/*배열의 최소값 구하는 프로그램*/
#include<stdio.h>
int main(void){
	int a[10];
	int i,min;
	//배열에 값 입력
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	//읽은 값 출력
	for(i=0;i<10;i++)
		printf("%d  ",a[i]);
	printf("\n");

	//최소값 출력
	min=a[0];
	for(i=1;i<10;i++){
		if(min>a[i])
			min=a[i];
	}

	printf("min = %d\n",min);
	return 0;
}
/*================================================================*/
/*최대값,최소값 동시에 구하기*/
#include<stdio.h>
int min,max;
void computeMinMax(int a,int b,int c){
	int i;
	min=a;
	max=a;

	if(min>b) min=b;
	if(max<b) max=b;
	if(min>c) min=c;
	if(max<c) min=c;
}
int main(){
	computeMinMax(9,4,1);
	printf("min=%d\n",min);
	printf("max=%d\n",max);
}
/*================================================================*/
/*배열 채우고 출력하는 함수들 p4.c*/
#include<stdio.h>
int a[10];
void fillArray(){
	int i,num=0;
	for(i=0;i<10;i++){
		a[i]=num;
		num++;
	}
}
void printArray(){
	int i;
	for(i=0;i<10;i++)
		printf("%d  ",a[i]);
}
int main(void){
	fillArray();
	printArray();
}
/*================================================================*/
/*배열에 저장되어있는 음수의 개수를 계산*/
#include<stdio.h>
int main(void){
	int a[10]={5,-3,7,3,-9,10,4,-2,-1,15};
	int i,count1=0,count2=0,sum1=0,sum2=0;
	for(i=0;i<10;i++){
		if(a[i]<0){
			count1++;
			sum1+=a[i];
		}
		else{
			count2++;
			sum2+=a[i];
		}
	}
	
	printf("음수의 개수 = %d\n",count1);
	printf("양수의 개수 = %d\n",count2);

	printf("음수의 합 = %d\n",sum1);
	printf("양수의 합 = %d\n",sum2);
	return 0;
}
/*================================================================*/
#include<stdio.h>
int main(void){
	int a[10]={5,-3,7,3,-9,10,4,-2,-1,15};
	int b[10]={1,2,3,4,5,6,7,8,9,10};
	int c[10]={0};
	int i;

	for(i=0;i<10;i++){
		c[i]=a[i]+b[i];
	}
	for(i=0;i<10;i++){
		printf("%d ",c[i]);
	}
	return 0;
}
/*================================================================*/
/*각 학생의 성적 평균 구하기*/
#include<stdio.h>
int main(void){
	int kor[]={50,60,40,60,70,75,65,90,85,100};
	int eng[]={100,60,70,40,80,60,40,75,35,80};
	int math[]={75,65,90,85,100,40,80,60,40,55};
	double average[10];
	int i,n;
	n=sizeof(kor)/sizeof(int);

	for(i=0;i<n;i++){
		average[i]=(kor[i]+eng[i]+math[i])/3.0;
		printf("Average of student[%d]=%.1f\n",i,average[i]);
	}

	printf("\n");
	return 0;
}