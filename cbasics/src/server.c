#include"../inc/servclt.h"

void ISR(void);

int sfd,r,len,nsfd,retval;

void main()
{
	char buf[100];
	struct sockaddr_in ser,client;
        struct timeval tv;

	sfd=socket(AF_INET,SOCK_STREAM,0);
       

	if(sfd<0)
	{
		perror("socket");
		return;
	}

	perror("socket");
	printf("sfd=%d\n",sfd);



        ser.sin_family=AF_INET;
	ser.sin_port=htons(3000);
	ser.sin_addr.s_addr=inet_addr("0.0.0.0");

	len=sizeof(ser);
	r=bind(sfd,(struct sockaddr *)&ser,len);

	if(r<0)
	{
		perror("bind");
		return;
	}

	perror("bind");


	listen(sfd,5);
	perror("listen");


	nsfd=accept(sfd,(struct sockaddr *)&client,&len);

	if(nsfd<0)
	{
		perror("accept");
		return;
	}

	perror("accept");
       
       
	if(fork()==0)
	{
		while(1)
		{
                        bzero(buf,100);
                        read(nsfd,buf,sizeof(buf));
                        if(strcmp(buf,"bye")==0)
                        {
                         printf("\nclient terminated\n");
                         break;
                        }  
			printf("%s\n",buf);
        }

	}
	else
	{
		while(1)
		{
			bzero(buf,100);
			fd_set readset;
			FD_ZERO(&readset);
			FD_SET(sfd, &readset);

			tv.tv_sec = 5;
			tv.tv_usec = 0;
			scanf("%s",buf);
			write(nsfd,buf,strlen(buf)+1);
			retval = select(sfd, &readset, NULL, NULL, &tv);
            if(retval==-1)
                perror("select()");
            else if(retval==0)
                printf("\ntime out....\n");
            else;
            if(strcmp(buf,"bye")==0)
                break;
		}

	}
}






