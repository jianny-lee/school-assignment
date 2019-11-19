#include<stdio.h>
int main(void){
	int num,i=1;
	printf("========================================\n");
	printf("\t소수 판별 프로그램\n");
	printf("========================================\n");
	printf("\n");
	printf("숫자를 입력하세요 : ");
	scanf("%d",&num); //숫자를 입력하여 어떤 수까지 소수를 판별할지 결정한다
	printf("\n");

	printf("%d과 %d 사이의 소수는\n",i,num);
	//입력한 수까지 소수를 판별하여 출력하는 반복문
	for(i=1;i<=num;i++){
		if(i==2||i==3) //만약 2와 3이면 출력
			printf("%d ",i);
		if(i!=1){ //만약 1이 아니면
			if(i%2!=0&&i%3!=0&&i%5!=0&&i%7!=0) //i를 나눈 나머지가 0이 아닐때 출력
				printf("%d ",i);
		}
	}
	printf("입니다.\n");

	return 0;
}