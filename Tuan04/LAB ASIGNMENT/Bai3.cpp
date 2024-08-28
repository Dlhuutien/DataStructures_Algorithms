#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int stack[SIZE], top=-1;

void push(int value){
	if(top==SIZE-1)
		printf("\nNgan xep da day!");
	else 
		top++;
		stack[top] = value;
}
void pop(){
	if(top==-1)
		printf("Ngan xep da rong!");
	else
		top--;
}
int peek(){
	return stack[top];
}
void deToBi(int n){
	while(n>0){
		push(n%2);
		n=n/2;
	}
	
	while(top!= -1){
	printf("%d", peek());
	pop();
	}
}

int main(){
	int n;
	printf("Nhap so nguyen: "); scanf("%d", &n);
	printf("Chuyen thap phan sang nhi phan: ");
    deToBi(n);
}

