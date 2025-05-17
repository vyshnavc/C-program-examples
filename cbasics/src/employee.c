/*    Write a program to implement Employee database program using Double linked list. The database should be permanent.    
 *   Database should have members like Employee ID, age, sex, name, address, branch, designation, date of joining etc. There should be options to add, delete, modify, search, sort,print database. */

#include"../inc/employee.h"

typedef struct employee
{
	int employeeID;
	char name[100];
	int age;
	char sex[10];
	char branch[100];
	char desig[100];
	char doj[20];
	char address[100];
	struct employee *prev;
	struct employee *next;
}employee;

FILE *fp;
int file(employee **);
int filesave(employee *);
int delete(employee **,const int);
int linklist(employee *,employee **);
int database(employee **);
int name(employee **,const int);
int ID(employee **,const int);
int print(employee *);
int modify(employee **);
int datachange(employee **);
int moname(employee **);
int moID(employee **);
int countfun(employee *);
int sort(employee **);
int sortname(employee **);
int sortID(employee **);
int nodeexchange(employee **,employee *);

int r,count;

int main()
{
	employee *hptr=0;
	char c;

	do{
		r=file(&hptr);
	}while(r==0);

	while(1){       
		printf("\n=====================EMPLOYEE RECORD=======================");
		printf("\n\nA)Add employee details\nB)delete employee details\nC)modify details\nD)Search\nE)sort\nF)print employee details\nG)save details\nH)exit\nenter a option :"); 
		scanf(" %c",&c);
		system("clear");  
		if(c=='a'||c=='A'){
			do{
				r=database(&hptr);
			}while(r==0);			

		}
		else if(c=='b'||c=='B'){
			do{	
				r=delete(&hptr,0);
			}while(r==0);
		}
		else if(c=='c'||c=='C'){
			do{
				r=modify(&hptr);
			}while(r==0);
		}
		else if(c=='d'||c=='D'){
			do{
				r=delete(&hptr,2);
			}while(r==0);	
		}
		else if(c=='e'||c=='E'){

			do{
				count=countfun(hptr);	
			}while(count==0);	
			do{	
				r=sort(&hptr);
			}while(r==0);	
		}		
		else if(c=='f'||c=='F'){
			do{
				r=print(hptr);
			}while(r==0);

		}
		else if(c=='g'||c=='G'){
			do{
				r=filesave(hptr);
			}while(r==0);
		}
		else if(c=='h'||c=='H'){
			if(hptr!=0)
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
		//break;
	}
	fclose(fp);
}

int file(employee **ptr)         /*funtion is used to fetch previous contents from the file*/
{    
	if(ptr==NULL)
	{
		printf("\nsystem error occured....");
		return 0;
	}   
	fp=fopen("employee","r");
	if(fp!=NULL)
	{
		employee *temp=(employee*)malloc(sizeof(employee));
		while(fscanf(fp,"%d%s%d%s%s%s%s%[^\n]s",&temp->employeeID,temp->name,&temp->age,temp->sex,temp->branch,temp->desig,temp->doj,temp->address)!=EOF)
		{	
			do
			{
				r=linklist(temp,ptr);
			}while(r==0);      
			temp=(employee*)malloc(sizeof(employee));
		}
		free(temp);
	}
        else
        fp=fopen("employee","w");
	//        fflush(stdout);
	return 1;
}

int database(employee **ptr)      /*function is used to add new employee details to the node*/
{       
	if(ptr==NULL)
	{
		printf("\nsystem error occured..");
		return 0;
	}
	int r;
	//student *last;
	employee *temp=(employee*)malloc(sizeof(employee));
	do
	{    
		printf("\nenter employee ID : ");
		r=scanf("%d",&temp->employeeID);
		if(r!=1)
		{
			printf("\nwrong input try again..");
			scanf("%*s");
		}
	}while(r!=1);
	do
	{
		printf("\nenter employee age : ");
		r=scanf("%d",&temp->age);
		if(r!=1)
		{
			printf("\nwrong input try again..");
			scanf("%*s");
		}
	}while(r!=1);
	printf("\nenter employee name : ");
	scanf(" %[^\n]s",temp->name);
	printf("\nenter sex : ");
	scanf(" %s",temp->sex);
	printf("\nenter branch : ");
	scanf(" %[^\n]s",temp->branch);
	printf("\nenter designation : ");
	scanf(" %[^\n]s",temp->desig);
	printf("\nenter date of joining dd/mm/yr: ");
	scanf(" %[^\n]s",temp->doj);
	printf("\nenter addres : ");
	scanf(" %[^\n]s",temp->address);
	do
	{
		r=linklist(temp,ptr);
	}while(r==0);
	return 1;
}

int delete(employee **ptr,const int search)      /*delete perticular employee id */
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
		do{test=name(ptr,search);}while(test==0);
	}
	else if(test==2)
	{
		do{test=ID(ptr,search);}while(test==0);
	}
	else
	{
		printf("\nwrong choice...\n");
		delete(ptr,search);
	}
	return 1;
}

int modify(employee **ptr)
{
	if(ptr==NULL)
	{
		printf("\nsystem error occured");
		return 0;
	}
	int test;
	printf("\nenter\n1)name\n2)ID\noption : ");
	if(scanf("%d",&test)==0)
	{
		scanf("%*s");
		modify(ptr);
	}
	if(test==1)
	{
		do{test=moname(ptr);}while(test==0);
	}
	else if(test==2)
	{
		do{test=moID(ptr);}while(test==0);
	}
	else
	{
		printf("\nwrong choice...\n");
		modify(ptr);
	}
	return 1;
}

int linklist(employee *temp,employee **ptr)
{
	if(temp==NULL&&ptr==NULL)
	{
		printf("\nsystem error occured...");
		return 0;
	}

	employee *last;

	temp->next=0; 
	if(*ptr==0)
	{
		*ptr=temp;
		temp->prev=0;
		temp->next=0;
	}
	else
	{       
		last=*ptr;
		while(last->next!=0)
			last=last->next;

		last->next=temp;
		temp->next=0;
		temp->prev=last;
	}
	return 1;
}

int name(employee **ptr,const int search)
{ 
	if(ptr==NULL)
	{
		printf("\nsystem error occured..");
		return 0;
	}

	int check=0;
	char sname[50];
	employee *test=*ptr,*last,*node;

	system("clear");
	printf("\nenter the name: ");
	scanf(" %[^\n]s",sname);
	while(test!=0)
	{
		if(strcmp(test->name,sname)==0)
		{
			node=test;
			check++;
		}
		test=test->next;
	}
	if(check==1)
	{ 
		if(search==2)
		{
			printf("\n===========================================");
			printf("\n------");
			printf("\n|    | ID   : %d",node->employeeID);
			printf("\n|    | Name : %s",node->name);
			printf("\n|    | Age  : %d",node->age);
			printf("\n------ Sex  : %s",node->sex);
			printf("\n\n5)branch :%s\n6)desig  :%s\n7)doj    :%s\n8)address:%s\n ",node->branch,node->desig,node->doj,node->address);
			return 1;
		}
		test=*ptr;
		while(test!=0)
		{
			if(strcmp(test->name,sname)==0)
			{
				if(*ptr==test)
				{
					*ptr=test->next;
					test->prev=0;
					free(test);
				}
				else
				{       

					last->next=test->next;
					if(test->next!=0)
						test->next->prev=last;
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
		sleep(1);
		do{check=ID(ptr,search);}while(check==0);
	}
	else
		printf("\nname not found......");
	return 1;
}

int ID(employee **ptr,const int search)
{
	if(ptr==NULL)
	{
		printf("\nsystem error occured..");
		return 0;
	}
	int check=0,s_id;
	employee *test=*ptr,*last;
	system("clear");
	printf("\nenter the student id: ");
	scanf("%d",&s_id);
	while(test!=0)
	{
		if(test->employeeID==s_id)
		{

			if(search==2)
			{
				printf("\n===========================================");
				printf("\n------");
				printf("\n|    | ID   : %d",test->employeeID);
				printf("\n|    | Name : %s",test->name);
				printf("\n|    | Age  : %d",test->age);
				printf("\n------ Sex  : %s",test->sex);
				printf("\n\n5)branch :%s\n6)desig  :%s\n7)doj    :%s\n8)address:%s\n ",test->branch,test->desig,test->doj,test->address);
				return 1;
			}
			else if(*ptr==test)
			{
				*ptr=test->next;
				test->prev=0;
				free(test);
			}
			else
			{

				last->next=test->next;
				if(test->next!=0)
					test->next->prev=last;
				free(test);
			}
			break;
		}
		last=test;
		test=test->next;
	}
	if(check==0)
		printf("\nstudent ID not found......");
	return 1;
}

int moname(employee **ptr)
{
	if(ptr==NULL)
	{
		printf("\nsystem error occured..");
		return 0;
	}
	int check=0;
	char sname[50];
	employee *test=*ptr;
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
		//		system("clear");
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

int moID(employee **ptr)
{
	if(ptr==NULL)
	{
		printf("\nsystem error occured..");
		return 0;
	}

	int check=0,s_id;
	employee *test=*ptr;

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
		if(test->employeeID==s_id)
		{
			do{check=datachange(&test);}while(check==0);
			check=1;
			break;
		}
		test=test->next;
	}
	if(check==0)
		printf("\nstudent ID not found......");
	return 1;
}

int datachange(employee **ptr)
{
	if(ptr==NULL)
	{
		printf("\nsystem error occured..");
		return 0;
	}
	system("clear");

	int check;
	employee *test=*ptr;

	printf("\n1)ID:%d\n2)NAME:%s\n3)AGE:%d\n4)sex:%s\n5)branch:%s\n6)desig:%s\n7)address:%s\nenter a option : ",test->employeeID,test->name,test->age,test->sex,test->branch,test->desig,test->address);
	scanf("%d",&check);
	switch(check)
	{
		case 1: printf("\nenter ID : ");
			scanf("%d",&test->employeeID);
			break;
		case 2:printf("\nenter name : ");
		       scanf(" %[^\n]",test->name);
		       break;
		case 3:printf("\nenter age : ");
		       scanf("%d",&test->age);
		       break;
		case 4:printf("\nenter sex : ");
		       scanf(" %s",test->sex);
		       break;
		case 5:printf("\nenter branch : ");
		       scanf(" %[^\n]",test->branch);
		       break;
		case 6:printf("\nenter designation : ");
		       scanf(" %[^\n]",test->desig);
		       break;
		case 7:printf("\nenter address : ");
		       scanf(" %[^\n]",test->address);
		       break;
		default:printf("\nwrong choice");
			datachange(ptr);
	}
	return 1;
}

int print(employee *ptr)
{
	int filelength;
	fseek(fp,2,-2);
	filelength=ftell(fp);

	if(filelength!=0)
	{
		system("clear");
		if(ptr==NULL)
		{
			printf("\nsystem error occured..");
			return 0;
		}
		while(ptr!=0)
		{         
			printf("\n===========================================");
			printf("\n------");
			printf("\n|    | ID   : %d",ptr->employeeID);
			printf("\n|    | Name : %s",ptr->name);
			printf("\n|    | Age  : %d",ptr->age);
			printf("\n------ Sex  : %s",ptr->sex);
			printf("\n\n5)branch :%s\n6)desig  :%s\n7)doj    :%s\n8)address:%s\n ",ptr->branch,ptr->desig,ptr->doj,ptr->address);
			ptr=ptr->next;
		}
	}
	else
		printf("\ndatabase is empty...forgot to save?");
	fflush(stdout);
	return 1;
}

int filesave(employee *ptr)
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
		if(c=='y'||c=='Y')
		{
			fp=fopen("employee","w");
			while(ptr!=0)
			{
				fprintf(fp,"%d %s %d %s %s %s %s %s\n",ptr->employeeID,ptr->name,ptr->age,ptr->sex,ptr->branch,ptr->desig,ptr->doj,ptr->address);
				ptr=ptr->next;
			}
			printf("\nstudent details are stored in file..\n");
			break;
		}
		else if(c=='n'||c=='n')
			return 1;
		else 
			printf("\nwrong input");
	}
	return 1;
}

int countfun(employee *ptr)
{
	count=0;

	if(ptr==NULL)
	{
		printf("\nsystem error occured");
		return 0;
	}
	while(ptr!=0)
	{
		count++;
		ptr=ptr->next;
	}
	return count;
}

int sort(employee **ptr)
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
		do{test=sortname(ptr);}while(test==0);
	}
	else if(test==2)
	{
		do{test=sortID(ptr);}while(test==0);
	}
	else
	{
		printf("\nwrong choice...\n");
		sort(ptr);
	}
	return 1;
}

int sortID(employee **ptr)
{
	if(ptr==NULL)
	{
		printf("\nsystem error occured");
		return 0;
	}

	int i,j,check;
	employee *test,*temp;

	for(i=0;i<count;i++)
	{
		test=*ptr;
		for(j=0;j<count-i-1;j++)
		{
			if(test->employeeID>test->next->employeeID)
			{
				do
				{
					check=nodeexchange(ptr,test);
				}while(check==0);
				test=test->prev;
			}
			test=test->next;
		}
	}
}

int sortname(employee **ptr)
{
	if(ptr==NULL)
	{
		printf("\nsystem error occured");
		return 0;
	}

	int i,j,check,compare;
	employee *test,*temp;

	for(i=0;i<count;i++)
	{
		test=*ptr;
		for(j=0;j<count-i-1;j++)
		{
			compare=strcmp(test->name,test->next->name);
			printf("%d ",compare);
			if(compare==0)
			{
				if(test->employeeID>test->next->employeeID)
				{
					do
					{	
						check=nodeexchange(ptr,test);
					}while(check==0);
					test=test->prev;
				}
			}
			else if(compare>0)
			{
				do
				{
					check=nodeexchange(ptr,test);
				}while(check==0);
				test=test->prev;
			}
			else;
			test=test->next;
		}
	}
}

int nodeexchange(employee **ptr,employee *test)
{
	if(ptr==NULL&&test==NULL)
	{
		printf("\nsystem error occured");
		return 0;
	}

	employee *temp;
	temp=test->prev;

	if(test->prev!=0)
		test->prev->next=test->next;
	test->next->prev=temp;
	test->prev=test->next;
	temp=test->next->next;
	test->next->next=test;
	test->next=temp;
	if(*ptr==test)
		*ptr=test->prev;
}












