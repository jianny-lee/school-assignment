/* C프로그래밍 과제 #1 <1615051 이영은>*/
#include<stdio.h>

int main(void){
	//3개의 계획안들의 각각의 기본요금,통화요금(1분당),메시지송신요금(1통당) 변수 선언과 초기화
	const int basicRate1 = 2800, basicRate2 = 3780, basicRate3 = 4800;
	const int callRate1 = 23, callRate2 = 20, callRate3 = 18;
	const int msgRate1 = 6, msgRate2 = 5, msgRate3 = 3; 
	//입력할 통화시간(분 단위) 변수(callTIme)과 보낸 메시지 수를 입력 할 변수(msgSend)정의
	int callTime,msgSend;
	int monthCharge1, monthCharge2, monthCharge3; //이번달 요금을 나타내는 각 계획안들의 변수 정의
	printf("통화 시간(분 단위)을 입력하세요 : ");
	scanf("%d",&callTime); //통화 시간(분 단위)을 입력
	printf("메시지 송신 횟수를 입력하세요 : ");
	scanf("%d",&msgSend); //메시지 송신 횟수 입력
	//각 계획안들의 이번 달 요금을 구하는 공식
	monthCharge1 = basicRate1 + (callRate1*callTime) + (msgRate1*msgSend);
	monthCharge2 = basicRate2 + (callRate2*callTime) + (msgRate2*msgSend);
	monthCharge3 = basicRate3 + (callRate3*callTime) + (msgRate3*msgSend);

	//이번 달 휴대폰 사용 시간,메시지 송신 횟수와 휴대폰 요금 출력
	printf("==============================================\n");
	printf("이번 달의 통화 시간 : %d분\n",callTime); 
	printf("메시지 송신 횟수 : %d회\n\n",msgSend);
	printf("1안의 이번 달 휴대폰 요금은 %d원 입니다.\n",monthCharge1);
	printf("2안의 이번 달 휴대폰 요금은 %d원 입니다.\n",monthCharge2);
	printf("3안의 이번 달 휴대폰 요금은 %d원 입니다.\n",monthCharge3);
	printf("==============================================\n");

	return 0;
}