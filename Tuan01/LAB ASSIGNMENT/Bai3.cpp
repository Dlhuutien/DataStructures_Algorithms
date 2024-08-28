#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
struct Date{
		int dd;
		int mm;
		int yy;
};
struct record{
	int rollno;
	char name[20];
	Date dob;

};
void nhap(record &rc){
	rc.rollno = rand()%101;
	printf("\nNhap ten ");
	fflush(stdin);
	gets(rc.name);
	rc.dob.dd = 1+ rand()%30;
	rc.dob.mm = 1+ rand()%(12);
	rc.dob.yy = 2000+ rand()%(2022+1-2000);
//	printf("Nhap ngay thang nam sinh: ");
//	scanf("%d %d %d", &rc.dob.dd, &rc.dob.mm, &rc.dob.yy);
}
void xuat(record rc){
	printf("\nRollno   ||   Ten   ||   Ngay sinh");
	printf("\n%4d\t %8s\t %4d/%d/%d", rc.rollno, rc.name, rc.dob.dd, rc.dob.mm, rc.dob.yy);
}
void nhapN(record a[], int n){
	for(int i=0; i<n; i++){
		printf("\nHoc sinh thu %d", i+1);
		nhap(a[i]);
	}
}
void xuatN(record a[], int n){
	for(int i=0; i<n; i++){
		printf("\nHoc sinh thu %d", i+1);
		xuat(a[i]);
	}
}
void timRollNo(record a[], int n, int x){
	for(int i=0; i<n; i++){
		if(a[i].rollno==x)
			xuat(a[i]);
	}
}
void timTen(record a[], int n, char timten[]){
	for(int i=0; i<n; i++){
		if(strcmp(a[i].name,timten)==0)
			xuat(a[i]);
	}
}
void timDate(record a[], int n, Date y){
	printf("\nNhap ngay thang nam can tim: ");
	scanf("%d %d %d", &y.dd, &y.mm, &y.yy);
	for(int i=0; i<n; i++){
		if(a[i].dob.dd==y.dd && a[i].dob.mm==y.mm && a[i].dob.yy==y.yy)
		xuat(a[i]);
	}
}
int main(){
	record a[100];
	Date y;
	int n, x;
	char timten[20];
	printf("Nhap so hoc sinh: "); scanf("%d",&n);
	srand(time(NULL));
	nhapN(a,n);
	xuatN(a,n);
	printf("\nNhap ma so muon tim "); scanf("%d", &x);
	timRollNo(a,n,x);
	printf("\nNhap ten muon tim ");
	fflush(stdin); gets(timten);
	timTen(a,n,timten);
	timDate(a,n,y);
}
