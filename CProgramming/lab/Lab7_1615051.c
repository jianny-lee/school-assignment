#include<stdio.h>
#define X 3
int main(void){
	int a=5,b=10;
	
	if(a>X && b>X)
		printf("a,b ��� %d���� ŭ\n");
	else if(a>X&&b<=X)
		printf("a�� %d���� ũ��, b�� �׷��� �ʴ�.\n");
	else if(a<=X &&b>X)
		printf("b�� %d���� ũ��, a�� �׷��� �ʴ�.\n");
	else
		printf("a�� b ��� %d���� ũ�� �ʴ�.\n");

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
		printf("���밪�� %d\n",num);
	else
		printf("���밪�� %d\n",-num);

	return 0;

}
/*================================================================*/
#include<stdio.h>
int main(void){
	int num1,num2,diff;
	printf("������ �Է��ϼ��� : ");
	scanf("%d",&num1);
	printf("������ �Է��ϼ��� : ");
	scanf("%d",&num2);
	
	diff=num2-num1;

	if(diff>0)
		printf("%d�� %d�� ���̴� %d\n",num1,num2,diff);
	else
		printf("%d�� %d�� ���̴� %d\n",num1,num2,-diff);


	return 0;
}
/*================================================================*/
#include<stdio.h>
int main(void){
	int what;
	printf("�ﰢ���̸� 3,�簢���̸� 4,���̸� 0�� �Է� : ");
	scanf("%d",&what);

	switch(what){
	case 3 :
		printf("�ﰢ�� �Դϴ�.\n");
		break;
	case 4:
		printf("�簢�� �Դϴ�.\n");
		break;
	case 0:
		printf("���Դϴ�.\n");
		break;
	default :
		printf("�߸� �Է��ϼ̽��ϴ�.\n");
	}
	return 0;
}
/*================================================================*/
#include<stdio.h>
int main(void){
	char day;
	printf("������ �Է��ϼ��� <S,M,T,W,t,F,s> : ");
	scanf("%c",&day);

	switch(day){
	case 'S':
		printf("�Ͽ����Դϴ�.\n");
		break;
	case 'M':
		printf("�������Դϴ�.\n");
		break;
	case 'T':
		printf("ȭ�����Դϴ�.\n");
		break;
	case 'W':
		printf("�������Դϴ�.\n");
		break;
	case 't':
		printf("������Դϴ�.\n");
		break;
	case 'F':
		printf("�ݿ����Դϴ�.\n");
		break;
	case 's':
		printf("������Դϴ�.\n");
		break;
	default :
		printf("�߸� �Է��ϼ̽��ϴ�.\n");
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
		printf("�߸� �Է��ϼ̽��ϴ�.\n");
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
		printf("¦�� ���Դϴ�!\n");
		break;
	case 1:
		printf("Ȧ�� ���Դϴ�!\n");
		break;
	default :
		printf("�߸� �Է��ϼ̽��ϴ�.\n");
	}
	return 0;
}
/*================================================================*/
#include<stdio.h>
int main(void){
	double area;
	int height = 3,width = 9;
	area = 1/(float)2*height*width;
	printf("���� = %.2f\n",area);

	return 0;
}
