// DELETION OPERATIONS ON LINKED LIST
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
}*head;
void delete_first();
void delete_last();
void delete_middle(int pos);
void display();
void create_list(int n);

int main(){
	int n;
	printf("Enter the no of nodes in the linked list: ");
	scanf("%d",&n);
	create_list(n);
	printf("\nData in the list\n");
	display();
	delete_first();
	display();
	delete_last();
	display();
	delete_middle(3);
    display();
return 0;	
}
void create_list(int n){
		struct node *newnode, *temp;
	head=(struct node *)malloc(sizeof(struct node));
	int data,i;
	if(head==NULL)
	{
	printf("Unable to allocate memory");
	exit(0);	
}
 printf("Enter the data of node 1:");
 scanf("%d",&data);
 head->data=data;
 head->next=NULL;
 temp=head;
 for(i=2;i<=n;i++){
 	newnode=(struct node *)malloc(sizeof(struct node));
 	if(newnode == NULL){
 		printf("Unable to allocate the memory");
 		break;
	 }
	 printf("Enter the data of node %d:",i);
	 scanf("%d",&data);
	 newnode->data=data;
	 newnode->next=NULL;
	 temp->next=newnode;
	 temp=temp->next;
}
}
void display(){
	struct node *temp;
	if(head==NULL){
		printf("The List is Empty");
		return;
	}
	else{
	
	temp=head;
	while(temp!=NULL){
	printf("%d-->",temp->data);
	temp=temp->next;
	}
}
}
void delete_first(){
	struct node *temp;
	if(head==NULL)
	printf("List is empty");
	else{
		temp=head;
		head=head->next;
		printf("\nThe deleted node is %d\n:",temp->data);
		free(temp);
	}
}
void delete_last(){
struct node *temp, *prev;
if(head==NULL)
	printf("\nList is empty");
		temp=head;
		while(temp->next!=NULL){
		prev=temp;
		temp=temp->next	;
		}
		prev->next=NULL;
		printf("\nThe deleted node is %d\n:",temp->data);
		free(temp);
}
void delete_middle(int pos){
	int i=1;
	
struct node *temp, *prev,*add ;
if(head==NULL)
	printf("\nList is empty");
temp=head;
while(i<pos){
	prev=temp;
	temp=temp->next;
	i++;
}
prev->next=temp->next;
printf("\nThe deleted node is %d :",temp->data);
free(temp);
}

