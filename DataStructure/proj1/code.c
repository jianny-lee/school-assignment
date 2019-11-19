#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_STACK_SIZE 100
typedef int element;//������ �ڷ����� int������ �����ְ� element��� �̸��� ���� �ڷ����� �����.
typedef struct{
	element stack[MAX_STACK_SIZE];//element �ڷ����� stack�̶�� �迭�� �����Ѵ�.
	int top;
}StackType;//StackType�̶�� Ÿ�� �����Ѵ�.

char str1[100]={0};//�������� �迭�� str1�� �ʱ�ȭ �����ش�.
//���� �ʱ�ȭ �Լ�
void init(StackType *s)
{
	s->top=-1;
}

//���� ���� ���� �Լ�
int is_empty(StackType *s)
{
	return(s->top==-1);
}

//��ȭ ���� ���� �Լ�
int is_full(StackType *s){
	return (s->top==(MAX_STACK_SIZE-1));
}

//���� �Լ�
void push(StackType *s,element item){
	if(is_full(s)){
		fprintf(stderr,"���� ��ȭ ����\n");
		return;
	}else s->stack[++(s->top)]=item;
}

//���� �Լ�
element pop(StackType *s){
	if(is_empty(s)){
		fprintf(stderr, "���� ���� ����1\n");
		exit (1);
	} else return s->stack[(s->top)--];
}

//��ũ �Լ�
element peek(StackType *s){
	if(is_empty(s)){
		fprintf(stderr,"���� ���� ����2\n");
		exit(1);
	}else return s->stack[s->top];
}

//�������� �켱������ ��ȯ
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

//���� ǥ�� ���� ��� �Լ�
element eval(char exp[]){
	int op1,op2,value,i=0;
	int len=strlen(exp);
	char ch;
	StackType s;
	init(&s);
	for(i=0;i<len;i++){
		ch=exp[i];
		if(ch!='+'&&ch!='-'&&ch!='*'&&ch!='/'&&ch!='%'&&ch!='^'){
			value=ch - '0'; //char�� '0'�� ���� int���� ��
			push(&s,value);
		}else{
			op2=pop(&s);
			op1=pop(&s);
			switch(ch){//ch�� � ��ȣ�̳Ŀ� ����, ������ �����ϰ� ���ÿ� ����
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

//���� ǥ�� ������ ���� ǥ�� �������� �ٲٴ� �Լ�
void infix_to_postfix(char exp[]){
	int i=0,k=0;
	char ch,top_op;
	int len=strlen(exp);
	StackType s; //���� s�� Ÿ�� �����Ѵ�.

	init(&s);//���� �ʱ�ȭ
	
	for(i=0; i<len; i++){
		ch=exp[i];//char�� ch�� �迭�� �޴´�.
		switch(ch)/*ch�� �����ڰ� ���������� ���� ����*/{
		case '+': case '-': case '*': case '/': case '%': case '^': 
			//���ÿ� �ִ� �������� �켱������ �� ũ�ų� ������ ���
			while(!is_empty(&s)&&(prec(ch)<=prec(peek(&s)))){
				str1[k]=pop(&s);//�迭 str1�� pop�� char�� ����
				printf("%c ",str1[k]);//�迭 str1�� ���ڸ� ���
				k++;
			}
			push(&s,ch);//Ÿ�� ������ s�� ���� ch�� �ִ´�
			break;
		case '(':
			push(&s,ch);//Ÿ�� ������ s�� ���� ch�� �ִ´�
			break;
		case ')':
			top_op=pop(&s);//Ÿ�� ������ s���� �� ���� ch�� ���� top_op�� �ִ´�
			while(top_op!='(')/*pop�Ͽ� top_op�� ���� ���ڰ� '('�� �ƴϸ� �ݺ����� ����*/{
				str1[k]=top_op;//pop�Ͽ� ������ top_op ���ڰ��� str1 �迭�� ����
				printf("%c ",str1[k]);//������ str1 �迭�� ���
				top_op=pop(&s);//pop�� stacktype ���� top_op�� ����
				k++;
			}
			break;
		default://���� case�� �������� �ʴ� ���϶� ���(�����϶�)
			printf("%c ",ch);
			str1[k]=ch;//���ڸ� �迭 str1�� ����
			k++;
			break;
		}
	}

	//stacktype s�� ������� ������ �ݺ����� ��� ����ȴ�.
	while(!is_empty(&s)){
		str1[k]=pop(&s);//pop�� stacktype�� str1�� �迭�� ����
		printf("%c ",str1[k]);
		k++;
	}
	str1[k]=NULL;//�ݺ����� ���� �� ���ÿ� ����Ǿ��ִ� ������ �ʱ�ȭ�ϴ� ������ �Ѵ�.
}

void main(){
	FILE *fp=fopen("c:\\infix1.txt","r");//��� ��Ʈ���� ����
	int result, value;
	char ch;
	if(fp==NULL)/*���� ����Ϸ��� ������ ������ ��ġ�� �������� ������*/{
		printf("�� ������ �������� �ʽ��ϴ�\n");
	}
	else{
		int n,i,j=0,k=0;
		char ch;
		char str[100]={0};//�迭 str�� �ʱ�ȭ�Ѵ�.
		n=fgetc(fp)-'0';//������ ���� fp���� fgetc�Ͽ� ������ character�� '0'�� ���� int������ ������ش�.
		
		for(i=0;i<n;i++){
		   fgetc(fp);//���� fp���� ���Ƿ� �Ѱ��� ���ڸ� �����´�.
		   printf("infix notation = ");
		   j=0;
		   while((ch=fgetc(fp))!=';')/*������ ���ڰ� ';'�� ���ö� ���� �ݺ��� ���*/{
						str[j++]=ch;//str�迭�� fgetc�Ͽ� �����ͼ� ch�� ������ ���� �ϳ��� �����Ѵ�
					    printf("%c ",ch);//���� ch�� ���
						str[j]=NULL;//j�� +1�� str�� �迭�� NULL������ �����Ѵ�.
				}
		   printf(";\n");
		   printf("postfix notation = ");
		   infix_to_postfix(str);//�Լ� infix_to_postfix�� �迭 str�� �־ ����Ѵ�.
		   printf(";\n");
		   result=eval(str1);//�Լ� eval�� �迭 str1�� �־ ����� int���� result�� �����Ѵ�.
		   printf("value = %d\n",result);
		   printf("\n");
			}
		}
	
		fclose(fp);
		return;
}
