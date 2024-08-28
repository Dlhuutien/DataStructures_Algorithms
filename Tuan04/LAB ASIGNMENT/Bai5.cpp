#include<stdio.h>
#include<stdlib.h>
#include <string.h>
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
		top--;
}
int isEmpty() {
	if(top == -1)
    	return 1;
	else
    	return 0;
}
void nhapDauNgoac(char s[20]){
	char c;
	printf("Nhap bieu thuc '{' ; '}'\n");
    gets(s);
    int length = strlen(s);
    for(int i = 0; i < length; i++){
        if(s[i] == '{')
            push(s[i]);
        else if(s[i] == '}')
            pop();
        else
        	printf("loi! Phai nhap '{ }'\n");
}
}
void kTraNgoac(){
	if(isEmpty()==1)
        printf("Can bang");
    else
        printf("Khong can bang");
}
int main(){
	char s[20];
	nhapDauNgoac(s);
	kTraNgoac();
    return 0;
}

