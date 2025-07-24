//Find the linked list is palindrom or not

#include <stdio.h>
#include <stdlib.h>
typedef struct data{
    int x;
    struct data *next;
}ListNode;

void input(ListNode **ptr,int data)
{
    ListNode *temp= (ListNode*)malloc(sizeof(ListNode));
    
    temp->x=data;
    temp->next = *ptr;
    *ptr = temp;
}

void print(ListNode *ptr)
{
    ListNode *temp = ptr;
    
    printf("\nData\n");
    while(temp!=NULL)
    {
        printf("%d ",temp->x);
        temp=temp->next;
    }
}

ListNode *reverse(ListNode **ptr)
{
    ListNode *prev=NULL;
    ListNode *curn=*ptr;
    ListNode *next=NULL;
    
    while(curn != NULL)
    {
       next = curn->next;
       curn->next=prev;
       prev=curn;
       curn=next;
    }
    return prev;
}

int palindrom(ListNode **ptr)
{
    ListNode *fast=*ptr;
    ListNode *slow=*ptr;
    ListNode *node2=NULL;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    printf("\nMiddle Num %d",slow->x);
    
    slow = reverse(&slow);
    #if 0
    printf("\nnode2\n");
    while(slow != NULL)
    {
        printf("%d ",slow->x);
        slow=slow->next;
    }
    #endif
    
    fast=*ptr;
    while(slow!=NULL)
    {
        if(fast->x == slow->x){
            fast=fast->next;
            slow=slow->next;
        }else
         return 0;
    }
    return 1;
}

int main() {
    ListNode *head=NULL;
    
    input(&head,1);
    input(&head,2);
    input(&head,3);
    input(&head,3);
    input(&head,2);
    input(&head,1);
    
    print(head);
    
    printf("\nChecking data is palindrom or not\n");

    palindrom(&head)?printf("\nit is palindrom\n"):printf("\nits not\n");
    
    return 0;
}
