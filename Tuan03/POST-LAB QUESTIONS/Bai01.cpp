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

void swap(int &a, int &b)
{
	int x = a;
	a = b;
	b = x;
}
void SelectionSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
			if (a[min]>a[j])
				min = j;
			swap(a[i], a[min]);
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
	SelectionSort(a,n);
	Xuat(a,n);
	t2=clock();
	printf("\n%d -> %d", t1, t2);
	s=(float)(t2-t1)/100;
	printf("\nThoi gian thuc thi: %f", s);
	return 0;
}


