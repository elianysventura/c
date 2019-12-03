//Elianys Ventura Rodriguez
//////Panther ID: 5652936
////This is a program that gets ten threads to increment a shared variable which is 10
//////“I affirm that I wrote this program myself without any help form any other people or sources from the internet.”.
#include<string.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

#define NUM_THREADS 10

long int shared_var = 13;
pthread_t tid[10];
pthread_mutex_t mutex_lock;

//Increments shared value and threads
void* increment_shared_var(void *arg)
{
	unsigned long i = 0;//Sets lock to 0
 	
	pthread_mutex_lock(&mutex_lock);//Gets mutex lock

	int thread_id = (int)pthread_self();//Gets thread ID

	for(i=0;i<6;i++)//Increments shared variable with specific thread ID
	shared_var = shared_var ++;//thread_id;


	for(i=0; i<(0xFFFFFFFF);i++);
	{	
	
	printf("Thread %d finished\n", thread_id);//thread_id);//Prints thread ID

	pthread_mutex_unlock(&mutex_lock);//Prints thread ID
	}
	return NULL;
}


//Main 
int main(void)
{
	int value;//Variable
	int i = 0;//Variable

	if (pthread_mutex_init(&mutex_lock, NULL) != 0)//Initiates mutex lock
	{
		printf("Mutex initiation has failed\n");//Prints
		return 1;
	}	

	while(i < 10)//Spawns 10 threads
	{
		value = pthread_create(&(tid[i]), NULL, &increment_shared_var, NULL);//Thread spawned
		if (value != 0)//If val isnt equal to 0 dont spawn thread
		printf("Thread can't be created :[%s]\n", strerror(value));
		i++;
	}	

	//10 threads
	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	pthread_join(tid[2], NULL);
	pthread_join(tid[3], NULL);
	pthread_join(tid[4], NULL);
	pthread_join(tid[5], NULL);
	pthread_join(tid[6], NULL);
	pthread_join(tid[7], NULL);
	pthread_join(tid[8], NULL);
	pthread_join(tid[9], NULL);

	pthread_mutex_destroy(&mutex_lock);//Stops lock

	printf("Shared variable value x= %li \n", shared_var);//Prints final shared variable value

	return 0;
}
