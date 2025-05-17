/* Program to find the paricular "word_to_search" in the string and if found replace it by a user defined word. Use dyanmic memory allocation to take in user defined word.*/

#include"../inc/replaceword.h"

#define size 100
#define wsize 50

char *replace;

int replaceword(char *,const char *,const char *);

void main()
{
	int check=0;
	char reword[wsize],*newword,string[size];

	printf("\nenter a string...\n");
	scanf(" %[^\n]s",string);
	while(1){	{
		printf("\nenter the word to replace \n");
		scanf(" %s",reword);
		if(strstr(string,reword)!=NULL)
			break;
		printf("\nword is not present try another word\n");
	}
	newword=malloc(sizeof(char)*size);
	printf("\nenter new word\n");
	scanf(" %[^\n]s",newword);
	do{
		check=replaceword(string,reword,newword);
	}while(check==0);
	       printf("\n%s\n",replace);
}

int replaceword(char *str,const char *old,const char *new)
{

        if(str==NULL&&old==NULL&&new==NULL){
         printf("\nsystem error occured");
         return 0;
        }

	int old_len,new_len,count=0,i,j;

	old_len=strlen(old);
	new_len=strlen(new);
	for(i=0;str[i];i++){
		if(strstr(&str[i],old)==&str[i]){
			count++;
			i=i+old_len-1;
		}
	}
	replace=(char*)malloc(i+count*(new_len-old_len)+1);
	for(i=0,j=0;str[i];i++,j++){
		if(strstr(&str[i],old)==&str[i]){
			strcpy(&replace[j],new);
			i=i+old_len-1;
                        j=j+new_len-1;
		}
		else
			replace[j]=str[i];
	}
	replace[j]='\0';
	return 1;
}




























