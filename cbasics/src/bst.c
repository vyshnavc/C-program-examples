/*Implement a binary seacrh tree to find a particular word from an array of 50 names.*/

#include"../inc/bst.h"

struct node 
{ 
	char name[50]; 
	struct node *left, *right; 
}; 

struct node* insert(struct node*, char *); 
struct node *newNode(char *); 
struct node* search(struct node* , char *); 

int main() 
{ 
	struct node *root = NULL,*searchnode = NULL; 
	char name[50],option;

	do{
		printf("\n==========BINARY SEARCH TREE==========");
		printf("\n\nenter a name : ");
		scanf(" %[^\n]s",name);
		if(root==NULL){
			root=insert(root,name);
			printf("\nname added as root name");
		}else
		{
			insert(root,name);
			printf("\nname added successfully...");
		}
		printf("\ndo you want to add new name y/n? : ");
		scanf(" %c",&option);
	}while(option=='y'||option=='Y');
	do{
		printf("\n==========BINARY SEARCH TREE==========");
		printf("\n\nenter a name to search : ");
		scanf(" %[^\n]s",name);
		searchnode=search(root,name);
		if(searchnode==NULL)
			printf("\nsorry name not found...");
		else
			printf("\n%s name is there in BST",searchnode->name);
		printf("\ndo you want to search new name y/n? : ");
		scanf(" %c",&option);
	}while(option=='y'||option=='Y');
	return 0; 
}

struct node* insert(struct node* node, char *name) 
{ 
	if (node == NULL) return newNode(name); 

	if (strcmp(name,node->name)<0) 
		node->left  = insert(node->left,name); 
	else if (strcmp(name,node->name)>0) 
		node->right = insert(node->right,name);    

	return node; 
}
 
struct node *newNode(char *name) 
{ 
	struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
	strcpy(temp->name,name); 
	temp->left = temp->right = NULL; 
	return temp; 
}
 
struct node* search(struct node* root,char *name) 
{ 
	if (root == NULL || strcmp(root->name,name)==0) 
		return root; 
	if (strcmp(root->name,name)<0) 
		return search(root->right,name); 
	return search(root->left,name); 
} 
