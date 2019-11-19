/*p1-문자들의 출력*/
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
/*p2-영어 소문자의 위치 찾기*/
#include<stdio.h>
int main(void){
	char input,i;
	int num=1;
	printf("영어 소문자 입력 : ");
	scanf("%c",&input);

	for(i='a';i<input;i++){
		num++;
	}
	printf("입력하신 문자는 %d번째 영어 소문자 입니다.\n",num);
	
	return 0;
}
/*
	printf("입력하신 문자는 %d번째\n",input-ch+1);*/
/*================================================================*/
/*p3-별표 줄 출력 프로그램*/
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
/*p4-별표 줄 출력 프로그램2*/
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
/*p5-정사각형 모양 출력*/
#include<stdio.h>
int main(void){
	int i,j,n;
	printf("별표 줄의 개수를 입력하세요 : ");
	scanf("%d",&n);

	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("*");
		}
		printf("\n");
	}
}
/*================================================================*/
/*p5-1열씩 띄워 출력하기*/
#include<stdio.h>
int main(void){
	int i,j,n;
	printf("별표 줄의 개수를 입력하세요 : ");
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
/*p6-1행씩 띄워 출력하기*/
#include<stdio.h>
int main(void){
	int i,j,k,n;
	printf("별표 줄의 개수를 입력하세요 : ");
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
/*p7-격자무늬 출력*/
#include<stdio.h>
int main(void){
	int i,j,k,n;
	printf("별표 줄의 개수를 입력하세요 : ");
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
	printf("정사각형 변의 길이 : ");
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
	printf("삼각형의 높이 : ");
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
/*p8-역삼각형 출력 프로그램*/
#include<stdio.h>
int main(void){
	int n,i,j;
	printf("삼각형의 높이 : ");
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
/*p9-도형 출력 프로그램*/
#include<stdio.h>
int main(void){
	int n,i,j;
	printf("삼각형의 높이 : ");
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
/*평행사변형의 출력*/
#include<stdio.h>
int main(void){
	int n,i,j;
	printf("평행사변형의 높이 : ");
	scanf("%d",&n);

	for(i=1;i<=n;i++){
		//투명 삼각형 출력
		for(j=1;j<=i;j++)
			printf(" ");
		//사각형 출력
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
	printf("정수 두개 입력(행,열의 수) : ");
	scanf("%d %d",&x,&y);

	for(i=1;i<=x;i++){
		k=x-i+1;//투명삼각형의 한줄 길이
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