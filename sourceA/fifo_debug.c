//#include "stdio.h"
//	sort_t(sort_test,5);
#include "stdio.h"
#include "unistd.h"
#include "fcntl.h"
#include "sys/types.h"
#include "sys/wait.h"
#include "stdlib.h"
main(char argc ,char * argv[]  )
{
	char* PATH_L;
	int open_model,res;
	char *Buff[BUFSIZ];
	if(argc > 1)
	{
		PATH_L = argv[1]; //定义环境
		for(char i = 1; i<argc;i++)
		{
			if(strncmp("O_RDONLY",argv[i],8))
			{
				open_model |= O_RDONLY;				
			}
			else if(strncmp("O_WRONLY",argv[i],8))
			{
				open_model |= O_WRONLY;
			}
			if(strncmp("O_NONBLOCK",argv[i],10))
			{
				open_model |= O_NONBLOCK;
			}
	
		}

	}
	else
	{
		printf("there is an error about the menber of parament is to less!\n ");
		return -1;
	}

	if(access(PATH_L,F_OK) == -1)
	{
		res = mkfifo(PATH_L,0777);
	 	if(res != 0)
		{
			printf("could not create the fifo : %s \n",PATH_L);
			exit(-1);
		}
	}
	

	printf("process %d will open FIFO : %s , the model = %d \n",getpid(),argv[1],open_model);

	res = open(PATH_L,open_model);
	printf("process %d is return the function of open \n",getpid());

	sleep(5);
	if(res >0)
	{
		if(open_model & O_WRONLY == O_WRONLY)
		{
			if(write(res,"hello",sizeof("hello"))>0)
			{
				
				printf("The process %d write data to fifo : %s \n",Buff);
			}
			
		}
		else if(open_model & O_RDONLY == O_RDONLY)
		{
			if(read(res,Buff,BUFSIZ)>0)
			{
				printf("The process %d read data from fifo : %s \n",Buff);
			}
		}

	(void)close(res);
	}
	else
	{
		printf("there is an error about failling to open the fifo \n");
	}
exit(0);

	









	//return 0;
#if (DEBUG == 1)
			printf("son process is ready !\n");
#endif
#if (DEBUG==1)
			printf("parant process is running !\n");
#endif


	#if DEBUG==2
		
	for(i=0;i<5;i++)
	{
		printf("Compiled: "__DATE__" at "__TIME__"\n ");
		printf("This is line %d of file %s\n",__LINE__,__FILE__);
		printf("sort_%d : Member = %s  key = %d \n",i,sort_test[i].Name,sort_test[i].key);
	}
	


	#endif
}
