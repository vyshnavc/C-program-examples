/*Write a program for polynomial addition, subtraction, and multiplication. Use dynamic memory allocation to take in the polynomial enetred by the user.*/

#include"../inc/polynomial.h"

int display(int *,int);
int addition(int *,int *,int *,int);
int subtraction(int *,int *,int *,int);
int multiplication(int *,int *,int *,int,int,int);
int input(int *,int);
int my_copy(int * ,int *,int);

void main()
{
	printf("\n==========polynomial addition===========");
	printf("\n\nplease follow the instruction {5,0,-3,2} = 2x^3-3x^2+5");

	int *p,*p2,*p3,i,size,check,num1,num2;
	char choice;
	static int test;

	do
	{
		printf("\n\nenter total number for 1st polynomial function : ");
		check=scanf("%d",&num1);
		if(check==0)
		{
			scanf("%*s");
			printf("\nwrong input");
		}
	}while(check==0);

	p=malloc(sizeof(int)*num1);

	do
	{
		check=input(p,num1);
	}while(check==0);
	do
	{
		printf("\nenter total number for 2nd polynomial function : ");
		check=scanf("%d",&num2);
		if(check==0)
		{
			scanf("%*s");
			printf("\nwrong input");
		} 
	}while(check==0);

	p2=malloc(sizeof(int)*num2);

	do
	{
		check=input(p2,num2);
	}while(check==0);
	size=num1>num2?num1:num2;

	p3=malloc(sizeof(int)*size);        

	while(1)
	{
		test++;
		printf("\n");
		printf("\nA)addition\nB)subtraction\nC)multiplication\nD)do more operation on result\nX)exit\nenter a choice : ");
		scanf(" %c",&choice);
		switch(choice)
		{

			case 'A':
				do
				{
					check=addition(p,p2,p3,size);
				}while(check==0);
				printf("\n");
				system("clear");
				do{check=display(p,num1);}while(check==0);
				printf("  +\n\n");
				do{check=display(p2,num2);}while(check==0);
				printf("\n\n---------------------------------\n");
				do{check=display(p3,size);}while(check==0);
				break;
			case 'B':
				do{check=subtraction(p,p2,p3,size);}while(check==0);
				printf("\n");
				system("clear");
				do{check=display(p,num1);}while(check==0);
				printf("  -\n\n");
				do{check=display(p2,num2);}while(check==0);
				printf("\n\n---------------------------------\n");
				do{check=display(p3,size);}while(check==0);
				break;
			case 'C':
				size=num1+num2-1;
				do{check=multiplication(p,p2,p3,num1,num2,size);}while(check==0);
				printf("\n");
				system("clear");
				do{check=display(p,num1);}while(check==0);
				printf("  *\n\n");
				do{check=display(p2,num2);}while(check==0);
				printf("\n\n---------------------------------\n");
				do{check=display(p3,size);}while(check==0);
				break;
			case 'D':
				if(test<2)
				{
					printf("\nyou haven't did any operation yet");
					test--;
				}
				else
				{

					free(p);
					p=malloc(sizeof(int)*size);
					do{check=my_copy(p,p3,size);}while(check==0);
					num1=size;
					free(p3);
					free(p2);
					do
					{
						printf("\nenter total number for polynomial function\n");
						check=scanf("%d",&num2);
						if(check==0)
						{
							scanf("%*s");
							printf("\nwrong input");
						}
					}while(check==0);
					p2=malloc(sizeof(int)*num2);
					do{check=input(p2,num2);}while(check==0);
					size=num1>num2?num1:num2;
					p3=malloc(sizeof(int)*size);        
				}
				break;

			case 'X':return;
			default:
				 test--;
				 printf("\nwrong choice");
		}

	} 

free(p);
free(p2);
free(p3);

}

int input(int *p,int size)
{
	if(p==NULL)
	{
		printf("\nsystem error occured");
		return 0;
	}

	int i,check;

	for(i=0;i<size;i++)
	{
		printf("\n\nenter number : ");
		check=scanf("%d",&p[i]);
		if(check==0)
		{
			printf("\nwrong input..enter again..");
			scanf("%*s");
			i--;
			continue;
		}
		system("clear");
		display(p,i);
	}
}

int my_copy(int *p,int *p3,int size)
{
	if(p==NULL&&p3==NULL)
	{
		printf("\nsystem error occured");
		return 0;
	}
	for(int i=0;i<size;i++)                                                                            
		p[i]=p3[i];
}

int addition(int *p,int *p2,int *p3,int size)
{
	if(p==NULL&&p2==NULL&&p3==NULL)
	{
		printf("\nsystem error occured");
		return 0;
	}

	int count;

	for(count=0;count<size;count++)
	{
		p3[count]=p[count]+p2[count];
	}
}
int subtraction(int *p,int *p2,int *p3,int size)
{
	if(p==NULL&&p2==NULL&&p3==NULL)
	{
		printf("\nsystem error occured");
		return 0;
	}

	int count;

	for(count=0;count<size;count++)
	{
		p3[count]=p[count]-p2[count];
	}

}

int multiplication(int *p,int *p2,int *p3,int num1,int num2,int size)
{
	if(p==NULL&&p2==NULL&&p3==NULL)
	{
		printf("\nsystem error occured");
		return 0;
	}

	int count,i,j;
	int *temp=malloc(sizeof(int)*num1);

	free(p3);

	p3=calloc(size,sizeof(int));
	for(i=0;i<num2;i++)
	{
		for(j=0;j<num1;j++)
			temp[j]=p[j]*p2[i];
		for(count=0;count<size;count++)
			p3[count+i]=p3[count+i]+temp[count];
	}
        free(temp);
	return 1;
}
int display(int *p,int size)
{
	if(p==NULL)
	{
		printf("\nsystem error occured");
		return 0;
	}

	int count;

	for(count=size;count>=0;count--)
	{
		if(p[count]==0)
			continue;
		else
		{
			if(p[count]>0)
				printf("+");
			printf("%d",p[count]);
			if(count!=0)
				printf("x^%d",count);
		}
	}
	return 1;
}

















