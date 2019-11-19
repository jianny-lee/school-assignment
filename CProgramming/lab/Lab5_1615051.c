/*p1 - 3의 배수 찾기*/
#include<stdio.h>
int main(void){
	int num;
	printf("양의 정수를 입력하세요 : ");
	scanf("%d",&num);
	if(num%3==0)
		printf("입력하신 수는 3의 배수입니다.\n");
	else
		printf("입력하신 수는 3의 배수가 아닙니다.\n");

	return 0;

}
/*================================================================*/
/*p2 - 관계 연산자의 이용*/
#include<stdio.h>
int main(void){
	int grade;
	printf("점수 입력 : ");
	scanf("%d", &grade);
	if(grade>=70&&grade<=80)
		printf("B학점입니다.\n");
	else
		printf("B학점이 아닙니다.\n");

	return 0;
}
/*================================================================*/
/*p4 - 윤년 계산*/
#include<stdio.h>
int main(void){
	int year;
	printf("연도를 입력하세요 : ");
	scanf("%d",&year);

	if(year%400==0&&year%100!=0||year%400==0)
		printf("그 해는 윤년입니다.\n");
	else
		printf("그 해는 윤년이 아닙니다.\n");

}
/*================================================================*/
/*p5 - 요일 출력 프로그램*/
#include<stdio.h>
int main(void){
	char day;
	printf("요일을 입력하세요 <S,M,T,W,t,F,s> : ");
	scanf("%c",&day);

	if(day=='S')
		printf("일요일입니다.\n");
	else if(day=='M')
		printf("월요일입니다.\n");
	else if(day=='T')
		printf("화요일입니다.\n");
	else if(day=='W')
		printf("수요일입니다.\n");
	else if(day=='t')
		printf("목요일입니다.\n");
	else if(day=='F')
		printf("금요일입니다.\n");
	else if(day=='s')
		printf("토요일입니다.\n");
	else
		printf("잘못 입력하셨습니다.\n");

	return 0;
}
/*================================================================*/
/*p11-switch로 변환*/
#include<stdio.h>
int main(void){
	//int x=3;
	int x;
	printf("Enter the number : ");
	scanf("%d",&x);

	switch(x){
	case 1:
		printf("one!\n");
		break;
	case 2:
		printf("two!\n");
		break;
	case 3:
		printf("three!\n");
		break;
	default:
		printf("no,no,no!\n");
	}

	return 0;
}