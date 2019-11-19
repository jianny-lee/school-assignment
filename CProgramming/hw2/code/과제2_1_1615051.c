#include<stdio.h>
#define MONTH 1 //이번달을 매크로 변수로 설정
//요일의 문자를 return값에 저장하는 함수
char day_calc(int day){
	int day_temp;
	char day_result;
	if(day<=31&&day>0){ //만약 입력한 숫자가 1과 31 사이의 숫자일때
		day_temp=day%7; //입력된 날짜를 7로 나눈다
		if(day_temp==0) //day_temp가 0일때 문자 's'를 저장
			day_result = 's';
		else if(day_temp==1)//day_temp가 1일때 문자 'M'를 저장
			day_result = 'M';
		else if(day_temp==2) //day_temp가 2일때 문자 'T'를 저장
			day_result = 'T';
		else if(day_temp==3) //day_temp가 3일때 문자 'W'를 저장
			day_result = 'W';
		else if(day_temp==4)//day_temp가 4일때 문자 't'를 저장
			day_result = 't';
		else if(day_temp==5)//day_temp가 5일때 문자 'F'를 저장
			day_result = 'F';
		else //day_temp가 6일때 문자 'S'를 저장
			day_result = 'S';

		return day_result; //입력된 day_result를 출력
	}else //만약 입력한 날짜가 1과 31 사이의 숫자가 아니면
		return 1; //1을 return
}
int main(void){
	int day,day_temp=0;
	char day_result;
	printf("=== 2018년 %d월 : 요일 계산 프로그램 ===\n\n",MONTH);
	//이번달이 31일까지 있어서 31일사이의 숫자로 설정 함.
	printf("일을 입력하세요 (1-31 사이의 숫자) : ");
	scanf("%d",&day);

	day_result=day_calc(day); //day_calc 함수를 이용하여 main함수에서의 day_result를 구한다
	
	//입력된 day_result에 따른 switch문을 사용
	switch(day_result){
	case 's':
		printf("입력하신 날짜는 %d월 %d이고, 일요일입니다!\n",MONTH,day);
		break;
	case 'M':
		printf("입력하신 날짜는 %d월 %d이고, 월요일입니다!\n",MONTH,day);
		break;
	case 'T':
		printf("입력하신 날짜는 %d월 %d이고, 화요일입니다!\n",MONTH,day);
		break;
	case 'W':
		printf("입력하신 날짜는 %d월 %d이고, 수요일입니다!\n",MONTH,day);
		break;
	case 't':
		printf("입력하신 날짜는 %d월 %d이고, 목요일입니다!\n",MONTH,day);
		break;
	case 'F':
		printf("입력하신 날짜는 %d월 %d이고, 금요일입니다!\n",MONTH,day);
		break;
	case 'S':
		printf("입력하신 날짜는 %d월 %d이고, 토요일입니다!\n",MONTH,day);
		break;
	default : //만약 해당되는 case가 없으면 실행
		printf("잘못 입력하셨습니다.\n");
	}
	return 0;
}