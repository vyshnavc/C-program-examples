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
    message.mesg_type = 1; 
  
    printf("Write Data : "); 
    scanf("%s",message.mesg_text); 
  
    msgsnd(msgid, &message, sizeof(message), 0); 
  
    printf("Data send is : %s \n", message.mesg_text); 
  
    return 0; 
} 
