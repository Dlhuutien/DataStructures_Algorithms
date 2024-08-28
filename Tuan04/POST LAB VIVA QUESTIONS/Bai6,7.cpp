#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10
int queue[SIZE], front=-1, rear = -1;

void enQueue(int value){
	if(rear==SIZE-1)
		printf("Queue full");
	else {
		if(front == -1)
			front = 0;
		rear++;
		queue[rear] = value;
	}
}
void deQueue(){
	if(front==-1)
		printf("Queue is Empty");
	else{
		printf("Deleted: %d", queue[front]);
		front++;
		if(front == rear)
			front = rear =-1;
	}
}
void display(){
	if(rear==-1)
		printf("\nQueue is Empty");
	else
	{
		int i;
		printf("Queue elements are:\n");
		for(int i=front; i<=rear; i++)
			printf("%d	", queue[i]);
	}
}
int main(){
	int choise, value;
	int t1, t2;
	float s;
	while(1){
		printf("\n\nMENU\n");
		printf("1. Time complexity of Insertion\n2. Time complexity of Deletion\n3. Exit\n");
		printf("Enter your choise: ");
		scanf("%d", &choise);
		switch(choise){
			case 1: 
				t1= clock();
				printf("Enter any elements: ");
				scanf("%d", &value);
				enQueue(value);
				t2 = clock();
				display();
				printf("\n%d -> %d", t1, t2);
				s = (float)(t2-t1)/100;
				printf("\nThoi gian thuc thi: %f", s);
				break;
			case 2: t1 = clock();
				deQueue();
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

