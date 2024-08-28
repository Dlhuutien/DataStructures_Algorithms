#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define SIZE 10
int stack[SIZE], top=-1;

void push(int value){
	if(top==SIZE-1)
		printf("Stack full");
	else 
		top++;
		stack[top] = value;
}
void pop(){
	if(top==-1)
		printf("Stack is Empty");
	else{
	
		printf("Deleted: %d", stack[top]);
		top --;
	}
}
void display(){
	if(top==-1)
		printf("\nStack is Empty");
	else
	{
		int i;
		printf("Stack elements are:\n");
		for(int i=top; i>=0; i--)
			printf("%d	", stack[i]);
	}
}
int main(){
	int choise, value;
	while(1){
		printf("\nMENU\n");
		printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
		printf("Enter your choise: ");
		scanf("%d", &choise);
		switch(choise){
			case 1: printf("Enter any elements: ");
				scanf("%d", &value);
				push(value);
				break;
			case 2: pop();
				break;
			case 3: display();
				break;
			case 4: exit(0);
				default: printf("\nWrong selection");
		}
	}
}

