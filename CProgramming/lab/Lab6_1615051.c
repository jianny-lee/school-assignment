/*p1-���ڵ��� ���*/
#include<stdio.h>
int main(void){
	char ch='a';
	int i;

	for(i=0;i<26;i++){
		printf("%c ",ch);
		ch++;
	}

	return 0;
}
/*================================================================*/
/*p2-���� �ҹ����� ��ġ ã��*/
#include<stdio.h>
int main(void){
	char input,i;
	int num=1;
	printf("���� �ҹ��� �Է� : ");
	scanf("%c",&input);

	for(i='a';i<input;i++){
		num++;
	}
	printf("�Է��Ͻ� ���ڴ� %d��° ���� �ҹ��� �Դϴ�.\n",num);
	
	return 0;
}
/*
	printf("�Է��Ͻ� ���ڴ� %d��°\n",input-ch+1);*/
/*================================================================*/
/*p3-��ǥ �� ��� ���α׷�*/
#include<stdio.h>
int main(void){
	int i,num;
	printf("Enter the number : ");
	scanf("%d",&num);

	for(i=1;i<=num;i++)
		printf("*");
	printf("\n");

	return 0;
}
/*================================================================*/
/*p4-��ǥ �� ��� ���α׷�2*/
#include<stdio.h>
int main(void){
	int i,j,m,n;
	printf("Enter the two number : ");
	scanf("%d %d",&m,&n);

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("*");
		}
		printf("\n");
	}

	return 0;
}
/*================================================================*/
/*p5-���簢�� ��� ���*/
#include<stdio.h>
int main(void){
	int i,j,n;
	printf("��ǥ ���� ������ �Է��ϼ��� : ");
	scanf("%d",&n);

	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("*");
		}
		printf("\n");
	}
}
/*================================================================*/
/*p5-1���� ��� ����ϱ�*/
#include<stdio.h>
int main(void){
	int i,j,n;
	printf("��ǥ ���� ������ �Է��ϼ��� : ");
	scanf("%d",&n);

	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(j%2==1)
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}
/*================================================================*/
/*p6-1�྿ ��� ����ϱ�*/
#include<stdio.h>
int main(void){
	int i,j,k,n;
	printf("��ǥ ���� ������ �Է��ϼ��� : ");
	scanf("%d",&n);

	for(i=1;i<=n;i++){
		if(i%2==1){
			for(j=1;j<=n;j++){
				printf("*");
			}
			printf("\n");
		}else{
			for(j=1;j<=n;j++){
				printf(" ");
			}
			printf("\n");
		}
	}
	return 0;
}
/*================================================================*/
/*p7-���ڹ��� ���*/
#include<stdio.h>
int main(void){
	int i,j,k,n;
	printf("��ǥ ���� ������ �Է��ϼ��� : ");
	scanf("%d",&n);

	for(i=1;i<=n;i++){
		if(i%2==1){
			for(j=1;j<=n;j++){
				if(j%2==1)
					printf("*");
				else
					printf(" ");
			}
			printf("\n");
		}else{
			for(j=1;j<=n;j++){
				if(j%2==1)
					printf(" ");
				else
					printf("*");
			}
			printf("\n");
		}
	}
	return 0;
}
/*================================================================*/
#include<stdio.h>
int main(void){
	int n=3,i,j;

	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%3d %3d\n",i,j);
		}
		printf("\n");
	}
	return 0;
}
/*================================================================*/
#include<stdio.h>
int main(void){
	int n=3,i,j;

	for(i=1;i<=n+1;i++){
		for(j=1;j<=n+1;j++){
			printf("%3d %3d\n",i,j);
		}
		printf("\n");
	}
	return 0;
}
/*================================================================*/
#include<stdio.h>
int main(void){
	int n=3,i,j;

	printf("  i   j\n");
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			printf("%3d %3d\n",i,j);
		}
		printf("\n");
	}
	return 0;
}
/*================================================================*/
#include<stdio.h>
int main(void){
	int n,i,j;
	printf("���簢�� ���� ���� : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
/*================================================================*/
#include<stdio.h>
int main(void){
	int n,i,j;
	printf("�ﰢ���� ���� : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
/*================================================================*/
/*p8-���ﰢ�� ��� ���α׷�*/
#include<stdio.h>
int main(void){
	int n,i,j;
	printf("�ﰢ���� ���� : ");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=i;j<=n;j++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
/*================================================================*/
/*p9-���� ��� ���α׷�*/
#include<stdio.h>
int main(void){
	int n,i,j;
	printf("�ﰢ���� ���� : ");
	scanf("%d",&n);

	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++){
			printf("*");
		}
		printf("\n");
	}
	for(i=1;i<n;i++){
		for(j=i;j<n;j++){
			printf("*");
		}
		printf("\n");
	}
	return 0;
}
/*================================================================*/
/*����纯���� ���*/
#include<stdio.h>
int main(void){
	int n,i,j;
	printf("����纯���� ���� : ");
	scanf("%d",&n);

	for(i=1;i<=n;i++){
		//���� �ﰢ�� ���
		for(j=1;j<=i;j++)
			printf(" ");
		//�簢�� ���
		for(j=1;j<=n;j++)
			printf("*");
		printf("\n");
	}
	return 0;
}
/*================================================================*/
#include<stdio.h>
int main(void){
	int x,y,i,j,k;
	printf("���� �ΰ� �Է�(��,���� ��) : ");
	scanf("%d %d",&x,&y);

	for(i=1;i<=x;i++){
		k=x-i+1;//����ﰢ���� ���� ����
		for(j=1;j<=x+y-i;j++){
			if(j<=k)
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}
	return 0;
}