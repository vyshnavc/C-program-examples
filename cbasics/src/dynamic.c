/*Write a program to input a list of real numbers of unknown length and output : sum and count of all positive & negative numbers.
* Perform    the output using following cases
*                  a) Pointer to array
*                  b) Pointer to Pointer
*    
*/

#include"../inc/dynamic.h"
int pointerarray(float (*),int);
int pointerpointer(float **,int);
void main()
{
	int nullcheck,count,check;
	char option;
        long int size;
	do
	{    
		printf("\nenter how many real number you want to enter : \n");
		check=scanf("%ld",&size);
		if(check==0)
		{
			scanf("%*s");
			printf("\nwrong input..");
		}
		else if(size>1000)
		{
			check=0;
			printf("\ntry in range 1-1000");
		}
		else;
	}while(check==0);       
	float *pointer[size];
	float *array=malloc(sizeof(float)*size);
	printf("\n==============================================");
	for(count=0;count<size;count++)
	{
		while(1)
		{
			printf("\nenter number %d : ",count+1);
			check=scanf("%f",&array[count]);
			if(check==0)
			{
				scanf("%*s");
				printf("\nwrong input");
			}
			else if(array[count]>1000000)
			{
				check=0;
				printf("\nbeyond the limit try with 6 digit number");
			}
			else
			{
				pointer[count]=&array[count];
				break;
			}
		}	
	}
	printf("\n==============================================");
	do
	{
		printf("\nUsing...?\na)pointer to pointer\nb)pointer to an array\nc)exit program\nenter a option : ");
		scanf(" %c",&option);
		if(option=='a'||option=='A')
		{
			do
			{
				nullcheck=pointerpointer(pointer,size);
			}while(nullcheck==0);
		}
		else if(option=='b'||option=='B')
		{
			do
			{
				nullcheck=pointerarray(array,size);
			}while(nullcheck==0);
		}
		else if(option=='c'||option=='C')  
			return;
		else
		{
			printf("\nwrong choice");
		}
	}while(1);

}
int pointerpointer(float **array,int size)
{
	if(array==NULL)
	{
		printf("\nsystem error occured ");
		return 0;
	}
	int count,postive=0,negative=0;
	float sum=0;
	for(count=0;count<size;count++)
	{
		if(*array[count]<=-1)
		{
			negative++;
		}
		else
			postive++;
		sum=sum+*array[count];
	}
	printf("\npostive=%d\nnegative=%d\nsum=%f\n",postive,negative,sum);
	return 1;
}
int pointerarray(float (*array),int size)
{
	if(array==NULL)
	{
		printf("\nsystem error occured ");
		return 0;
	}
	int count,postive=0,negative=0;
	float sum=0;
	for(count=0;count<size;count++)
	{
		if(array[count]<=-1)
			negative++;
		else
			postive++;
		sum=sum+array[count];

	}
	printf("\npostive=%d\nnegative=%d\nsum=%f\n",postive,negative,sum);
	return 1;
}
