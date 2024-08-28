#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
struct record{
	int stt;
	int marks;
};
void Nhap(record &st){
	st.stt=1;
//	printf("Nhap diem: "); scanf("%f", &st.marks);
	st.marks=rand()%101;
}
void Xuat(record st){
	printf("STT: %-10d	||	 Diem: %-10d\n", st.stt, st.marks);
}
void NhapN(record ds[],int n){
	for(int i=0; i<n; i++){
		Nhap(ds[i]);
	}
}
void XuatN(record ds[],int n){
	for(int i=0; i<n; i++){
		ds[i].stt+=i;
		Xuat(ds[i]);
	}
}
void swap(record &x, record &y){
	record t;
	t=x;
	x=y;
	y=t;
}

void Bubblesort_marks(record ds[], int n) {
	for (int i = 0; i<n; i++) {
		for (int j = n - 1; j>i; j--)
		if (ds[j].marks > ds[j - 1].marks) {
			swap(ds[j], ds[j-1]);
		}
	}
}
void inTop(record ds[], int n){
	for(int i=0; i<10; i++){
		Xuat(ds[i]);
	}
}
int main(){
	srand(time(NULL));
	record ds[50];
	int n=50;
	NhapN(ds,n);
	XuatN(ds,n);
	printf("Danh sach Top 10\n");
	Bubblesort_marks(ds,n);
	inTop(ds,n);
	return 0;
}


