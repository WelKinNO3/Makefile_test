#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "pthread.h"
#include "string.h"

char message[] = "Hello World!\n";

void * pthread_fun(void * para)
{
	printf("message is %s \n",para);
	strcpy(message,"Hi");
	pthread_exit("the pthread_func is running \n");
}



void main (char argc ,char* argv[])
{

	int res;
	pthread_t thread_t; 
	char * result;

		res = pthread_create(
					&thread_t,
					NULL,
					pthread_fun,
					message
					);
	if(res != 0)
	{
		printf("there is an error about failling to used the function of pthread_create !\n");
		exit(-1);
	}

	printf("Wait for pthread_fun !\n");
	res = pthread_join(
			thread_t,
			&result
			);
	
	if(res != 0)
	{
		printf("there is an error about failling to used the function of pthread_create !\n");
		exit(-1);
	}
	printf("the reture : %s \n",result);
	printf("The message is %s now \n",message);
	exit(0);
}
