/* C프로그래밍 과제 #1 <1615051 이영은>*/
#include<stdio.h>

int main(void){

	int studentNo; //학번의 변수를 선언한다.
	int engGrade,matGrade,phyGrade; //각 과목 변수들을 선언한다.
	int sumGrade; //총점의 변수를 선언한다
	float average; //평균의 변수를 선언한다.
	printf("학번을 입력하세요 : ");
	scanf("%d",&studentNo); //학번을 입력한다.
	//영어,수학,물리의 성적을 각각 입력한다.
	printf("영어 점수를 입력하세요 : ");
	scanf("%d",&engGrade);
	printf("수학 점수를 입력하세요 : ");
	scanf("%d",&matGrade);
	printf("물리 점수를 입력하세요 : ");
	scanf("%d",&phyGrade);
	sumGrade=engGrade+matGrade+phyGrade; //3과목의 점수의 합을 변수 sumGrade에 대입한다.
	average=sumGrade/3; //3과목 점수의 합인 sumGrade를 과목의 수 만큼 나눈 값을 average에 대입한다.
	
	//총점과 평균을 출력한다.
	printf("====================================\n");
	printf("\t학번 : %d\n",studentNo); //해당 점수의 학생의 학번 출력한다.
	printf("------------------------------------\n");
	//영어,수학,물리의 점수를 각각 출력한다.
	printf("영어 : %d점 수학 : %d점 물리 : %d점\n\n",engGrade,matGrade,phyGrade);
	printf("=> 총점 : %d점 평균 : %.2f점\n",sumGrade,average);//총점과 평균을 소수 둘째자리까지만 출력한다.
	printf("====================================\n");

	return 0;
}