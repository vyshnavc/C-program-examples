/*5. Reverse a single link list*/
#include"../inc/rsinglelink.h"

typedef struct data
{
	int x;
	struct data *next;
}st;

void add(st **);
void reverse(st **);
void print(st *);

void main()
{
	st *hptr=0;
	char c;
	do
	{
		add(&hptr);
		printf("\ncontinue y?");
		scanf(" %c",&c);
	}
	while(c=='y'||c=='Y');
        reverse(&hptr);
        print(hptr);
}

void add(st **ptr)
{
	st *temp=(st*)malloc(sizeof(st));
	printf("\nenter number : ");
	scanf("%d",&temp->x);
	st *last;

	temp->next=0;

	if(*ptr==0)
	{
		*ptr=temp;
	}
	else
	{
		last=*ptr;

		while(last->next!=0)
		{       last=last->next;
		}
		last->next=temp;
	}
}

void reverse(st **ptr)
{
	static st *q=0,*r;

	if(*ptr==0)
	{
		*ptr=q;
		return;
	}

	r=q;
	q=*ptr;
	*ptr=(*ptr)->next;
	q->next=r;
	reverse(ptr);
}

void print(st *ptr)
{
	while(ptr!=0)
	{
		printf("%d",ptr->x);
		ptr=ptr->next;
	}
}











