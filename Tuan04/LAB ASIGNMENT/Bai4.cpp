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
int Top(){
    if(top==-1)
        printf("Ngan xep da rong!");
    else
        return stack[top];
}
void pop(){
	if(top==-1)
		printf("Ngan xep da rong!");
	else
		top--;
}
int main(){
	int n;
	printf("Nhap so nguyen: "); scanf("%d", &n);
    push(n);
    for(int i=1;i<n;i++){
        push(Top() * i);
    }
    printf("\nGiai thua cua %d la: %d",n, Top());
}

