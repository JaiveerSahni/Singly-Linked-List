//REVERSING A SINGLY LINKED LIST
//FINDING MIDDLE ELEMENT OF A LINKED LIST
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;	
}*head;
void create_list( int n);
void display();
void reverse_list();
void middle_element();

int main(){
	int n;
	printf("Enter the no of nodes in the list: ");
	scanf("%d",&n);
	create_list(n);
	display();
	middle_element();
	printf("\nThe Reversed list is:");
	reverse_list();
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
 printf("Enter the data of node 1: ");
 scanf("%d",&data);
 head->data=data;
 head->next=NULL;
 temp=head;
 for(i=2;i<=n;i++){
 	newnode=(struct node *)malloc(sizeof(struct node));
 	if(newnode==NULL){
 		printf("Unable to allocate the memory");
 		break;
	 }
	 printf("Enter the data of node %d :",i);
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
		exit(0);
	}
	temp=head;
	while(temp!=NULL){
	printf("%d-->",temp->data);
	temp=temp->next;
	}
	printf("NULL\n");
}
void reverse_list(){
	struct node *prev=NULL,*current=NULL,*nextnode=NULL;
	if (head==NULL){
		printf("Empty List");
	    return;
	}
	if(head->next==NULL){
		printf("The List is already reversed,only 1 node");
		return;
	}
	prev=NULL;
	current=head;
	while(current!=NULL){
	
	nextnode=current->next;
	current->next=prev;
	prev=current;
	current=nextnode;
}
head=prev;	
}
 void middle_element(){
	struct node *slow=head,*fast=head;
	if(head==NULL){
		printf("The List is Empty");
		return;
}
   else{
   	while(fast!=NULL && fast->next!=NULL){
   		slow=slow->next;
   		fast=fast->next->next;
	   }
	   printf("The Middle Element of the list is %d",slow->data);
   }
	}


