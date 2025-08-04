//WAP TO DELETE THE Kth NODE FROM A LINKED LIST
#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node *next;
};
struct Node *head;
struct Node *InsertAtBeg(struct Node *head,int x){
	struct Node *temp=NULL;
	temp= (struct Node *)malloc(sizeof(Node));
	temp->data=x;
	temp->next=head;
	head=temp;
	return head;
}
 struct Node *InsertAtEnd(struct Node *head,int x){
 	struct Node *newnode=(struct Node *)malloc(sizeof(Node));
newnode->data=x;
newnode->next=NULL;
if(head==NULL){
head=newnode;
return head;
}
struct Node *temp=head;
while(temp->next!=NULL){
	temp=temp->next;
}
temp->next=newnode;
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
 struct Node *deleteKthNode(struct Node *head,int k){
 	int i;
 	struct Node *temp=head;
 	for(i=0;i<k-2;i++){
 		temp=temp->next;          // Temp points to the K-1 th node
	 }
	 struct Node *temp2=temp->next ;         // Temp2 points to the Kth node the node to be deleted
     temp->next=temp2->next;
     temp2->next=NULL;
     free(temp2);
     return head;
 }
 int main(){
	struct Node *head=NULL;
	int n,i,x;
	printf("How many no of nodes?\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("Enter the number: ");
		scanf("%d",&x);
		head=InsertAtEnd(head,x);
		printf("\n");
	}
	printf("\nOriginal ");
	Print(head);
	head=deleteKthNode(head, 3);
	printf("\nAfter deletion ");
	Print(head);
	return 0;
}
