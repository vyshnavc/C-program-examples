#include <netinet/in.h>
#include <netinet/ip.h> 
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include<arpa/inet.h>

int sfd,m,len,retval=2;
#define BUFLEN 2000
#define COL 50
#define MAX 256
int IsMethodCorrect(char *,char **,int);

int main(int argc,char *argv[])
{
    char **array ;
    char currTrack[MAX],currSession[MAX];
    char s[BUFLEN],stream_setup[BUFLEN],stream_track[COL];
    int server_port;
    char *stream_name;
    char *server_ip;
    struct sockaddr_in clt;
    struct timeval tv;
    int ret,loc,Method_Count;
    char *ptr,*sub="Public";
    int Key_Live;
    memset(s,0,BUFLEN);
    if(argc != 4){
        printf("uses %s <IP> <PORT> <STREAME NAME>\n",argv[0]);
        return -1;
    }	
    server_port = atoi(argv[2]);
    server_ip=argv[1];
    stream_name=argv[3];
    sfd=socket(AF_INET,SOCK_STREAM,0);

    if(sfd<0)
    {
        perror("socket");
        return 0;
    }
    perror("socket");
    printf("sfd=%d\n",sfd);
    clt.sin_family=AF_INET;
    clt.sin_port=htons(server_port);
    clt.sin_addr.s_addr=inet_addr(server_ip);
    len=sizeof(clt);
    m=connect(sfd,(struct sockaddr *)&clt,len);
    if(m<0)
    {
        perror("connect");
        return 0;
    }
    ret=sprintf(s,"OPTIONS rtsp://%s:%d/%s RTSP/1.1\r\nCSeq: 1\r\nRequire: implicit-play\r\nProxy-Require: gzipped-messages\r\n\r\n",server_ip,server_port,stream_name);

    printf("sending: %s\r\n",s);

    ret=send(sfd,s,strlen(s),0);
    if(ret<=0){
        printf("failed to send data to server\r\n");
        return 0;
    }
    memset(s,0,BUFLEN);	
    ret=recv(sfd,s,sizeof(s),0);
    if(ret<=0){
        printf("failed to receive data from server\r\n");
        return 0;
    }

    ptr=strstr(s,sub);
    loc=ptr-s;
    //	printf("==========%c\n==",s[loc+8]); 

    array=(char**)malloc(sizeof(char*));
    array[0]=(char *)malloc(50*sizeof(char));

    int j=0;
    for(int i=loc+8,k=0;s[i];i++,k++){
        if(s[i]==','){
            j++;
            array=(char**)realloc(array, ((j+1) * sizeof(char*)));
            array[j]=(char *)malloc(50*sizeof(char)); 
            i++;
            k=-1;
            continue;
        }

        array[j][k]=s[i];
    }
    printf("receive : %s\r\n",s);

    Method_Count=j;

    if(IsMethodCorrect("DESCRIBE",array,Method_Count)==0)
    {
        ret=sprintf(s,"DESCRIBE rtsp://%s:%d/%s RTSP/1.0\r\nCSeq: 2\r\n\r\n",server_ip,server_port,stream_name);
        printf("sending: %s\r\n",s);

        ret=send(sfd,s,strlen(s),0);
        if(ret<=0){
            printf("failed to send data to server\r\n");
        }
        memset(s,0,BUFLEN);	
        ret=recv(sfd,s,sizeof(s),0);
        if(ret<=0){
            printf("\nfailed to receive data from server");
        }
        printf("receive : %s\r\n",s);
    }

    ptr = s;
    j=0;
    if(IsMethodCorrect("SETUP",array,Method_Count)==0)
    {
        ptr = strstr(ptr,"a=control:");
        if(ptr == NULL) {
            fprintf(stderr, "No track fount in response sdp\n");
            return 0;
        }
        ptr = strstr(ptr, "\r\n");        
        while((ptr = strstr(ptr,"a=control:")) != NULL) {
            sscanf(ptr, "a=control:%s", currTrack);
            ptr = strstr(ptr, "\r\n");        
           
            memset(stream_setup, 0, BUFLEN);	

            ret=sprintf(stream_setup,"SETUP rtsp://%s:%d/%s/%s RTSP/1.1\r\nCSeq: 3\r\nTransport: RTP/AVP/TCP;interleaved=%d-%d\r\n\r\n",server_ip,server_port,stream_name, currTrack,j,j+1);
            printf("sending: %s\r\n",stream_setup);
            
            ret=send(sfd,stream_setup,BUFLEN,1);
            if(ret<0){
                printf("\nfailed to send data to server");
                return 0;
            }
            memset(stream_setup,0,BUFLEN);	
            ret=recv(sfd,stream_setup,sizeof(stream_setup),0);
            if(ret<0){
                printf("\nfailed to receive data from server");
                return 0;
             }
            printf("receive : %s\n",stream_setup);
            memset(stream_track,0,COL);
            j++;
        }
    }

    if(IsMethodCorrect("PLAY",array,Method_Count)==0)
    {  

        ptr = strstr(stream_setup,"Session:");
        for(int i = ptr-stream_setup+9,j = 0;stream_setup[i]!=';';i++,j++)
            currSession[j]=stream_setup[i];
        ptr = strstr(ptr,"timeout=");
        char buf[10];
        sscanf(ptr, "timeout=%d",&Key_Live);
        ret = sprintf(s,"PLAY rtsp://%s:%d/%s RTSP/1.0\r\nCSeq: 4\r\nRange: npt=5-20\r\nSession: %s\r\n\r\n",server_ip,server_port,stream_name,currSession);
        printf("sending: %s\r\n",s);

        // printf("--time: %d\r\n",Key_Live);

        ret = send(sfd,s,strlen(s),0);
        if(ret <= 0){
            printf("failed to send data to server\r\n");
        }
        memset(s,0,BUFLEN);	
        ret = recv(sfd,s,sizeof(s),0);
        if(ret <= 0){
            printf("\nfailed to receive data from server");
        }
        printf("receive : %s\r\n",s);
    }
    int cnt=0;
    while(1) {
        printf("receive : %c %d %d %d\r\n",s[0], s[1], s[2], s[3]);
        printf("receive : %s\r\n",s);
        memset(s,0,BUFLEN);	
        ret = recv(sfd,s,sizeof(s),0);
        if(ret <= 0){
            printf("\nfailed to receive data from server");
        }
        if(cnt == 50) {
            ret=sprintf(s,"OPTIONS rtsp://%s:%d/%s RTSP/1.1\r\nCSeq: 1\r\nRequire: implicit-play\r\nProxy-Require: gzipped-messages\r\n\r\n",server_ip,server_port,stream_name);
        printf("sending: %s\r\n",s);
        ret = send(sfd,s,strlen(s),0);
            cnt=0;
        }
        cnt++;
    }  

}

int IsMethodCorrect(char *s,char **array,int Method_Count){

    int i;
    for(i=0;i<Method_Count;i++){
        if(strcmp(array[i],s)==0){
            i=-1;
            break;
        }
    }
    if(i!=-1){
        printf("\nMethod Not Allowed\nAllow: OPTIONS, DESCRIBE, SETUP, TEARDOWN, PLAY, PAUSE, GET_PARAMETER, SET_PARAMETER\n");
        return -1;
    }
    else
        return 0;

}
