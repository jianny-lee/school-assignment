/*최소값 구하기 -p1_1.c*/
#include<stdio.h>
int main(void){
	int a,b,c,i;
	int min;
	printf("Enter the number : ");
	scanf("%d %d %d",&a,&b,&c);

	min=a;

	if(min>b)
		min=b;
	if(min>c)
		min=c;

	printf("Minimum : %d\n",min);
	return 0;
}
/*================================================================*/
/*최소값 구하기 -p1_2.c*/
#include<stdio.h>
void Min(int a,int b,int c){
	int min;
	min=a;
	if(min>b)
		min=b;
	if(min>c)
		min=c;
	printf("Minimum : %d\n",min);

}
int main(void){
	int a,b,c;
	int min;
	printf("Enter the number : ");
	scanf("%d %d %d",&a,&b,&c);
	Min(a,b,c);
	return 0;
}
/*================================================================*/
/*최소값 구하기 -p1_3.c*/
#include<stdio.h>
int Min(int a,int b,int c){
	int min;
	min=a;
		if(min>b)
			min=b;
		if(min>c)
			min=c;
	return min;
}
int main(void){
	int a,b,c;
	int min;
	printf("Enter the number : ");
	scanf("%d %d %d",&a,&b,&c);

	min=Min(a,b,c);
	printf("Minimum : %d\n",min);
	return 0;
}
/*================================================================*/
/*a~b의 합 구하기 -p2_1.c*/
#include<stdio.h>
int main(void){
	int a,b,i;
	int sum=0;
	printf("Enter the number (a<b): ");
	scanf("%d %d",&a,&b);

	for(i=a;i<=b;i++){
		sum+=i;
	}
	printf("Sum : %d\n",sum);
	return 0;

}
/*================================================================*/
/*a~b의 합 구하기 -p2_2.c*/
#include<stdio.h>
void Sum(int a,int b){
	int sum,i;
	sum=0;
	for(i=a;i<=b;i++)
		sum+=i;
	printf("Sum : %d\n",sum);
}
int main(void){
	int a,b,i;
	int sum=0;
	printf("Enter the number (a<b): ");
	scanf("%d %d",&a,&b);

	Sum(a,b);

	return 0;

}
/*================================================================*/
/*a~b의 합 구하기 -p2_3.c*/
#include<stdio.h>
int Sum(int a,int b){
	int sum,i;
	sum=0;
	for(i=a;i<=b;i++)
		sum+=i;
	return sum;
}
int main(void){
	int a,b,i;
	int sum=0;
	printf("Enter the number (a<b): ");
	scanf("%d %d",&a,&b);

	sum=Sum(a,b);
	printf("Sum : %d\n",sum);
	return 0;

}
/*================================================================*/
/*피보나치 숫자 구하는 함수 -p3.c*/
#include<stdio.h>
int Fib(int n){
	int a=1,b=1,i,value;
	if(n==1||n==2)
		return 1;
	else {
		for(i=3;i<=n;i++){
			value=a+b;
			a=b;
			b=value;
		}
	}
	return value;
}
int main(void){
	int n=3;
	int result;
	result=Fib(n);
	//printf("%d! = %d\n",n,result);
	printf("%d번째 피보나치 수 = %d\n",n,Fib(n));
	return 0;
}
/*================================================================*/
/*함수를 호출하는 함수 -p4.c*/
#include<stdio.h>
int Fact(int x){
	int value =1;
	int i;
	for(i=2;i<=x;i++)
		value*=i;
	return value;
}
int Fib(int x){
	int a=1,b=1,i,value;
	if(x==1||x==2)
		return 1;
	else{
		for(i=3;i<=x;i++){
			value=a+b;
			a=b;
			b=value;
		}
	}
	return value;
}
int Mighty(int what,int x){
	if(what==1)
		return Fact(x);
	else if(what==2)
		return Fib(x);

}
int main(void){
	int what,x,result;
	printf("Enter the what and x : ");
	scanf("%d %d",&what,&x);
	if(what==1)
		printf("%d!=%d\n",x,Mighty(what,x));
	else if(what==2)
		printf("%d번째 피보나치 수 = %d\n",x,Mighty(what,x));
	
	return 0;

}
/*================================================================*/
/*프로그램 실행 결과? -p6.c*/
#include<stdio.h>
int count=5;
void PrintCount1(){
	printf("count=%d\n",count);
}
void PrintCount2(){
	int count=10;
	printf("count=%d\n",count);
}
int main(void){
	int count;
	count =3;
	printf("count=%d\n",count);
	PrintCount1();
	PrintCount2();
}
/*================================================================*/
/*전역변수의 사용 -p7.c*/
#include<stdio.h>
int num;
int f(int n){
	n=n+5;
	return n;
}
int main(void){
	num=10;
	printf("%d\n",num);
	printf("%d\n",f(num));
	printf("%d\n",num);
	return 0;
}
/*================================================================*/
/*배열 맛보기 -p8.c*/
#include<stdio.h>
int main(void){
	int arr[10]={0};
	int i;

	for(i=0;i<10;i++)
		arr[i]=i*10;

	for(i=0;i<10;i++)
		printf("%4d\t",arr[i]);
	
	printf("\n");

	return 0;
}