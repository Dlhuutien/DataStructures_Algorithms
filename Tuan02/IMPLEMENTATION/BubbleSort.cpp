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
		for (int j = 0; j<n-i-1; j++)
		if (a[j] > a[j + 1]) {
			int temp = a[j];
			a[j] = a[j+1];
			a[j+1] = temp;
		}
	}
}

int main(){
	int a[100],n;
	srand(time(NULL));
	Nhap(a,n);
	Xuat(a,n);
	printf("\nSap khi sap xep\n");
	Bubblesort(a,n);
	Xuat(a,n);
	return 0;
}


