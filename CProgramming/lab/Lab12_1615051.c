/*�ǽ�1 ������ �迭�� ������ �����ϰ� �б�*/
#include<stdio.h>
int main(void){
	int arr[2][3];
	int i,j;
	
	printf("�迭 �Է�\n");
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			scanf("%d",&arr[i][j]);
		}
	}

	printf("�迭 ���\n");
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
		printf("%2d ",arr[i][j]);
		}
		printf("\n");
	}
/*================================================================*/
/*�ǽ�2 ���ڿ� ���ϱ�*/
#include<stdio.h>
#include<string.h>
int main(void){
	char name1[20]="����ȭ";
	char name2[20]="����ȭ";
	char name3[20]="����ȭ";

	printf("%s\n",name1);
	printf("%d \n",strcmp(name1,name2));
	printf("%d \n",strcmp(name2,name3));
	printf("%d \n",strcmp(name1,name3));
	return 0;
}
/*================================================================*/
/*�ǽ�3 �л� ��� ����*/
#include<stdio.h>
#include<string.h>
int main(void){
	char student[7][10];
	int i,j;

	for(i=0;i<7;i++)
		scanf("%s",student[i]);
	printf("\n");
	for(i=0;i<7;i++)
		printf("%s\n",student[i]);
	
}
/*================================================================*/
/*�ǽ�4 �л� ���� ����ϱ�*/
#include<stdio.h>
#include<string.h>
int main(void){
	char s[7][10]={"������","������","�ֹΰ�","���Ѿ�",
		"������","�躸��","�ռֹ�"};
	int score[7]={90,85,80,75,95,100,80};
	char sname[10];
	int i,flag=0;
	printf("�л� �̸��� �Է��ϼ��� : ");
	scanf("%s",sname);
	for(i=0;i<10;i++){
		if(strcmp(sname,s[i])==0){
			printf("�� �л��� ���� = %d\n",score[i]);
			flag=1;
			break;
		}
	}
	if(flag==0)
		printf("�� �л��� �츮�� �л��� �ƴմϴ�.\n");

	return 0;
}
/*================================================================*/
/*�ǽ�5 �ﰢ�� ���� ���� ���*/
#include<stdio.h>
#include<math.h>
int main(void){
	double a,b,c,temp;
	int i;

	printf("�ﰢ���� �غ��� ���̸� �Է��ϼ��� : ");
	scanf("%lf %lf",&a,&b);
	c=sqrt(a*a+b*b);

	printf("�ﰢ���� ������ %.2f �Դϴ�.\n",c);
	return 0;
}
/*================================================================*/
/*�ǽ�6 �Ǻ���ġ ���� ��� */
#include<stdio.h>
int main(void){
	int a=1,b=1,temp;
	int i;
	
	printf("%d %d ",a,b);

	for(i=3;i<=15;i++){
		temp=a+b;
		a=b;
		b=temp;
		printf("%d ",b);
	}
	return 0;
}