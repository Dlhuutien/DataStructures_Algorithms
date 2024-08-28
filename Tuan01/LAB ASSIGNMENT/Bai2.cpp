#include<stdio.h>
#include<string.h>

int TimKiTu(char s[],int len,char x);

int main(){
	char s[]="Tim kiem tuyen tinh", x;
	int len = strlen(s);
	printf("%s",s);
	printf("\nNhap ki tu x: "); scanf("%c", &x);
	if(TimKiTu(s,len,x))
		printf("Tim thay ki tu x");
	else 
		printf("Khong tim thay");
	return 0;
}

int TimKiTu(char s[],int len,char x){
	for (int i=0; i < len; i++){
    	if (s[i] == x) 
    		return 1;
  	}
  return 0;
}
