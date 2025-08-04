//MERGING TWO SORTED LINKED LISTS
#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node *next;
};
struct Node *head1,*head2;
struct Node *InsertAtBeg(struct Node *head,int x){
	struct Node *temp=NULL;
	temp= (struct Node *)malloc(sizeof( struct Node));
	temp->data=x;
	temp->next=head;
	head=temp;
	return head;
}
struct Node *InsertAtEnd(struct Node *head,int x){
     struct Node *newnode=(struct Node *)malloc(sizeof(struct Node));
	 newnode->data=x;
	 newnode->next=NULL;
		if(head==NULL){
		  head=newnode;
	}
	else{
	
struct Node *temp=head;

while(temp->next!=NULL){
	temp=temp->next;
}
temp->next=newnode;
}
return head;
}
 void Print(struct Node *head){
 	struct Node *temp=head;
 	printf("The List is:");
 	while(temp!=NULL){
 		printf("%d-->",temp->data);
 		temp=temp->next;
	 }
	 printf("null");
	 printf("\n");
 }
struct Node *merge(struct Node *head1, struct Node *head2){
	struct Node *p1=head1;
	struct Node *p2=head2;
	struct Node dummyNode;
	struct Node *p3=&dummyNode;
	dummyNode.next=NULL;
	while(p1!=NULL && p2!=NULL){
		if(p1->data < p2->data){
			p3->next=p1;
			p1=p1->next;
		}
		else{
			p3->next=p2;
			p2=p2->next;
		}
		p3=p3->next;
	}
	while(p1!=NULL){
		p3->next=p1;
		p1=p1->next;
		p3=p3->next;
	}
	while(p2!=NULL){
		p3->next=p2;
		p2=p2->next;
		p3=p3->next;
	}
	return dummyNode.next;
}

 int main(){
 	struct Node *head1=NULL;
 	struct Node *head2=NULL;
 	int i;
 	int arr1[4]={2,5,7,9};
 	int arr2[4]={1,3,4,6};
 	for(i=0;i<4;i++){
 		head1=InsertAtEnd(head1,arr1[i]);
	 }
	for(i=0;i<4;i++){
 		head2=InsertAtEnd(head2,arr2[i]);
	 }
	Print(head1);
	Print(head2);
	struct Node *newhead=merge(head1,head2);
	Print(newhead);
 	
 	
 }
