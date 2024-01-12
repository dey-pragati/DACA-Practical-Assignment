//  1. Program to implement push() and pop() operations of Stack using Singly Linked List
#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;
	struct Node *link;
};

struct Node *Top = NULL;

void push(int x);
void pop();

//  An auxiliary function to display stack
void display_Stack() {
	struct Node *ptr;
	if(Top == NULL){
		printf("\nStack is Empty..!! ");
	}
	else {
		ptr = Top;
		printf("Elements present in the Stack: ");
		while(ptr != NULL){
			printf("%d  ", ptr->data);
			ptr = ptr->link;
		}
	}
	printf("\n\n");
}


int main() {
	int ch, val;

    do {
    printf("<------- STACK OPERATIONS ------->\n");
    printf("1. PUSH Elements\n");
    printf("2. POP Elements\n");
    printf("3. Display Elements in Stack\n");
    printf("4. Exit\n");
    printf("<-------------------------------->\n\n");
    printf("Enter your choice: ");
    scanf("%d",&ch);

      switch(ch) {
        case 1: printf("Enter the element to be pushed: ");
            	scanf("%d",&val);
            	push(val);
            	break;
         
		case 2: pop();
            	break;
         
        case 3: system("cls");
				display_Stack();
            	break;
        
        case 4:	system("cls");
				printf("Exiting...\n");
		        exit(0);
         		break;
         
        default:	system("cls"); 
            		printf("\nInvalid Choice!!\n\n");
      }
   }while(ch != 4);	
}


// 	Implementation of Push Operation
void push(int x) {
	struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));

	if(newNode == NULL) {
		system("cls");
		printf("\nStack Overflow!!\nCan not push %d to the Stack!\n\n",x);
		return;
	}
	else {
	newNode->data = x;
	newNode->link = Top;
	Top = newNode;
	system("cls");
	printf("\n%d pushed to the Stack!!\n", newNode->data);
	display_Stack();
	}
}

//  Implementation of Pop Operation
void pop() {
	if(Top == NULL) {
		system("cls");
		printf("\nStack Underflow..!!\n\n");
		return;
	}
	else {
		system("cls");
		printf("\n%d popped from the Stack!!\n", Top->data);
		Top = Top->link;
		display_Stack();
	}
}