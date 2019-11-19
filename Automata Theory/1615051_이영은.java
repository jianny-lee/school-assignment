//1615051 이영은
package automata;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Automata {
	public static int makeKey(int a, int b, int c) {
		return a * c + b;
	}

	public static void main(String[] args) {

		//HashMap인 ruleMap이라는 새로운 객체를 생성한다.
		HashMap<String, ArrayList<String>> ruleMap = new HashMap<String, ArrayList<String>>();
		System.out.println("Production Rule의 개수를 입력하시오.");
		
		Scanner scan = new Scanner(System.in);//scan이라는 Scanner의 새로운 객체를 생성한다.
		int size = scan.nextInt();//size에 정수를 입력받는다.

		scan.nextLine();//객체 scan의 문자열 전체를 입력받는다.

		System.out.println("Production Rule을 입력하시오.");
		for (int i = 0; i < size; i++) {//i가 입력한 정수에 도달할 때 까지
			String str = scan.nextLine();//string str에 문자열 전체를 입력한다.
			String[] strArr = str.split(">");//입력한 문자열에 ">"가 있으면 이것을 기준으로 split을 하여 분리한다.
			if (!ruleMap.containsKey(strArr[1])) {// rulemap의 strArr[1]에 key가
													// 있는지 value가 있는지 확인
				ArrayList<String> vars = new ArrayList<String>();//ArrayList로 vars의 객체를 생성
				vars.add(strArr[0]);// 왼쪽의 변수 더한다.
				ruleMap.put(strArr[1], vars);// ruleMap에 strArr[1](key),vars(value)를 넣는다.
			} else {
				ruleMap.get(strArr[1]).add(strArr[0]);
			}
		}

		//parseVarMap이라는또 다른  HashMap의 객체 생성
		HashMap<Integer, ArrayList<String>> parseVarMap = new HashMap<Integer, ArrayList<String>>();

		System.out.println("문자열 w를 입력하시오.");
		String w = scan.nextLine();//string w에 문자열 전체를 입력한다.
		for (int len = 1; len <= w.length(); len++) {
			for (int i = 1, j = len; j <= w.length(); i++, j++) {
				int newkey = i * w.length() + j;//parseVarMap에 넣을 새로운 key
				ArrayList<String> newVars = new ArrayList<String>();
				if (i == j) {
					String findkey = w.substring(i - 1, i);//심볼 추출
					ArrayList<String> ruleVar = ruleMap.get(findkey); //심볼이 갖고 있는 변수 찾기
					if (ruleVar != null && !ruleVar.isEmpty()) {
						for (String var : ruleVar) { //ruleVar의 배열에 있는 var의 끝까지
							newVars.add(var); //newVars의 객체에 var을 더한다
						}

					}
					parseVarMap.put(newkey, newVars); //newKey와 newVars를 hashMap인 parseVarMap에 넣는다
				} else {
					for (int k = i; k < j; k++) {
						Integer key1 = makeKey(i, k, w.length());
						Integer key2 = makeKey(k + 1, j, w.length());
						for (String var1 : parseVarMap.get(key1)) { //parseVarMap에서 지정한 key1에 해당하는 데이터를 var1으로 반환한다.
							for (String var2 : parseVarMap.get(key2)) {//parseVarMap에서 지정한 key2에 해당하는 데이터를 var2으로 반환한다.
								String findkey = var1 + var2; //반환된 var1과 var2를 더하여 findkey에 대입
								ArrayList<String> ruleVar = ruleMap.get(findkey); //findkey에 해당하는 데이터를 ArrayList에 반환한다.
								if (ruleVar != null && !ruleVar.isEmpty()) {
									for (String var : ruleVar) { //ruleVar의 배열에 있는 var의 끝까지
										if (!newVars.contains(var)) //만약 newVars에 var이 있지 않다면
											newVars.add(var); //var을 newVars에 넣는다.
									}
								}
							}
						}

					}
					parseVarMap.put(newkey, newVars); //newkey와 newVars로 구성된 새로운 데이터를 추가한다.
				}
			}
		}
		int lastkey = 1 * w.length() + w.length();

		System.out.print("결과 : ");
		if (parseVarMap.get(lastkey).contains("S")) {
			System.out.println("Accept");
		} else {
			System.out.println("Reject");
		}

	}
}
