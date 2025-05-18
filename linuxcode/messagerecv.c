#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
  
struct mesg_buffer { 
    long mesg_type; 
    char mesg_text[100]; 
} message; 
  
int main() 
{ 
    int msgid; 
  
    msgid = msgget(5, 0666 | IPC_CREAT); 
  
    msgrcv(msgid, &message, sizeof(message),1, 0); 
  
    printf("Data Received is : %s \n",  
                    message.mesg_text); 
  
  //    msgctl(msgid, IPC_RMID, NULL); 
      return 0; 
} 
