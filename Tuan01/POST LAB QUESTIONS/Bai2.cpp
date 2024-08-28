//Write a C program to for implementing binary search technique

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Nhap(int a[], int &n);
void Xuat(int a[], int n);
void SapXep(int a[], int n);
int BinarySearch(int a[], int n, int x);

int main(){
	int t1,t2;
	float s;
	int a[100],n,x;
	srand(time(NULL));
	Nhap(a,n);
	SapXep(a,n);
	Xuat(a,n);
	printf("\nNhap x: "); scanf("%d", &x);
	t1=clock();
	if(BinarySearch(a,n,x))
		printf("Tim thay x");
	else
		printf("Khong tim thay");
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
void SapXep(int a[], int n){
	int i,j;
	for(i=0; i<=n; i++){
		for(j=i+1; j<n; j++){
			if(a[j]<a[i]){
				int doi=a[i];
				a[i]=a[j];
				a[j]=doi;
			}
		}
	}
}
int BinarySearch(int a[], int n, int x){
	int left=0, right=n-1;
	while(left <= right){
		int mid=(left + right)/2;
		if(a[mid]==x)
			return 1;
		else if(a[mid]<x)
			left = mid + 1;
		else 
			right = mid - 1;
	}
	return 0;
}
