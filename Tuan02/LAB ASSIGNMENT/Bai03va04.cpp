#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
struct record{
	char name[20];
	double salary;
};
void Nhap(record &nv){
	printf("Nhap ten: ");
	fflush(stdin);
	gets(nv.name);
//	printf("Nhap luong: "); scanf("%f", &nv.luong);
	nv.salary=rand()%10000000;
}
void Xuat(record nv){
	printf("Ten: %-20s	||	 Luong: %-10f VND\n", nv.name, nv.salary);
}
void NhapN(record ds[], int n){
	for(int i=0; i<n; i++){
		Nhap(ds[i]);
	}
}
void XuatN(record ds[], int n){
	for(int i=0; i<n; i++){
		Xuat(ds[i]);
	}
}
void swap(record &x, record &y){
	record t;
	t=x;
	x=y;
	y=t;
}
void Bubblesort_name(record ds[], int n) {
	for (int i = 0; i<n; i++) {
		for (int j = n - 1; j>i; j--)
		if (strcmp(ds[j].name,ds[j - 1].name)==-1) {
			swap(ds[j], ds[j-1]);
		}
	}
}

void InsertionSort_salary(record ds[], int n)
{
	record item;
	int j;
   for (int i = 1; i < n; i++){
    	item = ds[i];
       	j = i-1;
       	while (j >= 0 && ds[j].salary > item.salary){
           	ds[j+1] = ds[j];
           	j = j-1;
       	}
       	ds[j+1] = item;
   	}
}

int main(){
	int n;
	srand(time(NULL));
	record ds[100];
	printf("Nhap n= "); scanf("%d",&n);
	NhapN(ds,n);
	//Ten
	printf("Sap xep theo ten (tang dan)\n");
	Bubblesort_name(ds,n);
	XuatN(ds,n);
	//luong
	printf("Sap xep theo luong (tang dan)\n");
	InsertionSort_salary(ds,n);
	XuatN(ds,n);
	return 0;
}


