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
/*p3-������ ������*/
#include<stdio.h>
int main(void){
	int num=7;
	printf("%08x\n",num); //00000007
	num = -7;
	printf("%08x\n",num); //fffffff9

	return 0;
}
/*================================================================*/
/*p4 - �ߴ����� ����� �����*/
#include<stdio.h>
int main(void){
	int a=10,b=20,c=30,d=40;
	a=b;
	b=c+d;
	c=a-c;
	d=c+a;
	
}
/*================================================================*/
/*p5 - %(������)������ ���*/
#include<stdio.h>
int main(void){
	int money,one;
	printf("���� �׼��� �Է��Ͻÿ�: ");
	scanf("%d",&money);

	one=money%10;
	printf("1�� ¥���� %d �� �Դϴ�.\n",one);

	return 0;
}
/*================================================================*/
/*p6 - /(������),%(������) ������ ���*/
#include<stdio.h>
int main(void){
	int money,temp,ten,one;
	printf("���� �׼��� �Է��Ͻÿ�(õ�� �̸�): ");
	scanf("%d",&money);

	one=money%10;
	temp = money/10;
	ten=temp%10;
	temp=temp/10;

	printf("100�� ¥���� %d �� �Դϴ�.\n",temp);
	printf("10�� ¥���� %d �� �Դϴ�.\n",ten);
	printf("1�� ¥���� %d �� �Դϴ�.\n",one);

	return 0;
}
/*================================================================*/
/*p7 - ����������(++,--) ���*/
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
/*p8 - ���迬������ ���*/
#include<stdio.h>
int main(void){
	int a=10, b=50,c=0;
	c=a>b;
	printf("c=%d\n",c); //0

	printf("c=%d\n",a<b); //1

	return 0;
}
