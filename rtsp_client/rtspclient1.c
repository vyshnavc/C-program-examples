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
int isMethoodSuported(char *s,char *array);

int main(int argc,char *argv[])
{
       	char *array;
	char s[BUFLEN];
        int server_port;
 	char *stream_name;
        char *server_ip;
	struct sockaddr_in clt;
        struct timeval tv;
	int ret;
	int loc;
	char *ptr,*sub="Public";
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

	printf("sending: %s\n",s);

	ret=send(sfd,s,strlen(s),0);
	if(ret<=0){
		printf("\nfailed to send data to server");
                return 0;
	}
	memset(s,0,BUFLEN);	
	ret=recv(sfd,s,sizeof(s),0);
	if(ret<=0){
		printf("\nfailed to receive data from server");
                return 0;
	}

	ptr=strstr(s,sub);
	loc=ptr-s;
	array=(char*)malloc(sizeof(char));

        for(int i = 0; s[i+loc+17]; i++)
	        array[i]=s[i+loc+17];
//        printf("\n====%s ",array);

	printf("\nreceive : %s\n",s);

        ret = isMethoodSuported("DESCRIBE", array);
	if(ret == 0) {
		ret=sprintf(s,"DESCRIBE rtsp://%s:%d/%s RTSP/1.0\r\nCSeq: 2\r\n\r\n",server_ip,server_port,stream_name);
		printf("sending: %s\n",s);
		return 0;
		ret=send(sfd,s,strlen(s),0);
		if(ret<=0){
			printf("\nfailed to send data to server");
		}
		memset(s,0,BUFLEN);	
		ret=recv(sfd,s,sizeof(s),0);
		if(ret<=0){
			printf("\nfailed to receive data from server");
		}
		printf("receive : %s\n",s);
	}

	ret=sprintf(s,"SETUP rtsp://%s:%d/%s RTSP/1.0\r\nCSeq: 2\r\n\r\n",server_ip,server_port,stream_name);
	printf("sending: %s\n",s);
        ret= isMethoodSuported(s,array);
        if(ret==-1)
        return 0;

	ret=send(sfd,s,strlen(s),0);
	if(ret<=0){
		printf("\nfailed to send data to server");
	}
	memset(s,0,BUFLEN);	
	ret=recv(sfd,s,sizeof(s),0);
	if(ret<=0){
		printf("\nfailed to receive data from server");
	}
	printf("receive : %s\n",s);
}

int isMethoodSuported(char *s,char *array)
{
        int i=0,ret=0;
	char check[50];
	memset(check,0,50);

	while(s[i]!=' '){
		check[i]=s[i];
		i++;	
	}
	ret=strstr(array,check);
	
        if(ret==0){
		printf("\nMethod Not Allowed\nAllow: OPTIONS, DESCRIBE, SETUP, TEARDOWN, PLAY, PAUSE, GET_PARAMETER, SET_PARAMETER\n");
                return -1;
 	}
        else 
           return 0;
}
