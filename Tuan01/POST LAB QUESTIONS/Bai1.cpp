#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Nhap(int a[], int &n);
void Xuat(int a[], int n);
int LinearSearch(int a[], int x);

int main(){
	int t1,t2;
	float s;
	int a[100],n,x;
	srand(time(NULL));
	Nhap(a,n);
	Xuat(a,n);
	printf("\nNhap gia tri can tim: "); scanf("%d", &x);
	t1=clock();
	if(LinearSearch(a,x)==-1)
		printf("Khong tim thay");
	else
		printf("Tim thay o vi tri %d", LinearSearch(a,x));
	t2=clock();
	printf("\n%d -> %d", t1, t2);
	s=(float)(t2-t1)/100;
	printf("\nThoi gian thuc thi: %f", s);	
	return 0;
}

void Nhap(int a[], int &n){
	printf("Nhap cac phan tu cua mang n= ");
	scanf("%d", &n);
	for(int i=0; i<n; i++){
//		printf("a[%d]= ",i); scanf("%d", &a[i]);
		a[i]=rand()%101;
	}
	
}

void Xuat(int a[], int n){
	for(int i=0; i<n; i++)
		printf("%d	", a[i]);
}
int LinearSearch(int a[], int x){
	int tim = -1;
	for(int i=0; i<10; i++)
		if(a[i]==x){
			tim = i;
			break;
		}
	return tim;
}
