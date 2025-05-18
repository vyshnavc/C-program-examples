#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {

//key_t key=1235;
int shm_id;
char *shm;
char message;
//message = malloc(10*sizeof(char));
shm_id = shmget(5,10,0);
shm = shmat(shm_id,0,0);
printf("vlaue of shmat in recive sid %d\n",shm_id);
if(shm == NULL)
{
printf("error");
}
//strcpy(message,shm);
message=*shm;
printf("\n message = %c\n",message);
shmdt(shm);
}
