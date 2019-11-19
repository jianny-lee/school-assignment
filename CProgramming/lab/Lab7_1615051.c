#include<stdio.h>
#define X 3
int main(void){
	int a=5,b=10;
	
	if(a>X && b>X)
		printf("a,b 모두 %d보다 큼\n");
	else if(a>X&&b<=X)
		printf("a는 %d보다 크고, b는 그렇지 않다.\n");
	else if(a<=X &&b>X)
		printf("b는 %d보다 크고, a는 그렇지 않다.\n");
	else
		printf("a와 b 모두 %d보다 크지 않다.\n");

	return 0;
}
/*================================================================*/
#include<stdio.h>
#define X 3
int main(void){
	int num;
	printf("Enter the number : ");
	scanf("%d",&num);

	if(num>=0)
		printf("절대값은 %d\n",num);
	else
		printf("절대값은 %d\n",-num);

	return 0;

}
/*================================================================*/
#include<stdio.h>
int main(void){
	int num1,num2,diff;
	printf("정수를 입력하세요 : ");
	scanf("%d",&num1);
	printf("정수를 입력하세요 : ");
	scanf("%d",&num2);
	
	diff=num2-num1;

	if(diff>0)
		printf("%d와 %d의 차이는 %d\n",num1,num2,diff);
	else
		printf("%d와 %d의 차이는 %d\n",num1,num2,-diff);


	return 0;
}
/*================================================================*/
#include<stdio.h>
int main(void){
	int what;
	printf("삼각형이면 3,사각형이면 4,원이면 0을 입력 : ");
	scanf("%d",&what);

	switch(what){
	case 3 :
		printf("삼각형 입니다.\n");
		break;
	case 4:
		printf("사각형 입니다.\n");
		break;
	case 0:
		printf("원입니다.\n");
		break;
	default :
		printf("잘못 입력하셨습니다.\n");
	}
	return 0;
}
/*================================================================*/
#include<stdio.h>
int main(void){
	char day;
	printf("요일을 입력하세요 <S,M,T,W,t,F,s> : ");
	scanf("%c",&day);

	switch(day){
	case 'S':
		printf("일요일입니다.\n");
		break;
	case 'M':
		printf("월요일입니다.\n");
		break;
	case 'T':
		printf("화요일입니다.\n");
		break;
	case 'W':
		printf("수요일입니다.\n");
		break;
	case 't':
		printf("목요일입니다.\n");
		break;
	case 'F':
		printf("금요일입니다.\n");
		break;
	case 's':
		printf("토요일입니다.\n");
		break;
	default :
		printf("잘못 입력하셨습니다.\n");
	}
	return 0;
}
/*================================================================*/
#include<stdio.h>
int main(void){
	int month;
	printf("Enter the month : ");
	scanf("%d",&month);

	switch(month){
	case 1:
		printf("January!\n");
		break;
	case 2:
		printf("Febuary!\n");
		break;
	case 3:
		printf("March!\n");
		break;
	case 4:
		printf("April!\n");
		break;
	case 5:
		printf("May!\n");
		break;
	case 6:
		printf("June!\n");
		break;
	case 7:
		printf("July!\n");
		break;
	case 8:
		printf("Agust!\n");
		break;
	case 9:
		printf("September!\n");
		break;
	case 10:
		printf("October!\n");
		break;
	case 11:
		printf("November!\n");
		break;
	case 12:
		printf("December!\n");
		break;
	default :
		printf("잘못 입력하셨습니다.\n");
	}
	return 0;
}
/*================================================================*/
#include<stdio.h>
int main(void){
	int month,temp;
	printf("Enter the month : ");
	scanf("%d",&month);
	temp=month%2;

	switch(temp){
	case 0:
		printf("짝수 달입니다!\n");
		break;
	case 1:
		printf("홀수 달입니다!\n");
		break;
	default :
		printf("잘못 입력하셨습니다.\n");
	}
	return 0;
}
/*================================================================*/
#include<stdio.h>
int main(void){
	double area;
	int height = 3,width = 9;
	area = 1/(float)2*height*width;
	printf("면적 = %.2f\n",area);

	return 0;
}
