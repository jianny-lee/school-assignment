#include<stdio.h>
#define TAX 0.05 //������ ��ũ�� ����� �������״�
int main(void){
	//�� �ʿ��� �������� �����ϰ�, totalPrice�� maxCost,minCost,totalTax�� 0���� �ʱ�ȭ�Ѵ�.
	int buyCost,buyNum,totalPrice=0,tempCost;
	int maxCost,minCost; 
	double totalTax=0;
	printf("=======================================================\n");
	printf("\t��ǰ ���� �ݾ� ��� ���α׷�\n");
	printf("-------------------------------------------------------\n");

	//�ʱ��� ������ �ݾװ� ������ �Է� �� �ִ�ݾװ� �ּұݾ׿� ����
	printf("�����Ͻ� ������ �ݾװ� ������ �Է��� �ֽʽÿ� : ");
	scanf("%d %d",&buyCost,&buyNum);
	totalPrice+=(buyCost*buyNum);
	maxCost=buyCost;
	minCost=buyCost;

	//������ �ݾװ� ���� �Է�
	while(1){
		printf("�����Ͻ� ������ �ݾװ� ������ �Է��� �ֽʽÿ� : ");
		scanf("%d %d",&buyCost,&buyNum);
		totalPrice+=(buyCost*buyNum); //��ü �ݾ� ���Ѵ�
		if(buyCost==0&&buyNum==0) //���� �ݾװ� ������ 0�̸� break
			break;
		if(minCost>buyCost)//���� minCost�� buyCost���� ������
			minCost=buyCost; //buyCost�� minCost�� �ִ´�
		
		if(maxCost<buyCost) //���� maxCost�� buyCost���� ������
			maxCost=buyCost; //buyCost�� maxCost�� �ȴ�.
	}

	//��ü �ݾ׿� TAX�� ���� ���� ��ü �ݾ��� ���Ͽ� ���������� �ݾ� ���Ѵ�.
	totalTax=totalPrice*TAX+totalPrice; 

	//��ǰ ���� �ݾ� ��� ��� ���
	printf("-------------------------------------------------------\n");
	printf("\t<���>\t\n");
	printf("���� ������ ���� ������ �ݾ� : %d��\n",minCost);
	printf("���� ������ ���� ������ �ݾ� : %d��\n",maxCost);
	printf("������ ���Ե��� ���� �հ� �ݾ� : %d��\n",totalPrice);
	printf("������ ���Ե� �հ� �ݾ� : %.2f��\n",totalTax);
	printf("=======================================================\n");
	printf("�̿��� �ּż� �����մϴ�. �ູ�� �Ϸ� �Ǽ���!\n");

	return 0;
}