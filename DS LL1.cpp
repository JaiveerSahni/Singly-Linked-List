//INSERTION OPERATIONS IN LINKED LIST
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*head;
void create_list(int n);
void display();
void insert_first();
void insert_last();
void insert_middle( int pos);


int main(){
	int n,pos;
	printf("Enter the no of nodes in the linked list: ");
	scanf("%d",&n);
	create_list(n);
	printf("\nData in the list\n");
	display();
	insert_first();
	insert_last();
		printf("Enter the position at which node must be inserted: ");
	scanf("%d",&pos);
	insert_middle(pos);
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
 printf("Enter the data of first node:");
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
	temp=head;
	while(temp!=NULL){
	printf("%d-->",temp->data);
	temp=temp->next;
	}
}
void insert_first(){
	struct node *new1;
	int a;
	if(head==NULL){
		printf("List not found");
	}
	else{
		printf("\nEnter the element to be inserted in the beginning:");
		scanf("%d",&a);
		new1=(struct node *)malloc(sizeof(struct node));
		new1->data=a;
		new1->next=NULL;
		new1->next=head;
		head=new1;
		
	}
}
void insert_last(){
	struct node *new1, *temp;
	int b;
	if(head==NULL){
		printf("List not found");
	}
	else{
			printf("\nEnter the element to be inserted at last:");
		scanf("%d",&b);
		new1=(struct node *)malloc(sizeof(struct node));
		new1->data=b;
		new1->next=NULL;
		temp=head;
		while(temp->next!=NULL){ //ACCESSING THE LAST NODE
		temp=temp->next;
		}
		temp->next=new1;
	}
		
}
void insert_middle(int pos){
	struct node *new1, *temp, *prev;
	int c;
	int i=1;
	if(head==NULL){
		printf("List not found");
	}
	else{
		printf("\nEnter the element to be inserted in the middle:");
		scanf("%d",&c);
		new1=(struct node *)malloc(sizeof(struct node));
		new1->data=c;
		new1->next=NULL;
		temp=head;
		while(i<pos){
			prev=temp;
			temp=temp->next;
			i=i+1;
		}
		prev->next=new1;
		new1->next=temp;
	}
}
	 
 
 
	

