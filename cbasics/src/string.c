/*	Write a main program that performs the following steps:
 *	Prompt the user to enter a string, and let them type it in. This 
 *	could be an entire sentence, with the newline indicating the end of the 
 *	string. You may assume the string will be no more than 100 characters, so 
 *	declare your array accordingly.Display the following menu:
 *
 *	A) Count the number of vowels in the string
 *	B) Count the number of consonants in the string
 *	C) Convert the string to uppercase
 *	D) Convert the string to lowercase
 *	E) Display the current string
 *	I) Enter another string
 *		
 *	M) Display this menu
 *	X) Exit the program
 *
 *	Enter a loop, allowing the user to type in a menu choice each time. 
 *	Loop should continue until the user enters the command to exit. Upper and 
 *	lowercase letters should be allowed for the menu choices. 
 *
 */

#include"../inc/string.h"

int vowels(char *);
int consonants(char *);
int upper(char *);
int lower(char *);
int newstring(char *);
void menu(void);

#define max_len 100

int g_count,g_i;

void main()
{
	//	printf(__TIME__);
	char string[max_len],c;
	int checknull;

	system("clear");
	printf("enter a string: ");
	scanf(" %[^\n]s",string);
	do{     
		system("clear");
		printf("\n%s",string);
		printf("\n==========================================================================\n");
		menu();
		printf("==========================================================================\n");
		printf("enter a option : ");
		scanf(" %c",&c);
		printf("==========================================================================\n");
		switch(c)
		{
			case 'A': 
				do
				{
					checknull=vowels(string);
				}while(checknull==0);
				break;
			case 'B':
				do
				{
					checknull=consonants(string);
				}while(checknull==0);
				break;
			case 'C':
				do
				{
					checknull=upper(string);
				}while(checknull==0);			
                       	        break;
			case 'D': 
				do
				{
					checknull=lower(string);
				}while(checknull==0);
				break;
			case 'E': printf("\n%s",string);
				  break;
			case 'I':
				  do
				  {
					  checknull=newstring(string); 
				  }while(checknull==0);
				  break;
			case 'X': return;
			default :;
		}


		printf("\n===========================================================================\n");
		sleep(2);
	}while(1);
}

void menu(void)
{
	printf("\nA) Count the number of vowels in the string\nB) Count the number of consonants in the string\nC) Convert the string to uppercase\nD) Convert the string to lowercase\nE) Display the current string\nI) Enter another string\nX) Exit the program\n");
}

int vowels(char *p)
{
	if(p==NULL)
	{
		printf("\nsystem error occured");
		return 0;
	}
	g_count=0;
	for(g_i=0;p[g_i];g_i++)
	{ if(p[g_i]=='A'||p[g_i]=='a'||p[g_i]=='e'||p[g_i]=='E'||p[g_i]=='i'||p[g_i]=='I'||p[g_i]=='o'||p[g_i]=='O'||p[g_i]=='u'||p[g_i]=='U')
		g_count++;
	}
	printf("number of vowels : %d ",g_count);
return 1;
}

int consonants(char *p)
{
	if(p==NULL)
	{
		printf("\nsystem error occured");
		return 0;
	}

	g_count=0;
	for(g_i=0;p[g_i];g_i++)
	{ if(p[g_i]!='A'&&p[g_i]!='a'&&p[g_i]!='e'&&p[g_i]!='E'&&p[g_i]!='i'&&p[g_i]!='I'&&p[g_i]!='o'&&p[g_i]!='O'&&p[g_i]!='u'&&p[g_i]!='U'&&((p[g_i]>=65&&p[g_i]<=91)||(p[g_i]>=97&&p[g_i]<=121)))	
		g_count++;
	}
	printf("number of consonants : %d ",g_count);
return 1;
}

int upper(char *p)
{
	if(p==NULL)
	{
		printf("\nsystem error occured");
		return 0;
	}

	printf("\nupper case : ");
	for(g_i=0;p[g_i];g_i++)
	{
		if(p[g_i]!=' '&&p[g_i]>=97&&p[g_i]<=121)
			printf("%c",p[g_i]^32);
		else
			printf("%c",p[g_i]);
	}
return 1;
}

int lower(char *p)
{
	if(p==NULL)
	{
		printf("\nsystem error occured");
		return 0;
	}

	printf("\nlower case : ");
	for(g_i=0;p[g_i];g_i++)
	{
		if(p[g_i]!=' '&&p[g_i]>=65&&p[g_i]<=91)
			printf("%c",p[g_i]^32);
		else
			printf("%c",p[g_i]);
	}
return 1;
}

int newstring(char *s)
{
	if(s==NULL)
	{
		printf("\nsystem error occured");
		return 0;
	}
	bzero(s,max_len);
	printf("\nenter new string :\n");
	scanf(" %[^\n]s",s);
return 1;
} 
//((p[g_i]>=65&&p[g_i]<=91)||(p[g_i]>=97&&p[g_i]<=121))
