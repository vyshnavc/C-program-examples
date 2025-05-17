/* Write a program to accepts name and arrival time of 5 trains and display the name with railway time format (2PM is written as 14:00). The information must be entered by the user. */

#include"../inc/train.h"

#define size 50
#define count 5

typedef struct train
{
	char train[size];
	int hr;
	int min;
	int sec;
	char ampm[count];
}trai;

int trainname(int ,trai *);
int traintime(int ,trai *);
int ampm(int ,trai *);
int trainprint(trai *);

void main()
{
	int i,j,nullcheck;
	trai t[count];

	system("sl");                    /*sudo apt-get install sl*/

	for(i=0;i<count;i++)
	{
		printf("................TRAIN TIME...................\n");
		system("clear");
		do{nullcheck=trainname(i,t);}while(nullcheck==0);
		do{nullcheck=traintime(i,t);}while(nullcheck==0);
		do{nullcheck=ampm(i,t);}while(nullcheck==0);
	}
	trainprint(t);
}

int trainname(int j,trai *train)
{
	if(train==NULL)
	{
		printf("\nsystem error occured");
		return 0;
	}
	printf("\nenter train %d name : ",j+1);
	scanf("  %[^\n]s",train[j].train);
	return 1;
}

int traintime(int j,trai *train )
{      
	int r;

	if(train==NULL)
	{
		printf("\nsystem error occured");
		return 0;
	}
	printf("\nHr Mn Sec : ");
	r=scanf("%d%d%d",&train[j].hr,&train[j].min,&train[j].sec);
	if(r!=3)
	{
		printf("\nsomthing you entered wrong plese check the format : 00 00 00\n");
		printf("\n.............................................\n");
		scanf("%*s%*s%*s");
		traintime(j,train);
	} 
	else if((train[j].hr>13||train[j].hr<0)||(train[j].min>60||train[j].min<0)||(train[j].sec>60||train[j].sec<0))  /*will check numbers other than time format*/
	{
		printf("\nsomthing you entered wrong plese check the format : 00 00 00 \n");
		printf("\n.............................................\n");
		traintime(j,train);
	}
return 1;
}

int ampm(int j,trai *train)
{
	if(train==NULL)
	{
		printf("\nsystem error occured");
		return 0;
	}
	printf("\nenter am or pm : ");
	scanf(" %s",train[j].ampm);
return 1;
}

int trainprint(trai *train)
{
	if(train==NULL)
	{
		printf("\nsystem error occured");
		return 0;
	}

	int i;

	for(i=0;i<count;i++)
	{
		printf("\n======================================================");
		if((strcmp("am",train[i].ampm)==0)||(strcmp("AM",train[i].ampm)==0))     /*if it is pm it will convert to 24 hr format by adding 12*/
			printf("\ntrain name : %s   train time : %d:%d:%d  %s",train[i].train,train[i].hr,train[i].min,train[i].sec,train[i].ampm);
		else
		{
			printf("\ntrain name : %s   train time : %d:%d:%d",train[i].train,train[i].hr+12,train[i].min,train[i].sec);
		}
	}
return 1;
}

