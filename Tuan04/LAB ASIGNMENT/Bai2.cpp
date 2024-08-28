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
void display(){
	if(top==-1)
		printf("\nNgan xep da rong!");
	else
	{
		for(int i=top; i>=0; i--)
			printf("%d	", stack[i]);
	}
}
void taoMang(int a[], int &n){
	printf("Nhap vao so phan tu: "); scanf("%d", &n);
    for(int i=0;i<n;i++){
    	printf("a[%d]= ", i); scanf("%d", &a[i]);
        push(a[i]);
    }
}
int main(){
	int n;
	int a[SIZE]; 
	taoMang(a,n);
    printf("\nDanh sach sau khi dao nguoc\n");
	display();
}

