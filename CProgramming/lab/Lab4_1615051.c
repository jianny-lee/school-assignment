#include<stdio.h>
int main(void){
	short num=32765;
	printf("%d\n",num); //32765
	num=num+1;
	printf("%d\n",num); //32766
	num=num+1;
	printf("%d\n",num); //32767
	num=num+1;
	printf("%d\n",num); //-32768
	num=num+1;
	printf("%d\n",num); //-32767

	return 0;
}
/*================================================================*/
/*p2-underflow*/
#include<stdio.h>
int main(void){
	short num=-32768;
	printf("%d\n",num); //-32768
	num=num-1;
	printf("%d\n",num); //32767
	num=num-1;
	printf("%d\n",num); //32766
	num=num-1;
	printf("%d\n",num); //32765
	num=num-1;
	printf("%d\n",num); //32764

	return 0;
}
/*================================================================*/
/*p3-음수의 저장방식*/
#include<stdio.h>
int main(void){
	int num=7;
	printf("%08x\n",num); //00000007
	num = -7;
	printf("%08x\n",num); //fffffff9

	return 0;
}
/*================================================================*/
/*p4 - 중단점을 사용한 디버깅*/
#include<stdio.h>
int main(void){
	int a=10,b=20,c=30,d=40;
	a=b;
	b=c+d;
	c=a-c;
	d=c+a;
	
}
/*================================================================*/
/*p5 - %(나머지)연산자 사용*/
#include<stdio.h>
int main(void){
	int money,one;
	printf("돈의 액수를 입력하시오: ");
	scanf("%d",&money);

	one=money%10;
	printf("1원 짜리는 %d 개 입니다.\n",one);

	return 0;
}
/*================================================================*/
/*p6 - /(나누기),%(나머지) 연산자 사용*/
#include<stdio.h>
int main(void){
	int money,temp,ten,one;
	printf("돈의 액수를 입력하시오(천원 미만): ");
	scanf("%d",&money);

	one=money%10;
	temp = money/10;
	ten=temp%10;
	temp=temp/10;

	printf("100원 짜리는 %d 개 입니다.\n",temp);
	printf("10원 짜리는 %d 개 입니다.\n",ten);
	printf("1원 짜리는 %d 개 입니다.\n",one);

	return 0;
}
/*================================================================*/
/*p7 - 증감연산자(++,--) 사용*/
#include<stdio.h>
int main(void){
	int n=10,m;
	n=n+1;
	n++;
	m=n;
	m=++n +3;
	m=n++ +3;
	m=--n +3;
	m=n-- +3;
	
	printf("m=%d,n=%d\n",m,n);
	printf("m=%d,n=%d\n",++m,n++);

	return 0;
}
/*================================================================*/
/*p8 - 관계연산자의 사용*/
#include<stdio.h>
int main(void){
	int a=10, b=50,c=0;
	c=a>b;
	printf("c=%d\n",c); //0

	printf("c=%d\n",a<b); //1

	return 0;
}
