#include <stdio.h>
#include <stdlib.h>

typedef struct st{
	int rollno;
	struct st *next;
}ST;

int add_end(ST **ptr)
{

	ST * temp;

	temp = (ST *)malloc (sizeof(ST));


	printf("Enter the rollno: ");
	scanf("%d", &temp->rollno);

	if (*ptr == 0)
	{
		temp->next = (*ptr);
		*ptr = temp;
	} else {
		ST *last = (*ptr);

		while(last->next)
			last = last->next;

		temp->next = last->next;
		last->next = temp;
	}
}

int print_node(ST *ptr)
{

	while(ptr) {
		printf("%d ", ptr->rollno);
		ptr = ptr->next;
	}
	printf("\n\n");
}

int reverse_link(ST **ptr)
{
	static ST *r = 0, *q = 0;

	if (*ptr) {

		r = q;
		q = (*ptr);
		(*ptr) = (*ptr)->next;
		q->next = r;
		reverse_link(ptr);
	} else {
		*ptr = q;
	}
}

int main()
{

	ST *hptr = 0;
	char ch;

	do {
		add_end(&hptr);
		printf("would you like to add more data(y/n): ");
		scanf(" %c", &ch);
	} while(ch == 'Y' || ch == 'y');


	print_node(hptr);
	reverse_link(&hptr);
	print_node(hptr);
}
