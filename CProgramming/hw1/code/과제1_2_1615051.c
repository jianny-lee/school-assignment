/* C���α׷��� ���� #1 <1615051 �̿���>*/
#include<stdio.h>

int main(void){
	const int basicRate = 3780; //������ �⺻���
	const int callRate = 20; //������ 1�д� ��ȭ ���
	const int msgRate = 5; //������ 1��� �޽��� ���
	//�Է��� ��ȭ�ð�(�� ����) ����(callTIme)�� ���� �޽��� ���� �Է� �� ����(msgSend)����
	int callTime,msgSend;
	int monthCharge; //�̹��� ����� ��Ÿ���� ���� ����
	printf("��ȭ �ð�(�� ����)�� �Է��ϼ��� : ");
	scanf("%d",&callTime); //��ȭ �ð�(�� ����)�� �Է�
	printf("�޽��� �۽� Ƚ���� �Է��ϼ��� : ");
	scanf("%d",&msgSend); //�޽��� �۽� Ƚ�� �Է�
	//�̹� �� ����� ���ϴ� ����
	monthCharge = basicRate + (callRate*callTime) + (msgRate*msgSend);

	//�̹� �� �޴��� ��� �ð�,�޽��� �۽� Ƚ���� �޴��� ��� ���
	printf("=============================================\n");
	printf("�̹� ���� ��ȭ �ð� : %d��\n",callTime); 
	printf("�޽��� �۽� Ƚ�� : %dȸ\n\n",msgSend);
	printf("�̹� �� ������ �޴��� ����� %d�� �Դϴ�.\n",monthCharge);
	printf("=============================================\n");

	return 0;
}