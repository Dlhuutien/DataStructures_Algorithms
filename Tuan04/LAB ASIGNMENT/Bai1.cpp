#include<stdio.h>
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
void taoMang(int a[], int &n){
	printf("nhap vao so phan tu: "); scanf("%d", &n);
    for(int i=0;i<n;i++){
    	printf("a[%d]= ", i); scanf("%d", &a[i]);
        push(a[i]);
    }
}
int main(){
	int choise, value, n;
	int a[SIZE];
	while(1){
		printf("\nMENU\n");
		printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
		printf("Enter your choise: ");
		scanf("%d", &choise);
		switch(choise){
			case 1: 
				taoMang(a,n);
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

