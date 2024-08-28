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
void Bubblesort(int a[], int &n) {
	for (int i = 0; i<n; i++) {
		for (int j = n - 1; j>i; j--)
		if (a[j - 1] < a[j]) {
			int temp = a[j - 1];
			a[j - 1] = a[j];
			a[j] = temp;
			Xuat(a,n);
			printf("\n");
		}
	}
}/*
void Bubblesort(int a[], int &n) {
	for (int i = 0; i<n; i++) {
		for (int j = 0; j<n-i-1; j++)
		if (a[j] < a[j + 1]) {
			int temp = a[j];
			a[j] = a[j+1];
			a[j+1] = temp;
			Xuat(a,n);
			printf("\n");
		}
	}
}
*/
int main(){
	int a[100],n;
	srand(time(NULL));
	Nhap(a,n);
	Bubblesort(a,n);
	return 0;
}


