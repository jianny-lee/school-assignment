package hw3;

import java.io.IOException;
import java.util.*;
import java.lang.*;

import org.apache.hadoop.fs.Path;
import org.apache.hadoop.conf.*;
import org.apache.hadoop.io.*;
import org.apache.hadoop.mapreduce.*;
import org.apache.hadoop.mapreduce.Mapper;
import org.apache.hadoop.mapreduce.Reducer;
import org.apache.hadoop.mapreduce.Mapper.Context;
import org.apache.hadoop.mapreduce.lib.input.*;
import org.apache.hadoop.mapreduce.lib.output.*;

public class socialGraph {
	public static class MyMapper extends Mapper<LongWritable, Text, Text, Text> { //mapper class 지정
		private static Text one = new Text(); // Text type의 전역변수로 one과 word 지정
		private Text word = new Text();

		public void map(LongWritable key, Text value, Context context) throws IOException, InterruptedException {
			String line = value.toString(); //입력되어지는 value의 한줄을 받아옴
			StringTokenizer tokenizer = new StringTokenizer(line, "\t"); //tap 단위로 끊어낸다

			word.set(tokenizer.nextToken()); //reduce에서 key 역할을 할 word 지정

			while(tokenizer.hasMoreTokens()) { //tokenizer가 끝날 때 까지 진행
				one.set(tokenizer.nextToken()); //다음 token을 one에 지정
				if(word.compareTo(one) > 0) { // 만약 word가 더 크면 word는 value로, one은 key로 서로 위치가 바뀌어 진행됨
					context.write(one, word);
				}else {
					context.write(word, one);
				}
			}
		}


	}

	public static class MyReducer extends Reducer <Text, Text, Text, Text> { //reduce 지정
		private final static Text one = new Text(); //Text type의 전역변수로 one과 word 지정
		private Text word = new Text();

		public void reduce(Text key, Iterable<Text> value, Context context) throws IOException, InterruptedException {
			//Arraylist인 myArray와 otherArr을 선언
			ArrayList<String> myArray = new ArrayList<String>();
			ArrayList<String> otherArr = new ArrayList<String>();
			Iterator<Text> itr = value.iterator(); //순서를 정할때 사용 될 itr 지정
			String testA,testB = new String(); //string type 변수 선언

			while(itr.hasNext()) { //itr에 들어가 있는 값이 끝날 때 까지
				myArray.add(itr.next().toString()); //myArray에 data를 넣는다
			}

			for(int i = 0; i < myArray.size();++i) {
				testA = myArray.get(i).toString(); //myArray의 값들을 하나씩 testA에 지정
				otherArr.add(testA); //otherArr에 testA를 추가
				for(int j = i+1; j < myArray.size(); j++) {
					testB = myArray.get(j).toString(); //testA에 myArray의 값들을 지정
					if(testA.equals(testB)) { //만약 testA와 testB가 같다면
						myArray.remove(j); //ArrayList인 myArray내에 있는 index의 data 삭제
						break; //반복문 나옴
					} else {
						if(one.equals(testA)) { //만약 one과 testA가 같다면
							break; //반복문 나옴
						}

					}

				}
			}

			for(int i = 0;i<otherArr.size();i++) {
				one.set(otherArr.get(i).toString()); //one에 otherArr의 data를 index에 맞춰 삽입
				context.write(key, one); //framework에 보냄
			}
		}
	}


	public static void main(String[] args) throws Exception {
		Configuration conf = new Configuration();

			Job job = new Job(conf,"socialGraph");
			job.setJarByClass(socialGraph.class); //map과 reduce가 있는 클래스 지정
			job.setMapperClass(MyMapper.class); //Mapper 지정
			job.setReducerClass(MyReducer.class); //Reducer 지정

			job.setMapOutputKeyClass(Text.class); //map의 output key와 value type 지정
			job.setMapOutputValueClass(Text.class);
			job.setOutputKeyClass(Text.class); //output의 key와 value type 지정
			job.setOutputValueClass(Text.class);

			//input과 output의 format 지정
			job.setInputFormatClass(KeyValueTextInputFormat.class);
			job.setInputFormatClass(TextInputFormat.class);
			job.setOutputFormatClass(TextOutputFormat.class);

			//input, output 되어지는 파일의 경로 지정
			FileInputFormat.addInputPath(job, new Path(args[0]));
			FileOutputFormat.setOutputPath(job, new Path(args[1]));
			job.waitForCompletion(true);

	}
}
