/*Write a program  to accept and store student data base. The database should consist of any 4 attributes of a student.  User must be able to access the student details by entering the name/roll no. The database must be stored some where so that it may accessed at anytime (even after the program is quit). The data base should have the functionality to :
        1) add student data
        2) Delete an existing data
        3) Modify any existing data.
*/

#include"../inc/studentdatabase.h"

#define size 100

typedef struct student
{
	int studentID;
	char name[size];
	char address[size];
	char class[size];
	int age;
	char sex[size];
	struct student *next;
}student;

FILE *fp;
int file(student **);
int filesave(student *);
int delete(student **);
int linklist(student *,student **);
int database(student **);
int name(student **);
int ID(student **);
int print(student *);
int modify(student **);
int datachange(student **);
int moname(student **);
int moID(student **);

int r;

void main()
{
	student *hptr=0;
	char c;
	do
	{
		r=file(&hptr);
	}while(r==0);
        printf("\n=====================STUDENT RECORD=======================");
	while(1)
	{       

		printf("\nA)Add student details\nB)delete student details\nc)modify details\nD)print student details\nE)save details\nX)exit\nenter a option : ");
		scanf(" %c",&c);
		system("clear");
		if(c=='a'||c=='A')
		{
			do
			{
				r=database(&hptr);
			}while(r==0);			

		}
		else if(c=='b'||c=='B')
		{
			do
			{	
				r=delete(&hptr);
			}while(r==0);
		}
		else if(c=='c'||c=='C')
		{
			do
			{
				r=modify(&hptr);
			}while(r==0);
		}
		else if(c=='d'||c=='D')
		{
			do
			{	
				r=print(hptr);
			}while(r==0);	

		}
                else if(c=='E'||c=='e')
                {
                    do
                     {
                       r==filesave(hptr);
                     }while(r==0);		
                }
		else if(c=='x'||c=='X')
		{
			do
			{
				r=filesave(hptr);
			}while(r==0);
			break;
		}
		else
		{
			printf("\nwrong choice...try again");
			continue;
		}
		sleep(1);
	}
	fclose(fp);
}
int file(student **ptr)       /*adding file data's into program*/
{    
	if(ptr==NULL)
	{
		printf("\nsystem error occured....");
		return 0;
	}   
	fp=fopen("memory","r");
	if(fp!=NULL)
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
		free(temp);
	}
	return 1;
}
int database(student **ptr)                     /*fucton is used to add student details*/
{       
	if(ptr==NULL)
	{
		printf("\nsystem error occured..");
		return 0;
	}
	int r;
	student *temp=(student*)malloc(sizeof(student));
        do
        {    
   	printf("\nenter student ID : ");
	r=scanf("%d",&temp->studentID);                        
	if(r!=1)
	{
		printf("\nwrong input try again..");
		scanf("%*s");
	}
        }while(r!=1);
	do
        {
        printf("\nenter student age : ");
	r=scanf("%d",&temp->age);
	if(r!=1)
	{
		printf("\nwrong input try again..");
		scanf("%*s");
	}
        }while(r!=1);
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
	return 1;
}
int delete(student **ptr)
{
	if(ptr==NULL)
	{
		printf("\nsystem error occured");
		return 0;
	}
	int test,check;
	do
        {
        printf("\nusing\n1)name\n2)ID\noption : ");
        check=scanf("%d",&test);
	if(check==0)
        {
                printf("\nwrong chioce...");
		scanf("%*s");
        }
        }while(check==0);

	if(test==1)
	{
		do{test=name(ptr);}while(test==0);
                printf("\nstudent details deleted.....");
	}
	else if(test==2)
	{
		do{test=ID(ptr);}while(test==0);
                printf("\nstudent details deleted.....");
	}
	else
	{
		printf("\nwrong choice...\n");
		delete(ptr);
	}
	return 1;
}
int modify(student **ptr)
{
	if(ptr==NULL)
	{
		printf("\nsystem error occured");
		return 0;
	}
	int test,check;
	do
        {
        printf("\nenter\n1)name\n2)ID\noption : ");
	check=scanf("%d",&test);
        if(check==0)
	{
                printf("\nwrong choice....");
		scanf("%*s");
	
	}
        }while(check==0);
	if(test==1)
	{
		do{test=moname(ptr);}while(test==0);               
                printf("\nstudent details updated.....");
	}
	else if(test==2)
	{
		do{test=moID(ptr);}while(test==0);
                printf("\nstudent details updated....");
	}
	else
	{
		printf("\nwrong choice...\n");
		modify(ptr);
	}
	return 1;
}
int linklist(student *temp,student **ptr)                        /*funtion will make datas in linklist format*/
{
	if(temp==NULL&&ptr==NULL)
	{
		printf("\nsystem error occured...");
		return 0;
	}
	student *last;
	temp->next=0; 
	if(*ptr==0)
	{
		*ptr=temp;}
	else
	{       
	
		last=*ptr;
		while(last->next!=0)
		{	
                   last=last->next;		
		}
		last->next=temp;
	}
	return 1;
}
int name(student **ptr)                             
{ 
	if(ptr==NULL)
	{
		printf("\nsystem error occured..");
		return 0;
	}
	int check=0;
	char sname[50];
	student *test=*ptr,*last;
	printf("\nenter the name: ");
	scanf(" %[^\n]s",sname);
	while(test!=0)
	{
		if(strcmp(test->name,sname)==0)  /* to check repeatation of given name */
		{
			check++;
		}
		test=test->next;
	}
	if(check==1)
	{ 
		test=*ptr;
		while(test!=0)
		{
			if(strcmp(test->name,sname)==0)
			{
				if(*ptr==test)
				{
					*ptr=test;
					free(test);
				}
				else
				{
					last->next=test->next;
					free(test);
				}
				break;
			}
			last=test;
			test=test->next;
		}
	}
	else if(check>=2)
	{
		printf("\nThere are more number of %s\n",sname);
		do{check=ID(ptr);}while(check==0);
	}
	else
		printf("\nname not found......");
	return 1;
}
int ID(student **ptr)
{
	if(ptr==NULL)
	{
		printf("\nsystem error occured..");
		return 0;
	}
	int check=0,s_id;
	student *test=*ptr,*last;
	do
        {
        printf("\nenter the student id: ");
	check=scanf("%d",&s_id);
        if(check==0)
        {
                printf("\nwrong choice....");
                scanf("%*s");

        }
        }while(check==0);
        check=0;
	while(test!=0)
	{
		if(test->studentID==s_id)
		{
			if(*ptr==test)
			{ 
				*ptr=test;
				free(test);
			}
			else
			{
				last->next=test->next;
				free(test);
			}
			check=1;
                        break;
		}
		last=test;
		test=test->next;
	}
	if(check==0)
		printf("\nstudent ID not found......");
	return 1;
}
int moname(student **ptr)         
{
	if(ptr==NULL)
	{
		printf("\nsystem error occured..");
		return 0;
	}
	int check=0;
	char sname[50];
	student *test=*ptr;
	printf("\nenter the name: ");
	scanf(" %[^\n]s",sname);
	while(test!=0)
	{
		if(strcmp(test->name,sname)==0)
		{
			check++;
		}
		test=test->next;
	}
	if(check==1)
	{
		test=*ptr;
		while(test!=0)
		{
			if(strcmp(test->name,sname)==0)
			{
				datachange(&test);
				break;
			}
		test=test->next;

		}
	}
	else if(check>=2)
	{
		printf("\nThere are more number of %s\n",sname);
		do{check=moID(ptr);}while(check==0);
	}
	else
	printf("\nname not found......");
return 1;
}
int moID(student **ptr)
{
	if(ptr==NULL)
	{
		printf("\nsystem error occured..");
		return 0;
	}
	int check=0,s_id;
	student *test=*ptr;
       do
       {
	printf("\nenter the student id: ");
	check=scanf("%d",&s_id);
        if(check==0)
         {
          printf("\nwrong input..");
          scanf("%*s");
          }
        }while(check==0);
        check=0;
        while(test!=0)
	{
		if(test->studentID==s_id)
		{
			datachange(&test);
			check=1;
			break;
		}
		test=test->next;
	}
	if(check==0)
		printf("\nstudent ID not found......");
return 1;
}
int datachange(student **ptr)
{
	system("clear");
	int check;
	student *test=*ptr;
	printf("\n1)ID:%d\n2)NAME:%s\n3)AGE:%d\n4)ADDRESS:%s\n5)CLASS:%s\n6)SEX:%s\nenter a option : ",test->studentID,test->name,test->age,test->address,test->class,test->sex);
	scanf("%d",&check);
	switch(check)
	{
		case 1: printf("\nenter ID : ");
			scanf("%d",&test->studentID);
			break;
		case 2:printf("\nenter name : ");
		       scanf(" %[^\n]",test->name);
		       break;
		case 3:printf("\nenter age : ");
		       scanf("%d",&test->age);
		       break;
		case 4:printf("\nenter address : ");
		       scanf(" %[^\n]",test->address);
		       break;
		case 5:printf("\nenter class : ");
		       scanf(" %[^\n]",test->class);
		       break;
		case 6:printf("\nenter sex : ");
		       scanf(" %[^\n]",test->sex);
		       break;
		default:printf("\nwrong choice");
			datachange(ptr);
	}
}
int print(student *ptr)
{
	if(ptr==NULL)
	{
		printf("\nsystem error occured.");
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
int filesave(student *ptr)
{
	
	if(ptr==NULL)
	{
		printf("\nsystem error occured ");
		return 0;
	}
	char c;
	while(1)
	{
		printf("\ndo you want to save the data for future reference..y/n : ");
		scanf(" %c",&c);
	        fp=fopen("memory","w");
		if(c=='y'||c=='Y')
		{
			while(ptr!=0)
			{
				fprintf(fp,"%d %s %d %s %s %s\n",ptr->studentID,ptr->name,ptr->age,ptr->sex,ptr->class,ptr->address);
				ptr=ptr->next;
			}
			printf("\nstudent details are stored in file..\n");
			break;
		}
		else if(c=='n'||c=='N')
			return 1;
		else
			printf("\nwrong input");
	}
	sleep(2);
	return 1;
}
