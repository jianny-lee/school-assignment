#include<stdio.h>
int main(void)
{
	int num1,num2;

	num1=30;
	num2=50;

	printf("(1)안녕하세요?\n");
	printf("(2)저는 20살입니다.\n");
	printf("(3)저는 %d살 입니다.\n",num1);
	printf("(4)두 수의 합은 %d 입니다.\n",num1+num2);

	return 0;
}
/*================================================================*/
#include<stdio.h>
int main(void)
{
	int a,b;

	printf("입력해 주세요: ");
	scanf("%d",&a);
	printf("입력해 주세요: ");
	scanf("%d",&b);

	printf("%d %d %d\n",a,b,a+b);

	return 0;
}
/*================================================================*/
#include<stdio.h>
int main(void)
{
	int num1,num2,num3;
	printf("숫자를 입력하시오 :");
	scanf("%d",&num1);

	printf("숫자를 입력하시오 :");
	scanf("%d",&num2);

	num3=num1+num2;
	printf("입력하신 수는 %d, %d 이고, 그 합은 %d입니다.\n",num1,num2,num3);
	return 0;
}
/*================================================================*/
#include<stdio.h>
int main(void)
{
	float num1,num2,num3;
	printf("숫자(실수)를 입력하시오 :");
	scanf("%f",&num1);

	printf("숫자(실수)를 입력하시오 :");
	scanf("%f",&num2);

	num3=num1+num2;
	printf("입력하신 수는 %.1f, %.1f 이고, 그 합은 %.1f입니다.\n",num1,num2,num3);
	return 0;
}
/*================================================================*/
#include<stdio.h>
int main(void)
{
	int year,month,day;
	printf("오늘은 몇년입니까? ");
	scanf("%d",&year);

	printf("오늘은 무슨 달 입니까? ");
	scanf("%d",&month);

	printf("오늘은 며칠 입니까? ");
	scanf("%d",&day);

	printf("오늘은 %d년 %d월 %d일 입니다.\n",year,month,day);
	return 0;
}
/*================================================================*/
#include<stdio.h>
int main(void)
{
	float cnum,fnum;
	printf("섭씨 온도를 입력하시오 : ");
	scanf("%f",&cnum);

	fnum = 9.0/5.0*cnum+32.0;

	printf("화씨 온도는 %.1f 입니다.",fnum);
	return 0;
}
/*================================================================*/
#include<stdio.h>
int main(void)
{
	float cnum,fnum;
	printf("화씨 온도를 입력하시오 : ");
	scanf("%f",&fnum);

	cnum = (fnum-32.0)/1.8;

	printf("섭씨 온도는 %.1f 입니다.",cnum);
	return 0;
}