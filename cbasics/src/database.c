/**
 * * Advance C assignment question 2.
 * * Write a program to create a student database.
 * * The fields in the database will be Student ID, name, address, class, age, sex etc.The number of entries are variable also the fields name & address are char , which needs to be allocated dynamically as per the number of characters needed.
 * * Then the user should be able to find the details of any particular student based on the ID/name while quitting the program save the data base, and it should be loaded the 
 * next time the program is executed.
 */ 
#include"../inc/student.h"
typedef struct student
{
	int studentID;
	char name[100];
	char address[100];
	char class[100];
	int age;
	char sex[100];
	struct student *next;
}student;
FILE *fp;
int file(student **);
int linklist(student *,student **);
int database(student **);
int searchbyname(student *);
int searchbyID(student *);
int print(student *);
int r;
void main()
{
	student *hptr=0;
	char c;
	do
	{
		r=file(&hptr);
	}while(r==0);
	while(1)
	{       
		printf("\n====================student data base===================");
		//		system("clear");
		r=database(&hptr);
		if(r==0)
			continue;
		printf("\ndo you want to continue y/n : ");
		scanf(" %c",&c);
		fflush(stdout);
		if(c=='n'||c=='N')
			break;
	}
	while(1)
	{       

		printf("\nsearching method.....\nA)using name\nB)using student ID\nX)print all and exit\nenter a option : ");
		scanf(" %c",&c);
		system("clear");
		if(c=='a'||c=='A')
		{
			do
			{
				r=searchbyname(hptr);
			}while(r==0);			

		}
		else if(c=='b'||c=='B')
		{
			do
			{	
				r=searchbyID(hptr);
			}while(r==0);
		}
		else if(c=='x'||c=='X')
		{
			do
			{	
				r=print(hptr);
			}while(r==0);	

			break;
		}		
		else
		{
			printf("\nwrong choice...try again");
			continue;
		}
		sleep(2);
		//break;
	}
	fclose(fp);
}
int file(student **ptr)
{    
	if(ptr==NULL)
	{
		printf("\nsystem error occured....");
		return 0;
	}   
	char option;
	student st;
	fp=fopen("memory","r");
	if(fp!=NULL)
	{
		while(1)
		{
			printf("\nprevious datas are available...\nA)append the file\nB)overwrite the file\nC)print the data and continue with new data\nenter an option : ");
			scanf(" %c",&option);
			if(option=='a'||option=='A')
			{      
				student *temp=(student*)malloc(sizeof(student));
				while(fscanf(fp,"%d%s%d%s%s%[^\n]s",&temp->studentID,temp->name,&temp->age,temp->sex,temp->class,temp->address)!=EOF)
				{	
					do
					{
						r=linklist(temp,ptr);
					}while(r==0);      
					temp=(student*)malloc(sizeof(student));
				}
				fp=fopen("memory","a");
				free(temp);
			}
			else if(option=='b'||option=='B')
				fp=fopen("memory","w");
			else if(option=='c'||option=='C')
			{
				while(fscanf(fp,"%d %s %d %s %s %[^\n]s\n",&st.studentID,st.name,&st.age,st.sex,st.class,st.address)!=EOF)
					printf("\nID:%d\nNAME:%s\nAGE:%d\nADDRESS:%s\nCLASS:%s\nSEX:%s\n",st.studentID,st.name,st.age,st.address,st.class,st.sex);
				fp=fopen("memory","w");
			}
			else
			{
				printf("\nwrong input");
				continue;
			}
			break;
		}
	}
	else
	{
		fp=fopen("memory","w");
	}
	return 1;
}
int database(student **ptr)
{       
	if(ptr==NULL)
	{
		printf("\nsystem error occured..");
		return 0;
	}
	int r,r1;
	//student *last;
	student *temp=(student*)malloc(sizeof(student));
	printf("\nenter student ID : ");
	r=scanf("%d",&temp->studentID);
	if(r!=1)
	{
		printf("\nwrong input try again..");
		scanf("%*s");
		free(temp);
		database(ptr);
	}
	printf("\nenter student age : ");
	r1=scanf("%d",&temp->age);
	if(r1!=1)
	{
		printf("\nwrong input try again..");
		scanf("%*s");
		free(temp);
		database(ptr);
	}
	printf("\nenter student name : ");
	scanf(" %[^\n]s",temp->name);
	printf("\nenter student address : ");
	scanf(" %[^\n]s",temp->address);
	printf("\nenter student class : ");
	scanf(" %s",temp->class);
	printf("\nenter sex - male/female : ");
	scanf(" %s",temp->sex);
	do
	{
		r=linklist(temp,ptr);
	}while(r==0);
	fprintf(fp,"%d %s %d %s %s %s\n",temp->studentID,temp->name,temp->age,temp->sex,temp->class,temp->address);
	return 1;
}
int linklist(student *temp,student **ptr)
{
	if(temp==NULL&&ptr==NULL)
	{
		printf("\nsystem error occured...");
		return 0;
	}
	student *last;
	temp->next=0; 
	if(*ptr==0)
	{//  printf("1:%d%s%d%s%s%s\n",temp->studentID,temp->name,temp->age,temp->sex,temp->class,temp->address);
		*ptr=temp;}
	else
	{       
		//	printf("2:%d%s%d%s%s%s\n",temp->studentID,temp->name,temp->age,temp->sex,temp->class,temp->address);
		last=*ptr;
		while(last->next!=0)
		{	last=last->next;
			//printf("3:%d%s%d%s%s%s\n",temp->studentID,temp->name,temp->age,temp->sex,temp->class,temp->address);
		}
		last->next=temp;
	}
	return 1;
}
int searchbyname(student *name)
{ 
	if(name==NULL)
	{
		printf("\nsystem error occured..");
		return 0;
	}

	int check=0;
	char sname[50];
	student *test=name;
	printf("\nenter the name: ");
	scanf(" %[^\n]s",sname);
	while(test!=0)
	{
		if(strcmp(test->name,sname)==0)
		{
			check=1;
			printf("\nID:%d\nNAME:%s\nAGE:%d\nADDRESS:%s\nCLASS:%s\nSEX:%s\n",test->studentID,test->name,test->age,test->address,test->class,test->sex);		}
		test=test->next;
	}
	if(check==0)
		printf("\nname not found......");
	return 1;
}
int searchbyID(student *ID)
{
	if(ID==NULL)
	{
		printf("\nsystem error occured..");
		return 0;
	}
	int check=0,s_id;
	student *test=ID;
	printf("\nenter the student id: ");
	scanf("%d",&s_id);
	while(test!=0)
	{
		if(test->studentID==s_id)
		{
			check=1;
			printf("\nID:%d\nNAME:%s\nAGE:%d\nADDRESS:%s\nCLASS:%s\nSEX:%s\n",test->studentID,test->name,test->age,test->address,test->class,test->sex);
		}
		test=test->next;
	}
	if(check==0)
		printf("\nstudent ID not found......");
	return 1;
}
int print(student *ptr)
{
	if(ptr==NULL)
	{
		printf("\nsystem error occured..");
		return 0;
	}
	while(ptr!=0)
	{         
		printf("\n===========================================");
		printf("\nID:%d\nNAME:%s\nAGE:%d\nADDRESS:%s\nCLASS:%s\nSEX:%s\n",ptr->studentID,ptr->name,ptr->age,ptr->address,ptr->class,ptr->sex);
		ptr=ptr->next;
	}
	return 1;
}

