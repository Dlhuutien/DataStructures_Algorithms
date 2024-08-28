#include<stdio.h>

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
	Xuat(a,n);
	printf("\n");
	}
}

int main(){
	int a[8]={21,11,5,57,49,54,72,88};
	printf("Day so ban dau\n");
	Xuat(a,8);
	printf("\nSap xep (tang dan)\n");
	SelectionSort(a,8);
	return 0;
}


