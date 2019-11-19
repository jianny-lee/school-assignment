/* C프로그래밍 과제 #1 <1615051 이영은>*/
#include<stdio.h>

int main(void){
	const int basicRate = 3780; //정해진 기본요금
	const int callRate = 20; //정해진 1분당 통화 요금
	const int msgRate = 5; //정해진 1통당 메시지 요금
	//입력할 통화시간(분 단위) 변수(callTIme)과 보낸 메시지 수를 입력 할 변수(msgSend)정의
	int callTime,msgSend;
	int monthCharge; //이번달 요금을 나타내는 변수 정의
	printf("통화 시간(분 단위)을 입력하세요 : ");
	scanf("%d",&callTime); //통화 시간(분 단위)을 입력
	printf("메시지 송신 횟수를 입력하세요 : ");
	scanf("%d",&msgSend); //메시지 송신 횟수 입력
	//이번 달 요금을 구하는 공식
	monthCharge = basicRate + (callRate*callTime) + (msgRate*msgSend);

	//이번 달 휴대폰 사용 시간,메시지 송신 횟수와 휴대폰 요금 출력
	printf("=============================================\n");
	printf("이번 달의 통화 시간 : %d분\n",callTime); 
	printf("메시지 송신 횟수 : %d회\n\n",msgSend);
	printf("이번 달 고객님의 휴대폰 요금은 %d원 입니다.\n",monthCharge);
	printf("=============================================\n");

	return 0;
}