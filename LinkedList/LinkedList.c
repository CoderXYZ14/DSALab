#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void traversal(struct Node* p){
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

struct Node *insertAtFirst(struct Node *head,int data){
	struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
	ptr->next=head;
	ptr->data=data;
	return ptr;
}

struct Node *insertAtIndex(struct Node *head,int data,int index){
	struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
	struct Node *p=head;
	if(index==0){
		ptr->next=head;
		return ptr;
	}
	int i=0;
	while(i!=index-1 && p!=NULL){
		p=p->next;
		i++;
	}
	if(p==NULL)
		return head;
	ptr->data=data;
	ptr->next=p->next;
	p->next=ptr;
	return head;
}

struct Node *insertAtEnd(struct Node *head,int data){
	struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
	struct Node *p=head;
	while(p->next!=NULL){
		p=p->next;
	}
	if(p==NULL)
		return head;
	ptr->data=data;
	p->next=ptr;
	ptr->next=NULL;
	return head;
}

struct Node *deleteFirst(struct Node *head){
	struct Node *ptr=head;
	head=head->next;
	free(ptr);
	return head;
}

struct Node *deleteAtIndex(struct Node *head,int index){
	struct Node *p=head;
	struct Node *q=head->next;
	for(int i=0;i<index-1;i++){
		p=p->next;
		q=q->next;
	}
	p->next=q->next;
	free(q);
	return head;
}


struct Node *deleteLast(struct Node *head){
	struct Node *p=head;
	struct Node *q=head->next;
	while(q->next!=NULL){
		p=p->next;
		q=q->next;
	}
	p->next=NULL;
	free(q);
	return head;
}

void search(struct Node *head,int num){
	struct Node *ptr=head;
	int c=0;
	int t=0;
	while(ptr!=NULL){
		if(ptr->data==num){
			printf("Element found at %d position\n",c);
			t++;
			break;
		}
		else{
			ptr=ptr->next;
			c++;
		}
	}
	if(t==0)
	printf("Element not found\n");
}

int main() {
    printf("Enter the number of elements to be in the Linked List: ");
    int n;
    scanf("%d", &n);
    struct Node* arr[n];
    struct Node* head = NULL;
    printf("\nEnter %d elements: ", n);
    for(int i=0;i<n;i++){
        if(i==0){
            arr[0]=(struct Node*)malloc(sizeof(struct Node));
            head=arr[0];
            scanf("%d",&head->data);
        } 
        else{
            arr[i]=(struct Node*)malloc(sizeof(struct Node));
            scanf("%d",&arr[i]->data);
            arr[i-1]->next=arr[i];
        }
    }
    printf("\nLinked List traversal:\n");
    traversal(arr[0]);
    int a;
    printf("ENTER <1> FOR INSERTION \nENTER <2> FOR DELETION \nENTER <3> FOR SERCHING \nENTER <0> TO EXIT \n");
    scanf("%d",&a);
    switch(a){
    	case 1:{
    		printf("ENTER <1> FOR INSERTION AT THE BEGINNING \nENTER <2> FOR INSERTION AT AN GIVEN INDEX \nENTER <3> FOR INSERTION AT THE END\n");
    		int b;
    		scanf("%d",&b);
    		switch(b){
    			case 1:{
    				printf("Enter the data to be inserted:");
    				int dataT;
    				scanf("%d",&dataT);
    				head=insertAtFirst(head,dataT);
    				printf("Linked List after insertion: ");
    				traversal(head);
    				break;
    			}
    			case 2:{
    				printf("Enter the data to be inserted:");
    				int dataT;
    				scanf("%d",&dataT);
    				printf("Enter the position data is be inserted: ");
    				int pos;
    				scanf("%d",&pos);
    				head=insertAtIndex(head,dataT,pos);
    				printf("Linked List after insertion: ");
    				traversal(head);
    				break;
    			}
    			case 3:{
    				printf("Enter the data to be inserted:");
    				int dataT;
    				scanf("%d",&dataT);
    				head=insertAtEnd(head,dataT);
    				printf("Linked List after insertion: ");
    				traversal(head);
    				break;
    			}
    		}
    		break;
    	}
    	case 2:{
    		printf("ENTER <1> FOR DELETION AT THE BEGINNING \nENTER <2> FOR DELETION AT AN GIVEN INDEX \nENTER <3> FOR DELETION AT THE END\n");
    		int b;
    		scanf("%d",&b);
    		switch(b){
    			case 1:{
    				head=deleteFirst(head);
    				printf("Linked List after deletion: ");
    				traversal(head);
    				break;
    			}
    			case 2:{
    				printf("Enter the position to be deleted: ");
    				int pos;
    				scanf("%d",&pos);
    				head=deleteAtIndex(head,pos);
    				printf("Linked List after deletion: ");
    				traversal(head);
    				break;
    			}
    			case 3:{
    				head=deleteLast(head);
    				printf("Linked List after deletion: ");
    				traversal(head);
    				break;
    			}
    		}
    		break;
	}
	case 3:{
		printf("Enter the no. to be searched:");
		int num;
		scanf("%d",&num);
		search(head,num);
	}
	case 0:{
		printf("EXIT");
		exit(1);
	}
     }
     return 0;
}
