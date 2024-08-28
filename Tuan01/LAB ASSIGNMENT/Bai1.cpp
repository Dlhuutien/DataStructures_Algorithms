#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Nhap(int a[], int &n);
void Xuat(int a[], int n);
void SapXep(int a[], int n);
int BinarySearch(int a[], int left, int right, int x);

int main(){
	int a[100],n,x;
	srand(time(NULL));
	Nhap(a,n);
	SapXep(a,n);
	Xuat(a,n);
	printf("\nNhap x: "); scanf("%d", &x);
	if(BinarySearch(a,0,n-1,x))
		printf("Tim thay x");
	else
		printf("Khong tim thay");	
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

int BinarySearch(int a[], int left, int right, int x) {
	if (left <= right ) {
    	int mid = (left+right)/2;
    	if (x==a[mid])
    		return mid;
    	if (x < a[mid])
    		return BinarySearch(a, left, mid - 1, x);
    	else
			return BinarySearch(a, mid + 1, right, x);
  	}
  	return -1;
}
