/*각 학생의 성적 평균 구하기 p1.c*/
#include<stdio.h>
int main(void){
	int kor[]={50,-1,40,60,70,75,65,-1,85,100};
	int e
ng[]={100,60,70,-1,80,60,40,-1,35,80};
	int math[]={75,-1,90,85,100,40,80,60,40,55};
	double average[10];
	int i;

	for(i=0;i<10;i++){
		if(kor[i]<0||eng[i]<0||math[i]<0)
			printf("학생[%d]는 시험을 치르지 않은 과목이 있습니다.\n",i);
		else{
			average[i]=(kor[i]+eng[i]+math[i])/3.0;
			printf("학생[%d]의 평균 = %.1f\n",i,average[i]);
		}
	}
	return 0;
}
/*================================================================*/
/*문자 배열의 글자 단위 출력*/
#include<stdio.h>
int main(void){
	char greetings[]="Good Morning";
	int i;
	
	for(i=0;i<sizeof(greetings);i++)
		printf("%c",greetings[i]);

	printf("\n");
	return 0;
}
/*================================================================*/
#include<stdio.h>
int main(void){
	char ch1='\0';
	char ch2='a';

	printf("문자형 = %c %c\n",ch1,ch2);
	printf("10진수 = %d %d\n\n",ch1,ch2);

	printf("8진수 = %o %o\n",ch1,ch2);
	printf("8진수 = %#o %#o\n\n",ch1,ch2);

	printf("16진수 = %x %x\n",ch1,ch2);
	printf("16진수 = %#x %#x\n",ch1,ch2);

	return 0;
}
/*================================================================*/
#include<stdio.h>
int main(void){
	char s[40]="*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=";
	int i,j;

	for(i=0;i<15;i++){
		for(j=0;j<=i;j++){
			printf("%c",s[j]);
		}
		printf("\n");
	}
	return 0;
}
/*================================================================*/
/*정렬하기*/
#include<stdio.h>
#define NewLine printf("\n")
int A[20];

//최대값을 맨 오른편으로 옮기는 함수
void Right(int n){
	int i,temp;
	for(i=0;i<n-1;i++){
		if(A[i]>A[i+1]){
			temp=A[i];
			A[i]=A[i+1];
			A[i+1]=temp;
		}
	}
}
void printA(){
	int i;
	for(i=0;i<20;i++){
		printf("%d ",A[i]);
	}
}

int main(void){
	int i;
	for(i=0;i<20;i++){
		A[i]=100-2*i;
	}
	for(i=20;i>0;i--){
		printA();NewLine;
		Right(i);
	}
	return 0;
}