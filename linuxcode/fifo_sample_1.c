#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
int main() 
{ 
    int fd; 
    mkfifo("fifo", 0666); 
  
    char arr1[80], arr2[80]; 
    while (1) 
    { 
        fd = open("fifo", O_WRONLY); 
        printf("\nenter a data : ");
        scanf("%s",arr2);
        
        fflush(stdout);
//        printf("\n%s",arr2);  
        write(fd, arr2, strlen(arr2)+1); 
        close(fd); 
  
        fd = open("fifo", O_RDONLY); 
  
        read(fd, arr1, sizeof(arr1)); 
  
        printf("User2: %s ", arr1); 
        close(fd); 
    } 
    return 0; 
} 
