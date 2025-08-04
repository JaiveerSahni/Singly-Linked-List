//INSERTION AND DELETION AT nth POSITION IN LIST
#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node *next;
};
struct Node *head;
void InsertAtBeg(int x){
	struct Node *temp=NULL;
	temp= (struct Node *)malloc(sizeof(Node));
	temp->data=x;
	temp->next=head;
	head=temp;
}
void InsertAtEnd(int x){

struct Node *temp=head;
struct Node *newnode=(struct Node *)malloc(sizeof(Node));
newnode->data=x;
newnode->next=NULL;
while(temp->next!=NULL){
	temp=temp->next;
}
temp->next=newnode;
}
void Insert(int data,int n){
	struct Node *temp1=(struct Node *)malloc(sizeof(Node));
	temp1->data=data;
	temp1->next=NULL;
	if(n==1){
		temp1->next=head;
		head=temp1;
		return;
	}
	struct Node *temp2=head;
	for(int i=0;i<n-2;i++){
		temp2=temp2->next;
	}
	temp1->next=temp2->next;
	temp2->next=temp1;
}
 void Delete( int pos){
	struct Node *temp1=head;
	for(int i=0;i<pos-2;i++){
		temp1=temp1->next;
		
	}
	struct Node *temp2=temp1->next;
	temp1->next=temp2->next;
	free(temp2);
}
void Print(){
 	struct Node *temp=head;
 	printf("The List is:");
 	while(temp!=NULL){
 		printf("%d-->",temp->data);
 		temp=temp->next;
	 }
	 printf("null");
	 printf("\n");
 	
 }
int main(){
	head=NULL;
	InsertAtBeg(4);
	InsertAtEnd(5);
	InsertAtEnd(6);
	InsertAtEnd(7);
	InsertAtEnd(8);
	Print();
	Insert(3,4);
	Print();
	Delete(4);
	Print();
	return 0;
	
	
}
