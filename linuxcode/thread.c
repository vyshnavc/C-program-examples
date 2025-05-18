/*Have 27 write threads, each will write a character to a one byte shared memory (buffer), a read thread will read this character from the buffer and write to an output file. Each write thread will write an alphabet "a", "b","c"...."z" "\n" to the shared memory (size 1 byte). The read thread will read this character and write to a file. Make sure that the data is not over-written before its read. These threads will continuously write about M time (assume M=100) you need to use thread synchronization to achieve this alphabet sequence. [Remember M is just #define and can be simply changed in a single header file. I can vary this to any number to have the appropriate ASCII to get logged] the output file will have continuous alphabets. If any of the alphabets ordering is changes in between, it means your sequencing has some issue. You have to fix it.*/
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[2],rid;
int count=0;
pthread_mutex_t lock;
FILE *fp;
void* threadwrite(void *arg)
{
	pthread_mutex_lock(&lock); 
//	printf("\n thread %d started = %c\n",count,*(char*)arg+2);
	int shm_id;
	char *shm;
	char s;
	s=*(char*)arg+count;        
	if((shm_id = shmget(5,1,IPC_CREAT|0666))<0)
		perror("shmget");

	if((shm =(char*)shmat(shm_id,0,0))==(char*)-1)
		perror("shmat");

	strcpy(shm,&s);
	count++;
	pthread_mutex_unlock(&lock); 
	return NULL;

}
void* threadread(void *arg)
{
	pthread_mutex_lock(&lock); 
	int shm_id;
	char *shm;
//	char msg,msg1;
	//message = malloc(10*sizeof(char));
	shm_id = shmget(5,1,0);
	shm = shmat(shm_id,0,0);
	if(shm == NULL)
	{
		printf("error");
	}
	//	msg=shm[0];
	//      msg1=shm[1];
	//	printf("\n message = %c  %c\n",msg,msg1);
	fp=fopen("memory","a+");
	fputc(*shm,fp);
	printf("\nmsg=%c",*shm);
	pthread_mutex_unlock(&lock); 
        fclose(fp);
}
int main(void)
{
	int i = 0;
	int error;
	char ch='a';
	if (pthread_mutex_init(&lock, NULL) != 0) 
	{ 
		printf("\n mutex init has failed\n"); 
		return 1; 
	} 
	while(i<26)
	{
		error = pthread_create(&(tid[i]), NULL, &threadwrite,&ch);
		if (error != 0)
			printf("\nThread can't be created ");
		pthread_join(tid[i], NULL);
		pthread_create(&rid,NULL,&threadread,NULL);
		pthread_join(rid,NULL);
		i++;
	}
//	sleep(100);
	pthread_mutex_destroy(&lock); 
	//pthread_join(tid[0], NULL); 
	//pthread_join(tid[1], NULL); 
	return 0;
}
 








































