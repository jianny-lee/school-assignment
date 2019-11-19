package hw2;

import java.util.*; //수를 입력하게 하는 것

public class TestScanner {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in); // 새로운 scan 객체를 만든다

		// 필요한 수 선언
		int count = 0;
		float totalNum = 0, avgNum, num;

		while (true) {
			try {
				System.out.print("Enter number : ");
				num = scan.nextFloat(); // 숫자를 입력

				if (num < 0) { // 만약 입력된 수가 음수이면, 프로그램은 종료.
					System.out.println("Negative number entered. Finish the program");
					avgNum = totalNum / count; // 평균 구하기
					System.out.println("Sum = " + totalNum); // 전체 입력된 수 출력
					System.out.println("Average = " + avgNum); // 입력된 수의 평균 출력
					scan.close(); // scanner 종료
					return; // 반복문 종료
				}
				count++; // 더해진 갯수 구하는 변수
				totalNum += num; // 숫자의 합
			} catch (InputMismatchException e) { // 문자가 들어오는 경우를 고려한 예외처리
				scan = new Scanner(System.in); // 다시 새로운 scanner 객체를 받는다.
				System.out.println("Invalid word, please enter the valid number.");
			}
		}
	}
}