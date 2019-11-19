#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define total 100000
#define Num 10

int thread_count;
int sum[Num];

void *Thread_sum(void *rank); //thread function

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; //init thread 

int main(int argc, char * argv[]) {

	long i;
	long thread;
	int scoreNum[total];
	pthread_t * thread_handles;

	/*Get number of threads from command line*/
	thread_count = strtol(argv[1], NULL, 10);
	thread_handles = malloc(thread_count * sizeof(pthread_t));
	
	for (thread = 0; thread < thread_count; thread++) {

		pthread_create(&thread_handles[thread], NULL, Thread_sum, (void*) thread);
	}

	for (thread=0; thread < thread_count; thread++) {

		pthread_join(thread_handles[thread], NULL);
	}

	free(thread_handles);

	/*print the number of student grade distribution*/
	for(i=0;i<Num;i++)
		printf("%d ",sum[i]);
	printf("\n");

	return 0;

}

void * Thread_sum (void *rank) {

	FILE *fp = fopen("scores.txt","r");//open file

	long my_rank = (long) rank;
	int my_sum[Num];
	long long i;
	long long my_n = total/thread_count;
	long long my_first_i = my_n * my_rank;
	long long my_last_i = my_first_i + my_n;
	int scoreNum[total];

	for(i = 0; i < total; i++)//input the value scoreNum
		fscanf(fp, "%d", &scoreNum[i]);	

	for(i = my_first_i;i<my_last_i;i++){//calculate of student grade distribution
	
		if(scoreNum[i]>=0 && scoreNum[i]<=10)
			my_sum[0]++;

		else if(scoreNum[i]>10&&scoreNum[i]<=20)
			my_sum[1]++;

		else if(scoreNum[i]>20&&scoreNum[i]<=30)
			my_sum[2]++;

		else if(scoreNum[i]>30&&scoreNum[i]<=40)
			my_sum[3]++;

		else if(scoreNum[i]>40&&scoreNum[i]<=50)
			my_sum[4]++;
		
		else if(scoreNum[i]>50&&scoreNum[i]<=60)
			my_sum[5]++;

		else if(scoreNum[i]>60&&scoreNum[i]<=70)
			my_sum[6]++;

		else if(scoreNum[i]>70&&scoreNum[i]<=80)
			my_sum[7]++;

		else if(scoreNum[i]>80&&scoreNum[i]<=90)
			my_sum[8]++;

		else if(scoreNum[i]>90&&scoreNum[i]<=100)
			my_sum[9]++;
	}

	pthread_mutex_lock(&mutex); //restrict access to a critical section
	for(i = 0;i<10;i++)/*insert the number of total student */
		sum[i]+=my_sum[i];
	pthread_mutex_unlock(&mutex); //thread is finished executing the code

	fclose(fp); //close the file

	return NULL;
}
