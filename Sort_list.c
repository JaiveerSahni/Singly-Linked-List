//SORTING A LINKED LIST
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
}*head;
void create_list(int n);
void display();
void sort_list();
int main(){
	int n;
	printf("Enter the no of nodes in the list: ");
	scanf("%d",&n);
	create_list(n);
	display();
	sort_list();
	printf("\nThe Sorted List is: ");
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
void sort_list(){
	int temp;
	struct node *ptr,*cpt;
	ptr=head;
	while(ptr->next!=NULL){
		cpt=ptr->next;
		while(cpt!=NULL){
			if(ptr->data>cpt->data){
				temp=ptr->data;
				ptr->data=cpt->data;
				cpt->data=temp;
			}
			cpt=cpt->next;
		}
		ptr=ptr->next;
	}
}
