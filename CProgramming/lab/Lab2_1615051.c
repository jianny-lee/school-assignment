#include<stdio.h>
int main(void)
{
	int num1,num2;

	num1=30;
	num2=50;

	printf("(1)�ȳ��ϼ���?\n");
	printf("(2)���� 20���Դϴ�.\n");
	printf("(3)���� %d�� �Դϴ�.\n",num1);
	printf("(4)�� ���� ���� %d �Դϴ�.\n",num1+num2);

	return 0;
}
/*================================================================*/
#include<stdio.h>
int main(void)
{
	int a,b;

	printf("�Է��� �ּ���: ");
	scanf("%d",&a);
	printf("�Է��� �ּ���: ");
	scanf("%d",&b);

	printf("%d %d %d\n",a,b,a+b);

	return 0;
}
/*================================================================*/
#include<stdio.h>
int main(void)
{
	int num1,num2,num3;
	printf("���ڸ� �Է��Ͻÿ� :");
	scanf("%d",&num1);

	printf("���ڸ� �Է��Ͻÿ� :");
	scanf("%d",&num2);

	num3=num1+num2;
	printf("�Է��Ͻ� ���� %d, %d �̰�, �� ���� %d�Դϴ�.\n",num1,num2,num3);
	return 0;
}
/*================================================================*/
#include<stdio.h>
int main(void)
{
	float num1,num2,num3;
	printf("����(�Ǽ�)�� �Է��Ͻÿ� :");
	scanf("%f",&num1);

	printf("����(�Ǽ�)�� �Է��Ͻÿ� :");
	scanf("%f",&num2);

	num3=num1+num2;
	printf("�Է��Ͻ� ���� %.1f, %.1f �̰�, �� ���� %.1f�Դϴ�.\n",num1,num2,num3);
	return 0;
}
/*================================================================*/
#include<stdio.h>
int main(void)
{
	int year,month,day;
	printf("������ ����Դϱ�? ");
	scanf("%d",&year);

	printf("������ ���� �� �Դϱ�? ");
	scanf("%d",&month);

	printf("������ ��ĥ �Դϱ�? ");
	scanf("%d",&day);

	printf("������ %d�� %d�� %d�� �Դϴ�.\n",year,month,day);
	return 0;
}
/*================================================================*/
#include<stdio.h>
int main(void)
{
	float cnum,fnum;
	printf("���� �µ��� �Է��Ͻÿ� : ");
	scanf("%f",&cnum);

	fnum = 9.0/5.0*cnum+32.0;

	printf("ȭ�� �µ��� %.1f �Դϴ�.",fnum);
	return 0;
}
/*================================================================*/
#include<stdio.h>
int main(void)
{
	float cnum,fnum;
	printf("ȭ�� �µ��� �Է��Ͻÿ� : ");
	scanf("%f",&fnum);

	cnum = (fnum-32.0)/1.8;

	printf("���� �µ��� %.1f �Դϴ�.",cnum);
	return 0;
}