/*실습1 다차원 배열에 데이터 저장하고 읽기*/
#include<stdio.h>
int main(void){
	int arr[2][3];
	int i,j;
	
	printf("배열 입력\n");
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			scanf("%d",&arr[i][j]);
		}
	}

	printf("배열 출력\n");
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
		printf("%2d ",arr[i][j]);
		}
		printf("\n");
	}
/*================================================================*/
/*실습2 문자열 비교하기*/
#include<stdio.h>
#include<string.h>
int main(void){
	char name1[20]="김이화";
	char name2[20]="박이화";
	char name3[20]="김이화";

	printf("%s\n",name1);
	printf("%d \n",strcmp(name1,name2));
	printf("%d \n",strcmp(name2,name3));
	printf("%d \n",strcmp(name1,name3));
	return 0;
}
/*================================================================*/
/*실습3 학생 명단 관리*/
#include<stdio.h>
#include<string.h>
int main(void){
	char student[7][10];
	int i,j;

	for(i=0;i<7;i++)
		scanf("%s",student[i]);
	printf("\n");
	for(i=0;i<7;i++)
		printf("%s\n",student[i]);
	
}
/*================================================================*/
/*실습4 학생 점수 출력하기*/
#include<stdio.h>
#include<string.h>
int main(void){
	char s[7][10]={"문예빈","우지수","최민경","박한아",
		"한해주","김보윤","손솔미"};
	int score[7]={90,85,80,75,95,100,80};
	char sname[10];
	int i,flag=0;
	printf("학생 이름을 입력하세요 : ");
	scanf("%s",sname);
	for(i=0;i<10;i++){
		if(strcmp(sname,s[i])==0){
			printf("그 학생의 점수 = %d\n",score[i]);
			flag=1;
			break;
		}
	}
	if(flag==0)
		printf("그 학생은 우리반 학생이 아닙니다.\n");

	return 0;
}
/*================================================================*/
/*실습5 삼각형 빗변 길이 계산*/
#include<stdio.h>
#include<math.h>
int main(void){
	double a,b,c,temp;
	int i;

	printf("삼각형의 밑변과 높이를 입력하세요 : ");
	scanf("%lf %lf",&a,&b);
	c=sqrt(a*a+b*b);

	printf("삼각형의 빗변은 %.2f 입니다.\n",c);
	return 0;
}
/*================================================================*/
/*실습6 피보나치 수열 계산 */
#include<stdio.h>
int main(void){
	int a=1,b=1,temp;
	int i;
	
	printf("%d %d ",a,b);

	for(i=3;i<=15;i++){
		temp=a+b;
		a=b;
		b=temp;
		printf("%d ",b);
	}
	return 0;
}