// CREATING A LIST BY INSERTING ELEMENTS IN THE BEGINNING
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
 // COUNT THE NO OF OCCURENCES OF A VALUE
 int count_occ(struct Node *head,int data){
 	struct Node *temp=head;
 	int count=0;
 	while(temp!=NULL){
 		if(temp->data==data){
 			count++;
		 }
		 temp=temp->next;
	 }
	 return count;
 }
 //SUM OF ALL THE VALUES IN THE NODES
 void sum(struct Node *head){
 	struct Node *temp=head;
 	int sum=0;
 	while(temp!=NULL){
 		sum=sum+temp->data;
 		temp=temp->next;
	 }
	 printf("\n The sum of the values of all the nodes in the list is %d\n",sum);
 }
 //MAXIMUM VALUE AMONG ALL THE NODES IN THE LIST
 int max(struct Node *head){
 	struct Node *temp1=head;
 	struct Node *temp=temp1->next;
 	
 	 int max=temp1->data;
 	while(temp!=NULL){
 		if(max<temp->data){
 		max=temp->data;
		 }
		 temp=temp->next;
	 }
	 return max;
 }

int main(){
	struct Node *head=NULL;
	int n,i,x,a,b ;
	printf("How many no of nodes?\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("Enter the number: ");
		scanf("%d",&x);
		head=InsertAtEnd(head,x);
		printf("\n");
	}
	Print(head);
	a=max(head);
	printf("\nThe no of occurences of 4 is %d\n",count_occ(head,4));
	
	printf("The maximum element in the list is %d",a);
	sum(head);
	return 0;
	
}
