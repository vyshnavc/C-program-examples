/*write program for an automatic SIM card details verification. The database will contain name , ID proof, sim ID no, address etc.
 * Not more than 3 SIM card should be given on on ID proof. This should work for any state (with one being the home state).
 * Persons with ID proof outside home state, need to give local reference person's mobile no.
 */

#include"../inc/simcard.h"

#define size 100
#define NUM_MIN 1000000000
#define NUM_MAX 10000000000

struct sim
{
	char name[size];
	int age;
	int id;
	long int simid[6];
        char state[size];		
	char address[size];
};


char state[size]="kerala";
int adhar(struct sim *); 

int simcard(struct sim *,int);
int localguy(struct sim *,int);

struct sim database[3]={{"vyshnav",23,555,{0,0,0,0,0,0},"kerala","aaa bbb ccc"},{"arjun",22,666,{0,0,0,0,0,0},"tamilnadu","bbb sss ccc"},{"arun",24,777,{0,0,0,0,0,0},"ahmedabad","bbb nnn ccc"}};

void main()
{
	while(1)
	{
		system("clear");
		printf("\n=======================================");
		printf("\n=========SIMCARD verification==========");
		printf("\n=======================================");
		adhar(database);
	}
}

int adhar(struct sim *data)
{
	int check,num,i;

	do
	{
		printf("\nenter adhar card number : ");
		check=scanf("%d",&num);
		if(check==0)
		{
			printf("\nwrong input..");
			scanf("%*s");
		}
	}while(check==0);
	for(i=0;i<3;i++)
	{
		if(data[i].id==num)
		{
			do
			{
				check=simcard(data,i);
			}while(check==0);
			check=0;
                        break;
		}
	}
	if(check!=0)
	{
		printf("\nplease enter a valied adhar number..");
                adhar(data);
	}
	return 1;
}

int simcard(struct sim *data,int i)
{
	int check,j;
	long int num;
        char option;

        system("clear");
	printf("\n--------");
	printf("\n|      |  Name : %s",data[i].name);
	printf("\n|      |  age  : %d",data[i].age);
	printf("\n|      |");
	printf("\n--------");
	printf("\nAdhar no : %d",data[i].id);
	printf("\nstate    : %s",data[i].state);
	printf("\nAddress  : %s",data[i].address);
	printf("\n\n");
	if(strcmp(data[i].state,state)!=0)
	{
		printf("\nyou seems like  other state.you need to enter local reference person mobile number..");
		while(1)
		{
			printf("\nyou want to continue y/n?");
			scanf(" %c",&option);
			if(option=='y'||option=='Y')
			{ 	
			     do{check=localguy(data,i);}while(check==0);
				break;
			}
			else if(option=='n'||option=='N')
				return 1;          
			else 
				printf("\nwrong inpuy..");
		}
                if(check==2)
                return 1;
	}
	do
	{
		printf("\nenter verfication sim number : ");
		check=scanf("%ld",&num);
		if(check==0)
		{
			printf("\nplease enter a valied number");
			scanf("%*s");
			check=0;
			continue;
		}
		if(num<NUM_MIN||num>NUM_MAX)
		{
			printf("\nplease enter a valied number");
			check=0;
		}
	}while(check==0);
	for(j=0;j<3;j++)
	{
		if(data[i].simid[j]==0)
		{
			data[i].simid[j]=num;
			printf("\nnumber verified successfullyyy...");
			check=0;
			break;
		}
	}
	if(check!=0)
	{
		printf("\nyou have exceeded sim limit...\n");
	}
	fflush(stdout);
        sleep(2);
	return 1;
}  

int localguy(struct sim *data,int i)
{

int check,j;
long int num;

        do
        {
                printf("\nenter reference sim number : ");
                check=scanf("%ld",&num);
                if(check==0)
                {
                        printf("\nplease enter a valied number");
                        scanf("%*s");
                        check=0;
                        continue;
                }
                if(num<NUM_MIN||num>NUM_MAX)
                {
                        printf("\nplease enter a valied number");
                        check=0;
                }
        }while(check==0);

        for(j=3;j<6;j++)
        {
                if(data[i].simid[j]==0)
                {
                        data[i].simid[j]=num;
                        printf("\nreference number verified successfullyyy...");
                        check=0;
                        break;
                }
        }

        if(check!=0)
        {
                printf("\nyou have exceeded sim limit...\n");
                fflush(stdout);
                sleep(2);
                return 2;
        } 
                
return 1;
}














