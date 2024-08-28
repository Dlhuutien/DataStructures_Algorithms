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
		if (a[j] < a[j + 1]) {
			int temp = a[j];
			a[j] = a[j+1];
			a[j+1] = temp;
		}
	}
}

int main(){
	int t1,t2;
	float s;
	int a[100],n;
	srand(time(NULL));
	Nhap(a,n);
	Xuat(a,n);
	printf("\nSau khi sap xep\n");
	t1=clock();
	Bubblesort(a,n);
	Xuat(a,n);
	t2=clock();
	printf("\n%d -> %d", t1, t2);
	s=(float)(t2-t1)/100;
	printf("\nThoi gian thuc thi: %f", s);
	return 0;
}


