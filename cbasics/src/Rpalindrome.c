/*write a program to find all sub palindrome in a string*/

#include"../inc/Rpalindrome.h"

int main(){

    char string[50],check_1[50],check_2[50];
    int string_len,count,length,length_1,p_count=0,repeat=0;
    char **array=NULL;

    printf("-----PALINDROME-----\n");
    printf("\nenter a word = ");
    scanf("%s",string);

    string_len=strlen(string);
    printf("\npalindrome= ");
    for(count = 0;string[count];count++){
        length_1=string_len;
        do{
            memset(check_1,0,50);
            memset(check_2,0,50);

            length=length_1;
            for(int j = 0;j <= length-count;j++){
                check_1[j]=string[count+j];
            }
            length=length_1;
            for(int j = 0;length>=count;length--,j++){
                check_2[j]=string[length];
            }

            if(strcmp(check_1,check_2)==0){
                for(int i=0;i<p_count-1;i++)
                {
                    if(strcmp(check_1,array[i])==0){
                        repeat=1;
                    }
                }
                if(repeat!=1){
                    p_count++;
                    printf("%s ",check_1);
                    array=(char**)realloc(array,(p_count * sizeof(char*)));
                    array[p_count-1]=(char *)malloc(20*sizeof(char));
                    strcpy(array[p_count-1],check_1);
                }
                repeat=0;
            }
            --length_1;
        }while(length_1);
    }
}
