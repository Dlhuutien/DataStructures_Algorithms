#include<stdio.h>
#include<stdlib.h>
#include<time.h>

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
void InsertionSort(int a[], int n)
{
   int item, j;
   for (int i = 1; i < n; i++){
    	item = a[i];
       	j = i-1;
       	while (j >= 0 && a[j] > item){
           	a[j+1] = a[j];
           	j = j-1;
       	}
       	a[j+1] = item;
   	}
}
int main(){
	int a[100],n;
	srand(time(NULL));
	Nhap(a,n);
	Xuat(a,n);
	printf("\nSau khi sap xep\n");
	InsertionSort(a,n);
	Xuat(a,n);
	return 0;
}


