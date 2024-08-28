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
	int t1, t2;
	float s;
	int a[100],n;
	srand(time(NULL));
	Nhap(a,n);
	Xuat(a,n);
	t1=clock();
	printf("\nSau khi sap xep\n");
	QuickSort(a,0, n-1);
	Xuat(a,n);
	t2=clock();
	printf("\n%d -> %d", t1, t2);
	s=(float)(t2-t1)/100;
	printf("\nThoi gian thuc thi: %f", s);
	return 0;
}

