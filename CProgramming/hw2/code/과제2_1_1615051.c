#include<stdio.h>
#define MONTH 1 //�̹����� ��ũ�� ������ ����
//������ ���ڸ� return���� �����ϴ� �Լ�
char day_calc(int day){
	int day_temp;
	char day_result;
	if(day<=31&&day>0){ //���� �Է��� ���ڰ� 1�� 31 ������ �����϶�
		day_temp=day%7; //�Էµ� ��¥�� 7�� ������
		if(day_temp==0) //day_temp�� 0�϶� ���� 's'�� ����
			day_result = 's';
		else if(day_temp==1)//day_temp�� 1�϶� ���� 'M'�� ����
			day_result = 'M';
		else if(day_temp==2) //day_temp�� 2�϶� ���� 'T'�� ����
			day_result = 'T';
		else if(day_temp==3) //day_temp�� 3�϶� ���� 'W'�� ����
			day_result = 'W';
		else if(day_temp==4)//day_temp�� 4�϶� ���� 't'�� ����
			day_result = 't';
		else if(day_temp==5)//day_temp�� 5�϶� ���� 'F'�� ����
			day_result = 'F';
		else //day_temp�� 6�϶� ���� 'S'�� ����
			day_result = 'S';

		return day_result; //�Էµ� day_result�� ���
	}else //���� �Է��� ��¥�� 1�� 31 ������ ���ڰ� �ƴϸ�
		return 1; //1�� return
}
int main(void){
	int day,day_temp=0;
	char day_result;
	printf("=== 2018�� %d�� : ���� ��� ���α׷� ===\n\n",MONTH);
	//�̹����� 31�ϱ��� �־ 31�ϻ����� ���ڷ� ���� ��.
	printf("���� �Է��ϼ��� (1-31 ������ ����) : ");
	scanf("%d",&day);

	day_result=day_calc(day); //day_calc �Լ��� �̿��Ͽ� main�Լ������� day_result�� ���Ѵ�
	
	//�Էµ� day_result�� ���� switch���� ���
	switch(day_result){
	case 's':
		printf("�Է��Ͻ� ��¥�� %d�� %d�̰�, �Ͽ����Դϴ�!\n",MONTH,day);
		break;
	case 'M':
		printf("�Է��Ͻ� ��¥�� %d�� %d�̰�, �������Դϴ�!\n",MONTH,day);
		break;
	case 'T':
		printf("�Է��Ͻ� ��¥�� %d�� %d�̰�, ȭ�����Դϴ�!\n",MONTH,day);
		break;
	case 'W':
		printf("�Է��Ͻ� ��¥�� %d�� %d�̰�, �������Դϴ�!\n",MONTH,day);
		break;
	case 't':
		printf("�Է��Ͻ� ��¥�� %d�� %d�̰�, ������Դϴ�!\n",MONTH,day);
		break;
	case 'F':
		printf("�Է��Ͻ� ��¥�� %d�� %d�̰�, �ݿ����Դϴ�!\n",MONTH,day);
		break;
	case 'S':
		printf("�Է��Ͻ� ��¥�� %d�� %d�̰�, ������Դϴ�!\n",MONTH,day);
		break;
	default : //���� �ش�Ǵ� case�� ������ ����
		printf("�߸� �Է��ϼ̽��ϴ�.\n");
	}
	return 0;
}