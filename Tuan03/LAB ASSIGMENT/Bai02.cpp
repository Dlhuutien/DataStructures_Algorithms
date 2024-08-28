#include<stdio.h>

void Xuat(int a[], int n){
	for(int i=0; i<n; i++)
		printf("%d	", a[i]);
}
void QuickSort(int a[], int first, int last){
	int pivot, i, j, t;
	if(first<last){
		pivot = first;
		i = first;
		j = last;
		while(i<j){
			while(a[i]<= a[pivot] && i<last)
				i++;
			while(a[j]> a[pivot])
				j--;
			if(i<j){
				t = a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	t = a[pivot];
	a[pivot] = a[j];
	a[j]=t;
	QuickSort(a, first, j-1);
	QuickSort(a,j+1, last);
	}
}

int main(){
	int n=9;
	int a[9]={42, 12, 18, 98, 67, 83, 8, 10, 71};
	printf("Day so ban dau\n");
	Xuat(a,n);
	printf("\nSau khi sap xep\n");
	QuickSort(a,0, n-1);
	Xuat(a,n);
	return 0;
}

