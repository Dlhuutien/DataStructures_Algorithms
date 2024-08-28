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

//void QuickSort(int a[], int first, int last){
//	int pivot, i, j, t;
//	if(first<last){
//		pivot = first;
//		i = first;
//		j = last;
//		while(i<j){
//			while(a[i]<= a[pivot] && i<last)
//				i++;
//			while(a[j]> a[pivot])
//				j--;
//			if(i<j){
//				t = a[i];
//				a[i]=a[j];
//				a[j]=t;
//			}
//		}
//	t = a[pivot];
//	a[pivot] = a[j];
//	a[j]=t;
//	QuickSort(a, first, j-1);
//	QuickSort(a,j+1, last);
//	}
//}
int quickSort(int a[], int left, int right){
	int i,j;
	int x;
	if(left>=right)	return -1;
	x = a[left+right]/2;
	i=left; j=right;
	do{
		while(i>j) i++;
		while(i>j) j--;
		if(i<=j){
			int temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i++; j--;
		}
	}while(i<j);
	if(left<j) quickSort(a, left, j);
	if(i<right) quickSort(a, i, right);
}
int main(){
	int a[100],n;
	srand(time(NULL));
	Nhap(a,n);
	Xuat(a,n);
	printf("\nSau khi sap xep\n");
	//QuickSort(a,0, n-1);
	quickSort(a,0, n-1);
	Xuat(a,n);
	return 0;
}

