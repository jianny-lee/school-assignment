/*p1 - 3�� ��� ã��*/
#include<stdio.h>
int main(void){
	int num;
	printf("���� ������ �Է��ϼ��� : ");
	scanf("%d",&num);
	if(num%3==0)
		printf("�Է��Ͻ� ���� 3�� ����Դϴ�.\n");
	else
		printf("�Է��Ͻ� ���� 3�� ����� �ƴմϴ�.\n");

	return 0;

}
/*================================================================*/
/*p2 - ���� �������� �̿�*/
#include<stdio.h>
int main(void){
	int grade;
	printf("���� �Է� : ");
	scanf("%d", &grade);
	if(grade>=70&&grade<=80)
		printf("B�����Դϴ�.\n");
	else
		printf("B������ �ƴմϴ�.\n");

	return 0;
}
/*================================================================*/
/*p4 - ���� ���*/
#include<stdio.h>
int main(void){
	int year;
	printf("������ �Է��ϼ��� : ");
	scanf("%d",&year);

	if(year%400==0&&year%100!=0||year%400==0)
		printf("�� �ش� �����Դϴ�.\n");
	else
		printf("�� �ش� ������ �ƴմϴ�.\n");

}
/*================================================================*/
/*p5 - ���� ��� ���α׷�*/
#include<stdio.h>
int main(void){
	char day;
	printf("������ �Է��ϼ��� <S,M,T,W,t,F,s> : ");
	scanf("%c",&day);

	if(day=='S')
		printf("�Ͽ����Դϴ�.\n");
	else if(day=='M')
		printf("�������Դϴ�.\n");
	else if(day=='T')
		printf("ȭ�����Դϴ�.\n");
	else if(day=='W')
		printf("�������Դϴ�.\n");
	else if(day=='t')
		printf("������Դϴ�.\n");
	else if(day=='F')
		printf("�ݿ����Դϴ�.\n");
	else if(day=='s')
		printf("������Դϴ�.\n");
	else
		printf("�߸� �Է��ϼ̽��ϴ�.\n");

	return 0;
}
/*================================================================*/
/*p11-switch�� ��ȯ*/
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