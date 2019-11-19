#include<stdio.h>
int main(void){
	FILE *fp;
	int i,num;
	fp=fopen("inputfile.txt","r");
	for(i=0;i<5;i++){
		fscanf(fp,"%d",&num);
		printf("%d ",num);
	}
}
/*================================================================*/
#include<stdio.h>
int main(void){
	FILE *fp;
	int a,b;
	fp=fopen("inputfile.txt","r");
	while(fscanf(fp,"%d %d",&a,&b)==2){
		printf("%d %d\n",a,b);
	}
}
/*================================================================*/
#include<stdio.h>
int main(void){
	FILE *fp;
	int i,num;
	fp=fopen("C://Temp/inputfile.txt","r");
	for(i=0;i<5;i++){
		fscanf(fp,"%d",&num);
		printf("%d ",num);
	}
}
/*================================================================*/
#include<stdio.h>
int main(void){
	FILE *fp;
	int a,b,c;
	fp=fopen("inputfile.txt","r");
	while(fscanf(fp,"%d %d %d",&a,&b,&c)==3){
		printf("입력 값 : %d %d %d",a,b,c);
		printf(" 합산 : %d\n",a+b+c);
	}


	return 0;

}
/*================================================================*/
#include<stdio.h>
int main(void){
	FILE *fp1,*fp2;
	int a,b,c,i;
	fp1=fopen("inputfile.txt","r");
	fp2=fopen("outputfile.txt","w");
	for(i=0;i<5;i++){
		fscanf(fp1,"%d %d %d",&a,&b,&c);
		fprintf(fp2,"입력 값 : %d %d %d",a,b,c);
		fprintf(fp2," 합산 : %d\n",a+b+c);
	}
	fclose(fp1);
	fclose(fp2);

	return 0;

}