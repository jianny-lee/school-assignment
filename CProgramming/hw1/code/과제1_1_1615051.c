/* C���α׷��� ���� #1 <1615051 �̿���>*/
#include<stdio.h>

int main(void){

	int studentNo; //�й��� ������ �����Ѵ�.
	int engGrade,matGrade,phyGrade; //�� ���� �������� �����Ѵ�.
	int sumGrade; //������ ������ �����Ѵ�
	float average; //����� ������ �����Ѵ�.
	printf("�й��� �Է��ϼ��� : ");
	scanf("%d",&studentNo); //�й��� �Է��Ѵ�.
	//����,����,������ ������ ���� �Է��Ѵ�.
	printf("���� ������ �Է��ϼ��� : ");
	scanf("%d",&engGrade);
	printf("���� ������ �Է��ϼ��� : ");
	scanf("%d",&matGrade);
	printf("���� ������ �Է��ϼ��� : ");
	scanf("%d",&phyGrade);
	sumGrade=engGrade+matGrade+phyGrade; //3������ ������ ���� ���� sumGrade�� �����Ѵ�.
	average=sumGrade/3; //3���� ������ ���� sumGrade�� ������ �� ��ŭ ���� ���� average�� �����Ѵ�.
	
	//������ ����� ����Ѵ�.
	printf("====================================\n");
	printf("\t�й� : %d\n",studentNo); //�ش� ������ �л��� �й� ����Ѵ�.
	printf("------------------------------------\n");
	//����,����,������ ������ ���� ����Ѵ�.
	printf("���� : %d�� ���� : %d�� ���� : %d��\n\n",engGrade,matGrade,phyGrade);
	printf("=> ���� : %d�� ��� : %.2f��\n",sumGrade,average);//������ ����� �Ҽ� ��°�ڸ������� ����Ѵ�.
	printf("====================================\n");

	return 0;
}