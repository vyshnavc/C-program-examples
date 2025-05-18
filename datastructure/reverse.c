#include<stdio.h>
#include<stdlib.h>

typedef struct data{
    int data;
    struct data *next;
}ST;

void insert(ST **ptr,int x)
{
    ST *temp = (ST*)malloc(sizeof(ST));
    temp->data = x;

    temp->next = *ptr;
    *ptr = temp;
}
void print(ST *ptr)
{
    printf("DATA : \n");
    while(ptr)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;

    }
}

void reverse(ST **ptr)
{

    int temp_num;
    ST *current = *ptr, *prev = NULL,*next = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *ptr = prev; 

}

void main()
{
    int x,y,data;
    ST *hptr = NULL;
    for(int i = 0; i<5; i++){
        printf("\nenter data : ");
        scanf("%d",&data);
        insert(&hptr,data);
    }
    print(hptr);
    reverse(&hptr);
    print(hptr);
}

