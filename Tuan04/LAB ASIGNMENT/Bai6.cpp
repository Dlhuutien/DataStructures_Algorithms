#include<stdio.h>
#include<stdlib.h>
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
void taoMang(int a[], int &n){
	printf("nhap vao so phan tu: "); scanf("%d", &n);
    for(int i=0;i<n;i++){
    	printf("a[%d]= ", i); scanf("%d", &a[i]);
        enQueue(a[i]);
    }
}
int main(){
	int choise, value, n;
	int a[SIZE];
	while(1){
		printf("\nMENU\n");
		printf("1. Insertion\n2. Deletion\n3. Display\n4. Exit\n");
		printf("Enter your choise: ");
		scanf("%d", &choise);
		switch(choise){
			case 1: taoMang(a,n);
				break;
			case 2: deQueue();
				break;
			case 3: display();
				break;
			case 4: exit(0);
				default: printf("\nWrong selection");
		}
	}
}

