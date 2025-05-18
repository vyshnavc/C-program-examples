#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>


void main()
{
    struct sembuf sem_op;
    int file;
    int sem_id;
    char a[]="vyshnav";
    sem_id=semget(5,1,IPC_CREAT|0644);
      
    if(sem_id<0)
    {
     perror("semget");
     return;
    }
    sem_op.sem_num = 1;
    sem_op.sem_op = 0;
    sem_op.sem_flg = 0;

    semop(sem_id, &sem_op, 1);
    file = open("text",O_RDWR|O_APPEND|O_CREAT,0644);

    semctl(sem_id,1,SETVAL,1);

   // while(1)
    
    if(file)
    {   for(int i=0;a[i];i++)
         {
          write(file,&a[i],1);
          sleep(1);
         }
    }

    semctl(sem_id,1,SETVAL,0);

}
