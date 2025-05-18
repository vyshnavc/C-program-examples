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

void pair_swap(ST **ptr)
{

    int temp_num;
    ST *temp = *ptr;
    while(temp && temp->next != NULL)
    {
        temp_num = temp->data;
        temp->data = temp->next->data;
        temp->next->data = temp_num;
        temp = temp->next->next;
    }
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
    pair_swap(&hptr);
    print(hptr);
}

