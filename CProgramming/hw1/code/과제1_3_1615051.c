/* C���α׷��� ���� #1 <1615051 �̿���>*/
#include<stdio.h>

int main(void){
	//3���� ��ȹ�ȵ��� ������ �⺻���,��ȭ���(1�д�),�޽����۽ſ��(1���) ���� ����� �ʱ�ȭ
	const int basicRate1 = 2800, basicRate2 = 3780, basicRate3 = 4800;
	const int callRate1 = 23, callRate2 = 20, callRate3 = 18;
	const int msgRate1 = 6, msgRate2 = 5, msgRate3 = 3; 
	//�Է��� ��ȭ�ð�(�� ����) ����(callTIme)�� ���� �޽��� ���� �Է� �� ����(msgSend)����
	int callTime,msgSend;
	int monthCharge1, monthCharge2, monthCharge3; //�̹��� ����� ��Ÿ���� �� ��ȹ�ȵ��� ���� ����
	printf("��ȭ �ð�(�� ����)�� �Է��ϼ��� : ");
	scanf("%d",&callTime); //��ȭ �ð�(�� ����)�� �Է�
	printf("�޽��� �۽� Ƚ���� �Է��ϼ��� : ");
	scanf("%d",&msgSend); //�޽��� �۽� Ƚ�� �Է�
	//�� ��ȹ�ȵ��� �̹� �� ����� ���ϴ� ����
	monthCharge1 = basicRate1 + (callRate1*callTime) + (msgRate1*msgSend);
	monthCharge2 = basicRate2 + (callRate2*callTime) + (msgRate2*msgSend);
	monthCharge3 = basicRate3 + (callRate3*callTime) + (msgRate3*msgSend);

	//�̹� �� �޴��� ��� �ð�,�޽��� �۽� Ƚ���� �޴��� ��� ���
	printf("==============================================\n");
	printf("�̹� ���� ��ȭ �ð� : %d��\n",callTime); 
	printf("�޽��� �۽� Ƚ�� : %dȸ\n\n",msgSend);
	printf("1���� �̹� �� �޴��� ����� %d�� �Դϴ�.\n",monthCharge1);
	printf("2���� �̹� �� �޴��� ����� %d�� �Դϴ�.\n",monthCharge2);
	printf("3���� �̹� �� �޴��� ����� %d�� �Դϴ�.\n",monthCharge3);
	printf("==============================================\n");

	return 0;
}