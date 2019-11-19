#include<stdio.h>
#define NewLine printf("\n")
int A[20];

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
}
/*================================================================*/
#include<stdio.h>
#define NewLine printf("\n")
int A[20];

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
		Right(i);
		printA();NewLine;
	}
}
/*================================================================*/
#include<stdio.h>
int main(void){
	int arr[10];
	int i,max;
	
	for(i=0;i<10;i++){
		printf("입력 : ");
		scanf("%d",&arr[i]);
	}
	printf("배열 출력 : ");
	for(i=0;i<10;i++){
		printf("%d ",arr[i]);
	}
	max=arr[0];
	for(i=1;i<10;i++){
		if(max<arr[i])
			max=arr[i];
	}
	printf("\n최대값=%d\n",max);
}
/*================================================================*/
#include<stdio.h>
int arr[10];
void ReadNum(){
	int i;
	printf("정수를 입력하세요.\n>");
	for(i=0;i<10;i++)
		scanf("%d",&arr[i]);
}
void ComputeMin(){
	int i,min;
	min=arr[0];
	for(i=1;i<10;i++){
		if(min>arr[i])
			min=arr[i];
	}
	printf("Minimum = %d\n",min);
}
void ComputeMax(){
	int i,max;
	max=arr[0];
	for(i=1;i<10;i++){
		if(max<arr[i])
			max=arr[i];
	}
	printf("Maximum = %d\n",max);
}
void ComputeAvg(){
	int i,sum=0;
	double avg;
	for(i=0;i<10;i++){
		sum+=arr[i];
	}
	avg=sum/10.0;
	printf("Average = %.2f\n",avg);
}
int main(void){
	ReadNum();
	ComputeMin();
	ComputeMax();
	ComputeAvg();
}
/*================================================================*/
#include<stdio.h>
int arr[]={0};
int ReadNum(){
	int i,num;
	printf("숫자의 개수를 입력하세요 : ");
	scanf("%d",&num);
	printf("정수를 입력하세요.\n>");
	for(i=0;i<num;i++)
		scanf("%d",&arr[i]);
	return num;
}
void ComputeMin(int n){
	int i,min;
	min=arr[0];
	for(i=1;i<n;i++){
		if(min>arr[i])
			min=arr[i];
	}
	printf("Minimum = %d\n",min);
}
void ComputeMax(int n){
	int i,max;
	max=arr[0];
	for(i=1;i<n;i++){
		if(max<arr[i])
			max=arr[i];
	}
	printf("Maximum = %d\n",max);
}
void ComputeAvg(int n){
	int i,sum=0;
	double avg;
	for(i=0;i<n;i++){
		sum+=arr[i];
	}
	avg=sum/(float)n;
	printf("Average = %.2f\n",avg);
}
int main(void){
	int n;
	n=ReadNum();
	ComputeMin(n);
	ComputeMax(n);
	ComputeAvg(n);
}
/*================================================================*/
#include<stdio.h>
int arr[]={0},n;
void ReadNum(){
	int i;
	printf("숫자의 개수를 입력하세요 : ");
	scanf("%d",&n);
	printf("정수를 입력하세요.\n>");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
}
void ComputeMin(){
	int i,min;
	min=arr[0];
	for(i=1;i<n;i++){
		if(min>arr[i])
			min=arr[i];
	}
	printf("Minimum = %d\n",min);
}
void ComputeMax(){
	int i,max;
	max=arr[0];
	for(i=1;i<n;i++){
		if(max<arr[i])
			max=arr[i];
	}
	printf("Maximum = %d\n",max);
}
void ComputeAvg(){
	int i,sum=0;
	double avg;
	for(i=0;i<n;i++){
		sum+=arr[i];
	}
	avg=sum/(float)n;
	printf("Average = %.2f\n",avg);
}
int main(void){
	ReadNum();
	ComputeMin();
	ComputeMax();
	ComputeAvg();
}
/*================================================================*/
#include<stdio.h>
int arr[]={0},n;
void ReadNum(){
	int i;
	printf("숫자의 개수를 입력하세요 : ");
	scanf("%d",&n);
	printf("정수를 입력하세요.\n>");
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
}
int ComputeMin(){
	int i,min;
	min=arr[0];
	for(i=1;i<n;i++){
		if(min>arr[i])
			min=arr[i];
	}
	return min;
}
int ComputeMax(){
	int i,max;
	max=arr[0];
	for(i=1;i<n;i++){
		if(max<arr[i])
			max=arr[i];
	}
	return max;
}
int ComputeAvg(){
	int i,sum=0;
	double avg;
	for(i=0;i<n;i++){
		sum+=arr[i];
	}
	avg=sum/(float)n;
	return avg;
}
int main(void){
	int min,max;
	double avg;
	ReadNum();
	min=ComputeMin();
	max=ComputeMax();
	avg=ComputeAvg();
	printf("Minimum = %d\n",min);
	printf("Maximum = %d\n",max);
	printf("Average = %.2f\n",avg);
}
/*================================================================*/
#include<stdio.h>
int ComputeSum(int arr[],int n){
	int sum=0,i;
	for(i=0;i<n;i++){
		sum+=arr[i];
	}
	return sum;
}
int main(void){
	int arr[50]={0};
	int num,sum,i;
	printf("정수의 개수를 입력하세요 : ");
	scanf("%d",&num);
	printf("정수 %d개를 입력하세요.\n>",num);
	for(i=0;i<num;i++){
		scanf("%d",&arr[i]);
	}
	sum=ComputeSum(arr,num);
	printf("정수들의 합 = %d\n",sum);

	return 0;
}
/*================================================================*/
#include<stdio.h>
void AddOne(int *arr,int n){
	int i;
	for(i=0;i<n;i++){
		arr[i]++;
	}
}
int main(void){
	int i,num,arr[50]={0};
	printf("정수의 개수를 입력하세요 : ");
	scanf("%d",&num);
	printf("정수 %d개를 입력하세요.\n",num);
	for(i=0;i<num;i++){
		scanf("%d",&arr[i]);
	}
	AddOne(arr,num);
	for(i=0;i<num;i++)
		printf("%d ",arr[i]);

	return 0;
}
