#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

void fun(void);
pthread_t tid1,tid2;
void* thread1(void *arg)
{
	int n=*(int*)arg;
	while(1)
	{
		sleep(n);
		printf("\n\nafter %d sec thread awake",n);
		fflush(stdout);
	//	system("gnome-terminal -e sl");
		system("gnome-terminal -e vyshnav/ipc/./send");
	}
}
void* thread2(void *arg)
{
	int n=*(int*)arg;
	while(1)
	{
		sleep(n);
		printf("\n\nafter %d sec thread awake",n);
		fflush(stdout);
		system("gnome-terminal -e sl");
	}
}
int main(void)
{
	int i = 0;
	int error;
	int ch;
	//        for(i;i<5;i++)
	{
		printf("\nenter interrupt time : ");
		scanf("%d",&ch);
		error = pthread_create(&(tid1), NULL, &thread1,&ch);
		if (error != 0)
			printf("\nThread can't be created ");
	/*	printf("\nenter interrupt time : ");
		scanf("%d",&ch);
		error = pthread_create(&(tid2), NULL, &thread2,&ch);
		if (error != 0)
			printf("\nThread can't be created ");*/
	}
	while(1);
}
