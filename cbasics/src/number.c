/*write a program that will accept decimal number and will convert into binary and hexa*/
#include"../inc/number.h"

void binary(int);
void hexa(int);

void main()
{
	int number,option,check=0;;

	do{
		printf("\nenter a number : ");
		check=scanf("%d",&number);
		if(check==0){
			printf("\nwrong choice..");
			scanf("%*s");
		}
	}while(check!=1);

	while(1){
		printf("\n1)binary convertion\n2)hexa convertion\nenter an option : ");
		check=scanf("%d",&option);
		if(check==0){
			printf("\nwrong choice..");
			scanf("%*s");
			continue;
		}	
		switch(option)
		{
			case 1 :binary(number);
				break;
			case 2 :hexa(number);
				break;
			default:printf("wrong choice try again..");
		}
		break;
	}
}

void binary(int number)
{

	int i;

	printf("binary of number %d is : ",number);
	for(i=31;i>=0;i--)
	{
		if(number>>i&1)
			printf("%d",1);
		else
			printf("%d",0);
	}
	printf("\n");
}

void hexa(int number)
{

	int i=0,rem[20];
	char hex[6]={'F','E','D','C','B','A'};

	while(number)
	{
		rem[i]=number%16;
		number=number/16;
		i++;
	}

	for(--i;i>=0;i--)
	{
		if(rem[i]<10)
			printf("%d",rem[i]);
		else
			printf("%c",hex[15-rem[i]]);
	}
	printf("\n");
}































