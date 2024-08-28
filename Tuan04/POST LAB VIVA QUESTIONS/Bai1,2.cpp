#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
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
	int t1, t2;
	float s;
	while(1){
		printf("\n\nMENU\n");
		printf("1. Time complexity of Push\n2. Time complexity of Push Pop\n3. Exit\n");
		printf("Enter your choise: ");
		scanf("%d", &choise);
		switch(choise){
			case 1: t1 = clock();
				printf("Enter any elements: ");
				scanf("%d", &value);
				push(value);
				t2 = clock();
				display();
				printf("\n%d -> %d", t1, t2);
				s = (float)(t2-t1)/100;
				printf("\nThoi gian thuc thi: %f", s);
				break;
			case 2: t1 = clock();
				pop();
				t2 = clock();
				display();
				printf("\n%d -> %d", t1, t2);
				s = (float)(t2-t1)/100;
				printf("\nThoi gian thuc thi: %f", s);
				break;
			case 3: exit(0);
				default: printf("\nWrong selection");
		}
	}
}

