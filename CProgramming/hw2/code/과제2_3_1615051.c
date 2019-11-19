#include<stdio.h>
int main(void){
	char figure; //삼각형 또는 사각형의 문자 변수
	int triX1,triY1,triX2,triY2,triX3,triY3; //삼각형 꼭지점들의 변수
	int recX1,recX2,recY1,recY2; //사각형 두 꼭지점의 변수
	double area; //면적

	//도형 입력 
	printf("=======================================================\n");
	printf("\t>> 삼각형/사각형 도형을 출력해 드립니다 <<\n");
	printf("-------------------------------------------------------\n");
	printf("도형 (삼각형 또는 사각형)의 모양을 찾고, 면적을 계산해 드립니다.\n");
	printf("삼각형이면 t를 사각형이면 r을 입력하세요 : ");
	scanf("%c",&figure);
	
	//삼각형 또는 사각형에 따라 모양과 면적 출력
	switch(figure){
	case 't': //삼각형의 경우일 때
		printf("삼각형의 각 꼭지점 좌표를 입력하세요 : ");
		scanf("%d %d %d %d %d %d",&triX1,&triY1,&triX2,&triY2,&triX3,&triY3);
		printf("-------------------------------------------------------\n");
		printf("\t>> 실 행 결 과 <<\n");
		printf("-------------------------------------------------------\n");
		
		//만약 triX3과 triX1이 같거나 triX3과 triX2가 같으면 직각삼각형
		if(triX3==triX1||triX3==triX2)
			printf("입력하신 삼각형은 직각삼각형입니다.\n");
		
		area=(float)1/2*(triX2-triX1)*(triY3-triY1); //삼각형의 면적
		printf("삼각형의 면적은 \t%.2lf입니다.\n",area);
		break;

	case 'r' : //사각형의 경우일 때
		printf("사각형의 두 꼭지점 좌표를 입력하세요 : ");
		scanf("%d %d %d %d",&recX1,&recY1,&recX2,&recY2);
		printf("-------------------------------------------------------\n");
		printf("\t>> 실 행 결 과 <<\n");
		printf("-------------------------------------------------------\n");
		
		if((recX2-recX1)==(recY2-recY1)) //만약 x좌표의 차와 y좌표의 차가 같으면 정사각형
			printf("입력하신 사각형은 정사각형입니다.\n");
		else //아니면 직사각형
			printf("입력하신 사각형은 직사각형입니다.\n");
		
		area=(recX2-recX1)*(recY2-recY1); //사각형의 면적 구하기
		printf("사각형의 면적은 \t%.2lf입니다.\n",area);
		break;

	default : //t나 r의 입력이 아닐경우
		printf("잘못 입력하셨습니다.\n");
	}
	return 0;
}