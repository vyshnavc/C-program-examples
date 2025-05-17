/*write function to add two 2D arrays of variable dimension (dimension to be taken from user). Function should catch 1st array using pointer to array and 2nd using array of pointers.
  Print the resultant array using user defined printf() function which catches 2D array using double pointer. */

#include"../inc/matrixsum.h"

int **my_calloc(int ,int );
int sum(int **,int **,int **,int ,int );
int display(int **,int ,int );
int pointer_to_array(int **,int ,int );
int array_of_pointer(int **,int ,int );

int main()
{
	int **p1=0,**p2=0,**p3=0,check,r=0,c=0,r1=0,c1=0;


	while(1)
	{

		while(1)
		{
			printf("\nEnter the rows and column for matrix1:\n\n");
			check=scanf("%d%d",&r,&c);
			if(check!=2)
			{
				scanf("%*s");
				printf("\n\nprovide numbers...\n\n");
				continue;     
			}
			if(r<0||c<0)
			{
				printf("\nprovide postive numbers...");
				continue;
			}
			printf("row1=%d col1=%d\n\n",r,c);  
			printf(".............................................\n\n");
			break;
		}
		while(1)
		{
			printf("Enter the rows and column matrix2:\n\n");
			check=scanf("%d%d",&r1,&c1);
			if(check!=2)
			{
				printf("\n\nprovide numbers....\n\n");
				scanf("%*s");
				continue;
			}
			if(r1<0||c<0)
			{
				printf("\nprovide postive numbers...");
				continue;
			}
			printf("row2=%d col2=%d\n\n",r1,c1);  
			printf(".............................................\n\n");

			if(r == r1 && c==c1)
			{
                               p1=my_calloc(r,c);
                               p2=my_calloc(r,c);
                               p3=my_calloc(r,c);

				pointer_to_array(p1,r,c);
				array_of_pointer(p2,r,c);

				do
				{
					check=sum(p1,p2,p3,r,c);
				}while(check==0);			
                                system("clear");
				printf(".............................................\n");
				printf("\n\n");
                                 
				for(int i=0;i<r;i++)
				{
					printf("\t|");
					for(int j=0;j<c;j++)
						printf(" %d ",p1[i][j]);
					printf("|\n");
				}
				printf("\t  __|__\n");
				printf("\t    |  \n");
				printf("\n\n");
				for(int i=0;i<r;i++)
				{
					printf("\t|");
					for(int j=0;j<c;j++)
						printf(" %d ",p2[i][j]);
					printf("|\n");
				}

				printf("=============================================\n\n");
				printf("\n\n");

				for(int i=0;i<r;i++)
				{
					printf("\t|");
					for(int j=0;j<c;j++)
						printf(" %d ",p3[i][j]);
					printf("|\n");
				}
				break;
			}
                        else
                        {
			printf("wrong input..\nmake sure your two matrix row and coloumn are matching....\n\n");
			continue;
                        }
		}
        
	}
}


int **my_calloc(int r,int c)  /*funtion is used to allocate memory dynamically using calloc so by default zero will assigned*/
{
	int **p;
	p=calloc(r,sizeof(int*));
	for(int i=0;i<r;i++)
		p[i]=calloc(c,sizeof(int));

return p;
}

int pointer_to_array(int **p,int r, int c)
{
	int check,i,j;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		{
			system("clear");
			display(p,r,c);
			do
			{
				printf("\nEnter the data : ");
				check=scanf("%d",&p[i][j]);
				if(check==0)
				{
					printf("\nwrong input...");
					scanf("%*s");
				}
			}while(check==0);
		}
}

int array_of_pointer(int *p[],int r,int c)
{
	int check,i,j;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		{
			system("clear");
			display(p,r,c);
			do
			{
				printf("\nEnter the data : ");
				check=scanf("%d",&p[i][j]);
				if(check==0)
				{
					printf("\nwrong input...");
					scanf("%*s");
				}
			}while(check==0);
		}
}

int sum(int **p1,int **p2,int **p3,int r,int c) /*add two matrix*/
{
	int i,j;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			p3[i][j]=p1[i][j]+p2[i][j];
}

int display(int **p,int r,int c)
{
	for(int count=0;count<r;count++)
	{
		for(int count1=0;count1<c;count1++)
		{
			printf("%d  ",p[count][count1]);
		}
		printf("\n");
	}
}

