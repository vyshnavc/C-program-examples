/*implement a full duplex client server application using socket*/
#include"../inc/servclt.h"

int sfd,m,len,retval=2;

void main()
{
	char s[100];
	struct sockaddr_in clt;
        struct timeval tv;
	
        sfd=socket(AF_INET,SOCK_STREAM,0);
        
        
	if(sfd<0)
	{
		perror("socket");
		return;
	}
	perror("socket");
	printf("sfd=%d\n",sfd);
	clt.sin_family=AF_INET;
	clt.sin_port=htons(3001);
	clt.sin_addr.s_addr=inet_addr("127.0.0.1");
	len=sizeof(clt);
	m=connect(sfd,(struct sockaddr *)&clt,len);
	if(m<0)
	{
		perror("connect");
		return;
	}
	perror("connect");
	if(fork()==0)
	{
		while(1)
		{
			bzero(s,100);
			read(sfd,s,sizeof(s));
			if(strcmp(s,"bye")==0)
			{
				printf("\nserver terminated\n");
				break;
			}        
			printf("%s\n",s);
		}
	}
	else
	{
		while(1)
		{
			bzero(s,100);
			fd_set readset;
			FD_ZERO(&readset);
			FD_SET(sfd, &readset);	

			tv.tv_sec = 5;
			tv.tv_usec = 0;
			scanf("%s",s);
			write(sfd,s,strlen(s)+1);
       		retval = select(sfd, &readset, NULL, NULL, &tv);
			if (retval == -1)
        			perror("select()");
                        else if(retval==0)
                         printf("\ntime out.....\n");
                        else;
                        if(strcmp(s,"bye")==0)
                        break;
		}
	}
}
