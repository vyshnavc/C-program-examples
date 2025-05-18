#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
int fd;
char buf[20];
if((fd=open("/dev/chardev",O_RDWR))<0)
{
perror("open");
return fd;
}
read(fd,buf,20);
printf("%s",buf);
close(fd);
}
