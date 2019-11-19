#include<stdio.h>
#define TAX 0.05 //세율을 매크로 상수로 고정시켰다
int main(void){
	//각 필요한 변수들을 선언하고, totalPrice와 maxCost,minCost,totalTax는 0으로 초기화한다.
	int buyCost,buyNum,totalPrice=0,tempCost;
	int maxCost,minCost; 
	double totalTax=0;
	printf("=======================================================\n");
	printf("\t물품 구입 금액 계산 프로그램\n");
	printf("-------------------------------------------------------\n");

	//초기의 물건의 금액과 개수를 입력 후 최대금액과 최소금액에 대입
	printf("구입하신 물건의 금액과 개수를 입력해 주십시오 : ");
	scanf("%d %d",&buyCost,&buyNum);
	totalPrice+=(buyCost*buyNum);
	maxCost=buyCost;
	minCost=buyCost;

	//물건의 금액과 개수 입력
	while(1){
		printf("구입하신 물건의 금액과 개수를 입력해 주십시오 : ");
		scanf("%d %d",&buyCost,&buyNum);
		totalPrice+=(buyCost*buyNum); //전체 금액 구한다
		if(buyCost==0&&buyNum==0) //구매 금액과 개수가 0이면 break
			break;
		if(minCost>buyCost)//만약 minCost가 buyCost보다 작으면
			minCost=buyCost; //buyCost를 minCost에 넣는다
		
		if(maxCost<buyCost) //만약 maxCost가 buyCost보다 작으면
			maxCost=buyCost; //buyCost는 maxCost가 된다.
	}

	//전체 금액에 TAX를 곱한 값과 전체 금액을 더하여 세금적용한 금액 구한다.
	totalTax=totalPrice*TAX+totalPrice; 

	//상품 구입 금액 계산 결과 출력
	printf("-------------------------------------------------------\n");
	printf("\t<결과>\t\n");
	printf("가장 가격이 낮은 물건의 금액 : %d원\n",minCost);
	printf("가장 가격이 높은 물건의 금액 : %d원\n",maxCost);
	printf("세금이 포함되지 않은 합계 금액 : %d원\n",totalPrice);
	printf("세금이 포함된 합계 금액 : %.2f원\n",totalTax);
	printf("=======================================================\n");
	printf("이용해 주셔서 감사합니다. 행복한 하루 되세요!\n");

	return 0;
}