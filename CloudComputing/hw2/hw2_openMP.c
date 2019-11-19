#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define total 100000
#define Num 10

int sum[Num];
void oepnMP(void); /*Thread function*/

int main(int argc, char * argv[]){
	/*Get number of threads from command line*/
	int thread_count = strtol(argv[1], NULL, 10);
	int i;

/*added to a parallel directive*/
#pragma omp parallel num_threads(thread_count)
	openMP();
	
	
	/*print the number of student grade distribution*/
	for(i = 0;i<Num;i++){
		printf("%d ",sum[i]);
	}
	printf("\n");

	return 0;
} /*main*/

void openMP(void){

	FILE * fp = fopen("scores.txt","r");//open file
	long my_rank = omp_get_thread_num();
	long thread_count = omp_get_num_threads();
	long my_sum[Num];
	long i;
	long long my_n = total/thread_count;
	long long my_first_i = my_n * my_rank;
	long long my_last_i = my_first_i + my_n;
	int scoreNum[total];

	for(i = 0; i < total; i++)//input the value scoreNum
		fscanf(fp, "%d", &scoreNum[i]);	

	for(i = 0; i < Num; i++)
		my_sum[i]=0;

	for(i = my_first_i;i<my_last_i;i++){//calculate of student grade distribution
		
		if(scoreNum[i]>=0 && scoreNum[i]<=10)
			my_sum[0]++;

		else if(scoreNum[i]>10&&scoreNum[i]<=20)
			my_sum[1]++;

		else if(scoreNum[i]>20&&scoreNum[i]<=30)
			my_sum[2]++;

		else if(scoreNum[i]>30&&scoreNum[i]<=40)
			my_sum[3]++;

		else if(scoreNum[i]>40&&scoreNum[i]<=50)
			my_sum[4]++;
		
		else if(scoreNum[i]>50&&scoreNum[i]<=60)
			my_sum[5]++;

		else if(scoreNum[i]>60&&scoreNum[i]<=70)
			my_sum[6]++;

		else if(scoreNum[i]>70&&scoreNum[i]<=80)
			my_sum[7]++;

		else if(scoreNum[i]>80&&scoreNum[i]<=90)
			my_sum[8]++;

		else if(scoreNum[i]>90&&scoreNum[i]<=100)
			my_sum[9]++;
	}
	for(i = 0;i<Num;i++){/*insert the number of total student */
		sum[i]+=my_sum[i];
	}

	fclose(fp);//close the file

	return NULL;
}
