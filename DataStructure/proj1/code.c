#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_STACK_SIZE 100
typedef int element;//기존의 자료형에 int성질을 갖고있고 element라는 이름을 갖는 자료형을 만든다.
typedef struct{
	element stack[MAX_STACK_SIZE];//element 자료형에 stack이라는 배열을 선언한다.
	int top;
}StackType;//StackType이라고 타입 정의한다.

char str1[100]={0};//광역변수 배열인 str1을 초기화 시켜준다.
//스택 초기화 함수
void init(StackType *s)
{
	s->top=-1;
}

//공백 상태 검출 함수
int is_empty(StackType *s)
{
	return(s->top==-1);
}

//포화 상태 검출 함수
int is_full(StackType *s){
	return (s->top==(MAX_STACK_SIZE-1));
}

//삽입 함수
void push(StackType *s,element item){
	if(is_full(s)){
		fprintf(stderr,"스택 포화 에러\n");
		return;
	}else s->stack[++(s->top)]=item;
}

//삭제 함수
element pop(StackType *s){
	if(is_empty(s)){
		fprintf(stderr, "스택 공백 에러1\n");
		exit (1);
	} else return s->stack[(s->top)--];
}

//피크 함수
element peek(StackType *s){
	if(is_empty(s)){
		fprintf(stderr,"스택 공백 에러2\n");
		exit(1);
	}else return s->stack[s->top];
}

//연산자의 우선순위를 반환
int prec(char op)

{
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': case '%': return 2;
	case '^': return 3;
	}
	return -1;
}

//후위 표기 수식 계산 함수
element eval(char exp[]){
	int op1,op2,value,i=0;
	int len=strlen(exp);
	char ch;
	StackType s;
	init(&s);
	for(i=0;i<len;i++){
		ch=exp[i];
		if(ch!='+'&&ch!='-'&&ch!='*'&&ch!='/'&&ch!='%'&&ch!='^'){
			value=ch - '0'; //char에 '0'을 빼면 int값이 됨
			push(&s,value);
		}else{
			op2=pop(&s);
			op1=pop(&s);
			switch(ch){//ch가 어떤 기호이냐에 따라, 연산을 수행하고 스택에 저장
			case '+': push(&s,op1+op2); break;
			case '-': push(&s,op1-op2); break;
			case '*': push(&s,op1*op2); break;
			case '/': push(&s,op1/op2); break;
			case '%': push(&s,op1%op2); break;
			case '^': push(&s,pow(op1,op2)); break;
			}
		}
	}
	return pop(&s);                          
}

//중위 표기 수식을 후위 표기 수식으로 바꾸는 함수
void infix_to_postfix(char exp[]){
	int i=0,k=0;
	char ch,top_op;
	int len=strlen(exp);
	StackType s; //변수 s를 타입 정의한다.

	init(&s);//스택 초기화
	
	for(i=0; i<len; i++){
		ch=exp[i];//char인 ch를 배열로 받는다.
		switch(ch)/*ch의 연산자가 무엇인지에 따라 결정*/{
		case '+': case '-': case '*': case '/': case '%': case '^': 
			//스택에 있는 연산자의 우선순위가 더 크거나 같으면 출력
			while(!is_empty(&s)&&(prec(ch)<=prec(peek(&s)))){
				str1[k]=pop(&s);//배열 str1에 pop한 char를 저장
				printf("%c ",str1[k]);//배열 str1의 문자를 출력
				k++;
			}
			push(&s,ch);//타입 정의한 s에 문자 ch를 넣는다
			break;
		case '(':
			push(&s,ch);//타입 정의한 s에 문자 ch를 넣는다
			break;
		case ')':
			top_op=pop(&s);//타입 정의한 s에서 뺀 문자 ch를 변수 top_op에 넣는다
			while(top_op!='(')/*pop하여 top_op에 넣은 문자가 '('가 아니면 반복문을 실행*/{
				str1[k]=top_op;//pop하여 저장한 top_op 문자값을 str1 배열에 저장
				printf("%c ",str1[k]);//저장한 str1 배열을 출력
				top_op=pop(&s);//pop한 stacktype 값을 top_op에 저장
				k++;
			}
			break;
		default://만약 case에 부합하지 않는 것일때 사용(숫자일때)
			printf("%c ",ch);
			str1[k]=ch;//숫자를 배열 str1에 저장
			k++;
			break;
		}
	}

	//stacktype s가 비어있지 않으면 반복문이 계속 실행된다.
	while(!is_empty(&s)){
		str1[k]=pop(&s);//pop한 stacktype을 str1의 배열에 저장
		printf("%c ",str1[k]);
		k++;
	}
	str1[k]=NULL;//반복문을 실행 후 스택에 저장되어있는 수식을 초기화하는 역할을 한다.
}

void main(){
	FILE *fp=fopen("c:\\infix1.txt","r");//출력 스트림의 형성
	int result, value;
	char ch;
	if(fp==NULL)/*만약 출력하려는 파일이 지정한 위치에 존재하지 않으면*/{
		printf("이 파일은 존재하지 않습니다\n");
	}
	else{
		int n,i,j=0,k=0;
		char ch;
		char str[100]={0};//배열 str을 초기화한다.
		n=fgetc(fp)-'0';//지정한 파일 fp에서 fgetc하여 가져온 character에 '0'을 빼서 int값으로 만들어준다.
		
		for(i=0;i<n;i++){
		   fgetc(fp);//파일 fp에서 임의로 한개의 문자를 가져온다.
		   printf("infix notation = ");
		   j=0;
		   while((ch=fgetc(fp))!=';')/*가져온 문자가 ';'이 나올때 까지 반복문 사용*/{
						str[j++]=ch;//str배열에 fgetc하여 가져와서 ch에 선언한 문자 하나를 저장한다
					    printf("%c ",ch);//문자 ch를 출력
						str[j]=NULL;//j가 +1된 str의 배열을 NULL값으로 저장한다.
				}
		   printf(";\n");
		   printf("postfix notation = ");
		   infix_to_postfix(str);//함수 infix_to_postfix에 배열 str을 넣어서 출력한다.
		   printf(";\n");
		   result=eval(str1);//함수 eval에 배열 str1을 넣어서 출력한 int값을 result로 선언한다.
		   printf("value = %d\n",result);
		   printf("\n");
			}
		}
	
		fclose(fp);
		return;
}
