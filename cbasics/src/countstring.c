/* Write count main program that performs the following steps:
 *Prompt the user to enter count string, and let them type it in. This could be an entire sentence, with the newline indicating the end of the
 string. You may assume the string will be no more than 100 characters, so declare your array accordingly.Display the following menu:

 *A) Captialize case (First letter is captial of each word)
 *B) Alternative case (assume first letter to be in lower case in result)
 *C) Invert case

 *M) Display this menu
 *X) Exit the program

 *Enter count loop, allowing the user to type in count menu choice each time.
 *Loop should continue until the user enters the command to exit. 
 *Upper and lowercase letters should be allowed for the menu choices.
 */
#include"../inc/countstring.h"
#define max_len 100
int i,j;
int capitalize(char *);
int alternative(char *);
int invert(char *);
int main()
{
	int nullcheck,c;
	printf("==================count string=========================");
	char str[max_len];
    
	do
	{
		printf("\n=======================================================\n");
		printf("\nenter a string :\n");
		scanf(" %[^\n]s",str);
		printf("\n======================================================");
		printf("\nchecking correctons.........\n");
		for(i=0;str[i];i++)                           //remove extra spaces 
		{
			if(str[i]==' '&&str[i+1]==' ')
			{
				for(j=i;str[j];j++)
					str[j]=str[j+1];
				i--;
			}
		}
		printf("%s\n",str);
		printf("\n========================================================\n");
                printf("1)Captialize case\n2)Alternative case\n3)Invert case\n4)Exit the program\n");
                printf("=======================================================");
                printf("\nenter a choicee :\n ");
                scanf("%d",&c);
                printf("=======================================================\n");
        	switch(c)
		{
			case 1:
				do
				{
					nullcheck=capitalize(str);
				}while(nullcheck==0);
				break;
			case 2:
				do
				{			
					nullcheck=alternative(str);
				}while(nullcheck==0);
				break;
			case 3:
				do
				{
					nullcheck=invert(str);

				}while(nullcheck==0);
				break;
			case 4:
				return 0;
			default:;
		}
	}while(1);
}
int capitalize(char *p)
{
	if(p==NULL)
	{
		printf("\nsystem error occured try after sometimes..");
		return 0;
	}
	for(i=0;p[i];i++)
	{
		if(i==0&&p[i]>=97&&p[i]<=122)
			p[i]=p[i]^32;
		else if(p[i]==' '&&p[i+1]>=97&&p[i+1]<=122)
			p[i+1]=p[i+1]^32;
		else;
	}
	printf("capitalized : %s\n",p);
	return 1;
} 
int alternative(char *p)
{
	if(p==NULL)
	{
		printf("\nsystem error occured try after sometimes..");
		return 0;
	}
	char u;
	printf("\nupper case or lower case u/l : ");
	scanf(" %c",&u);
	if(u=='u')
	{
		for(i=0;p[i];i++)
		{
			if(i==0&&p[i]>=97&&p[i]<=122)
				p[i]=p[i]^32;
			else if(p[i]==' '&&p[i+1]>=97&&p[i+1]<=122)
				p[i+1]=p[i+1]^32;
			else;
		}
		printf("\nalternative : %s",p);
	}
	else if(u=='l')
	{
		for(i=0;p[i];i++)
		{
			if(i==0&&p[i]>=65&&p[i]<=91)
				p[i]=p[i]^32;
			else if(p[i]==' '&&p[i+1]>=65&&p[i+1]<=91)
				p[i+1]=p[i+1]^32;
			else;
		}

		printf("\nalternative : %s",p);
	}
	else
	{
		printf("\nwrong choice try again ");
		alternative(p);
	}
	return 1;
}
int invert(char *p)
{
	if(p==NULL)
	{
		printf("\nsystem error occured try after sometimes..");
		return 0;
	}
	printf("\ninvert : ");
	for(i=0;p[i];i++)
	{
		if(i==0&&(p[i]>=65&&p[i]<=91||p[i]>=97&&p[i]<=121))
			p[i]=p[i]^32;
		else if(p[i]!=' '&&(p[i]>=65&&p[i]<=91||p[i]>=97&&p[i]<=121))
			p[i]=p[i]^32;
		else;
	}
	printf("%s\n",p);
	return 1;
}





















