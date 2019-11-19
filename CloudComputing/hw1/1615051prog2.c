#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

int main(void){
	int a[1000],aTemp[1000]; //배열 a와 aTemp 선언
	int b[1000],bTemp[1000]; //배열 b와 bTemp 선언
	int i,rank_size,k,i_temp;
	int comm_size, my_rank;

	srand(time(NULL));

	MPI_Init(NULL, NULL); //MPI 초기화
	//communicator 내의 process들에게 번호 부여	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	//communicator 내의 process들의 개수
	MPI_Comm_size(MPI_COMM_WORLD, &comm_size);

	if(my_rank==0){ //rank가 0일 때, 배열 a에 값을 부여한다.
		for(i=0;i<1000;i++){
		a[i]=rand()%4+1;
		}
	}

	rank_size = 1000/comm_size;

	//P0의 a배열의 값들을 rank_size만큼씩 전체 프로세스들의 배열 aTemp에 rank_size만큼 scatter한다.
	MPI_Scatter(a,rank_size,MPI_INT,&aTemp,rank_size,MPI_INT,0,MPI_COMM_WORLD);

	bTemp[0]=aTemp[0];

	for (i=1;i < rank_size; i++){
		bTemp[i]=bTemp[i-1]+aTemp[i];
 	}

	//전체 프로들의 bTemp에서 250만큼 P0의 b배열로 Gather한다.
	MPI_Gather(bTemp,rank_size,MPI_DOUBLE,b,rank_size,MPI_DOUBLE,0,MPI_COMM_WORLD);

	if(my_rank==0){
		for(i=0;i<1000;i++){
		printf("%d. value of array rank %d= %f\n",i,my_rank,b[i]);
		}
	}


	MPI_Finalize();
}
