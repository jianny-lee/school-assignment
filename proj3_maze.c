#include <stdio.h>
#include <string.h>
#include <stdlib.h> //exit 함수 사용

#define MAX_STACK_SIZE 500
#define MAZE_SIZE 7 //6 또는 7 사용할 계획

char maze1[MAZE_SIZE][MAZE_SIZE]; //시계 방향으로 저장
char maze2[MAZE_SIZE][MAZE_SIZE]; //반시계 방향으로 저장

int count_block = 0;

typedef struct {
	short r;
	short c;
} element;

typedef struct {
	element stack[MAX_STACK_SIZE];
	int top;
} StackType;


element here, start, end; //현재위치, 입구, 출구

						  //maze 정의
char maze[MAZE_SIZE][MAZE_SIZE] = {
	{ '1','1','1','1','1','1','1' },
	{ 's','0','1','0','1','1','1' },
	{ '1','0','1','0','1','1','1' },
	{ '1','0','0','0','1','1','1' },
	{ '1','0','1','0','0','1','1' },
	{ '1','0','0','1','0','0','e' },
	{ '1','1','1','1','1','1','1' },
};

//스택 초기화 함수
void init(StackType *s)
{
	s->top = -1;
	count_block = 0; //이동 거리 초기화
}

//공백 상태 검출 함수
int is_empty(StackType *s)
{
	return (s->top == -1);
}

//포화 상태 검출 함수
int is_full(StackType *s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}

//삽입 함수
void push(StackType *s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->stack[++(s->top)] = item;
}

//삭제 함수
element pop(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->stack[(s->top)--];
}

//위치를 스택에 삽입하는 함수
void push_loc_maze1(StackType *s, int r, int c)
{
	if (r < 0 || c < 0) return;
	if (maze1[r][c] != '1' && maze1[r][c] != '>') {//벽('1')이 아니고 방문('>')되지 않았으면
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}

}

void push_loc_maze2(StackType *s, int r, int c)
{
	if (r < 0 || c < 0) return;
	if (maze2[r][c] != '1' && maze2[r][c] != '>') {//벽('1')이 아니고 방문('>')되지 않았으면
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp);
	}
}

//기존의 2차원 배열을 새로운 2차원 배열에 복사하는 함수
void copy(char dst[MAZE_SIZE][MAZE_SIZE], const char src[MAZE_SIZE][MAZE_SIZE], int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			dst[i][j] = src[i][j];
		}
	}
}

//미로를 출력하는 함수
void print_Maze(char maze[MAZE_SIZE][MAZE_SIZE], int n) {
	int i, j;
	for (i = 0; i<n; i++) {
		for (j = 0; j<n; j++) {
			printf("%c", maze[i][j]);
		}
		printf("\n");
	}
}

//'1'과 '0'을 출력할때 보기 좋게 만들어 주는 함수
void change_Maze(char maze[MAZE_SIZE][MAZE_SIZE], int n) {
	int i, j;
	for (i = 0; i<n; i++) {
		for (j = 0; j<n; j++) {
			if (maze[i][j] == '1')
				maze[i][j] = 127;

			else if (maze[i][j] == '0')
				maze[i][j] = 0;

		}
	}
}

void count_Maze(char maze[MAZE_SIZE][MAZE_SIZE]) {
	int i, j;
	for (i = 0; i<MAZE_SIZE; i++) {
		for (j = 0; j<MAZE_SIZE; j++) {
			if (maze[i][j] == '>')
				count_block++;
		}
	}
	printf("생쥐가 이동한 거리 : %d\n", count_block);
	printf("\n");
}



void main() {
	int count_block1 = 0; //이동한 블럭 개수
	int count_block2 = 0; //이동한 블럭 개수
	int down_s;
	int r, c; //row, column
	int i, j;
	StackType s;

	init(&s);

	//입구(s)와 출구(e) 탐색
	for (i = 0; i <= MAZE_SIZE; i++)
	{
		for (j = 0; j <= MAZE_SIZE; j++)
		{
			if (maze[i][j] == 's') {
				start.r = i;
				start.c = j;
			}
			if (maze[i][j] == 'e') {
				end.r = i;
				end.c = j;
			}
		}
	}

	printf("입구 : (%d,%d)\n", start.r, start.c);
	printf("출구 : (%d,%d)\n", end.r, end.c);

	here = start; //현재 위치를 시작점으로 정의

	copy(maze1, maze, MAZE_SIZE);
	copy(maze2, maze, MAZE_SIZE);

	//입, 출구 위치 비교
	if (start.r <= end.r) {
		down_s = 0; //입구가 출구보다 위에 있는 경우
	}
	else down_s = 1; //입구가 출구보다 아래에 있는 경우

	//미로 출력(벽:1, 빈 공간:0, 입구:s, 출구:e)
	for (i = 0; i<MAZE_SIZE; i++) {
		for (j = 0; j<MAZE_SIZE; j++) {
			printf("%c", maze1[i][j]);
		}
		printf("\n");
	}
	printf("\n");

					 //stack 저장 순서 정하기
	switch (down_s) {
	case 0:  //입구가 위에 있을 경우
			 //stack에 시계 방향으로 저장
		printf("\n<시계 방향으로 스택에 넣을 때>\n");
		while (maze1[here.r][here.c] != 'e') {
			r = here.r;
			c = here.c;
			maze1[r][c] = '>';

			push_loc_maze1(&s, r, c - 1); //서
			push_loc_maze1(&s, r - 1, c); //북
			push_loc_maze1(&s, r, c + 1); //동
			push_loc_maze1(&s, r + 1, c); //남

			if (is_empty(&s)) {
				printf("스택이 비어있습니다.");
				return;
			}
			else here = pop(&s);
		}

		change_Maze(maze1, MAZE_SIZE);
		print_Maze(maze1, MAZE_SIZE); //이동 경로 출력
		count_Maze(maze1); //이동 거리 count
		count_block1 = count_block;

		//반시계 방향
		//스택, 좌표 초기화
		init(&s);
		here = start;

		printf("\n<반시계 방향으로 스택에 넣을 때>\n");
		while (maze2[here.r][here.c] != 'e') {
			r = here.r;
			c = here.c;
			maze2[r][c] = '>';
			push_loc_maze2(&s, r - 1, c); //북
			push_loc_maze2(&s, r, c - 1); //서
			push_loc_maze2(&s, r + 1, c); //남
			push_loc_maze2(&s, r, c + 1); //동


			if (is_empty(&s)) {
				printf("스택이 비어있습니다.");
				return;
			}
			else here = pop(&s);
		}

		change_Maze(maze2, MAZE_SIZE);
		print_Maze(maze2, MAZE_SIZE); //이동 경로 출력
		count_Maze(maze2); //이동 거리 count
		count_block2 = count_block;

		printf("\n<결과>\n");
		if (count_block1<count_block2) {
			printf("-> 시계 방향으로 스택에 넣는 경우가 생쥐의 최단경로입니다.\n");
			print_Maze(maze1, MAZE_SIZE);
		}
		else if (count_block1>count_block2) {
			printf("-> 반시계 방향으로 스택에 넣는 경우가 생쥐의 최단경로입니다.\n");
			print_Maze(maze2, MAZE_SIZE);
		}
		else if (count_block1 == count_block2) {
			printf("-> 모든 경우가 생쥐의 최단경로입니다.");
			print_Maze(maze1, MAZE_SIZE);
			print_Maze(maze2, MAZE_SIZE);
		}
		break;

	case 1: //start가 아래에 있을 경우
			//시계 방향
		printf("<시계 방향으로 스택에 넣을 때>\n");
		while (maze1[here.r][here.c] != 'e') {
			r = here.r;
			c = here.c;
			maze1[r][c] = '>';

			push_loc_maze1(&s, r + 1, c); //남
			push_loc_maze1(&s, r, c - 1); //서
			push_loc_maze1(&s, r - 1, c); //북
			push_loc_maze1(&s, r, c + 1); //동

			if (is_empty(&s)) {
				printf("스택이 비어있습니다.");
				return;
			}
			else here = pop(&s);

		}

		change_Maze(maze1, MAZE_SIZE);
		print_Maze(maze1, MAZE_SIZE);  //이동 경로 출력
		count_Maze(maze1); //이동 거리 count
		count_block1 = count_block;

		//반시계 방향
		//스택, 좌표 초기화
		init(&s);
		here = start;

		printf("\n<반시계 방향으로 스택에 넣을 때>\n");
		while (maze2[here.r][here.c] != 'e') {
			r = here.r;
			c = here.c;
			maze2[r][c] = '>';
			push_loc_maze2(&s, r, c - 1); //서
			push_loc_maze2(&s, r + 1, c); //남
			push_loc_maze2(&s, r, c + 1); //동
			push_loc_maze2(&s, r - 1, c); //북

			if (is_empty(&s)) {
				printf("스택이 비어있습니다.");
				return;
			}
			else here = pop(&s);
		}

		change_Maze(maze2, MAZE_SIZE);
		print_Maze(maze2, MAZE_SIZE);  //이동 경로 출력
		count_Maze(maze2); //이동 거리 count
		count_block2 = count_block;

		printf("\n<결과>\n");
		if (count_block1<count_block2) {
			printf("-> 시계 방향으로 스택에 넣는 경우가 생쥐의 최단경로입니다.\n");
			print_Maze(maze1, MAZE_SIZE);
		}
		else if (count_block1>count_block2) {
			printf("-> 반시계 방향으로 스택에 넣는 경우가 생쥐의 최단경로입니다.\n");
			print_Maze(maze2, MAZE_SIZE);
		}
		else if (count_block1 == count_block2) {
			printf("-> 모든 경우가 생쥐의 최단경로입니다.\n");
			print_Maze(maze1, MAZE_SIZE);
			print_Maze(maze2, MAZE_SIZE);
		}
		break;
	}
}
