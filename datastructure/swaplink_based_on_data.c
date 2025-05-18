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

void swap(ST **ptr,int x,int y)
{

    ST *prevx = NULL,*curx = *ptr;
    while(curx && curx->data != x )
    {
        prevx = curx;
        curx = curx->next;
    }
    ST *prevy = NULL,*cury = *ptr;
    while(cury && cury->data != y)
    {
        prevy = cury;
        cury = cury->next;
    }

    if(curx == NULL || cury == NULL)
        return;

    if(prevx != NULL)
    {
        prevx->next = cury;
    }
    else
        *ptr = cury;

    if(prevy != NULL)
    {
        prevy->next = curx;
    }
    else
        *ptr = curx;

    ST *temp = cury->next;
    cury->next = curx->next;
    curx->next = temp;

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
    printf("\nenter the numbers to swap : ");
    scanf("%d %d",&x,&y);
    swap(&hptr,x,y);
    print(hptr);
}

