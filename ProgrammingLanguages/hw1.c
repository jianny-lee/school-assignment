#include<stdio.h>
#include<math.h> //pow를 사용하기 위해 선언

int main() {
	int number = pow(2, 30), total; //number과 total의 값을 선언
	float tmp;
	printf("number = %d\n", number); //2의 30승의 결과값
	total = number + 65537;
	printf("start value = %d\n", total); //total의 초기 값


	tmp = (float)total + 1.0;
	total = (int)tmp - 1;
	printf("finish value = %d\n", total); //total의 마지막 값

	return 0;
}