//WAP TO REMOVE DUPLICATES FROM A SORTED LIST
#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
};
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
struct Node *remove_duplicates(struct Node *head){
	struct Node *curr=head;
	if(head==NULL)
	 return NULL;
	while(curr->next!=NULL){
		if(curr->data==curr->next->data){
			struct Node *next_next=curr->next->next;
			struct Node *nodeToDelete=curr->next;
			free(nodeToDelete);
			curr->next=next_next;
		}
		else{
			curr=curr->next;
		}
		
	}
	return head;
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
	head=remove_duplicates(head);
	Print(head);
}

