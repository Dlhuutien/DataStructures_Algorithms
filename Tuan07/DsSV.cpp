#include<stdio.h>
#include<stdlib.h>

struct sv{
	int mssv;
	char hoten[30];
	bool gioitinh;
	char diachi[50];
	float diemTB;
};
struct node{
	sv data;
	node *next;
};
node *head = NULL;
node *tail = NULL;
node *taoNode(sv x);
void chenDau(sv x);
void chenCuoi(sv x);
void nhap1SV(sv &x);
void nhapDS();
void xuat1SV(sv x);
void xuatDS();
void lietKe5();
float timMim();
void xuatMin();
int demNu();
node* timSV(int tim);
void capNhapDiem(int ma, float diemMoi);
void chenSauX(sv y, node *p);
void chenTruocX(sv y,node *p);
void chen();
void xoaSV(int x);
void sapXep();

int main(){
	int x, x1;
	float diemMoi;
	nhapDS();
	xuatDS();
	printf("\nDanh sach sinh vien diem >=5:\n");
	lietKe5();
	printf("\nDanh sach sinh vien co diem thap nhat:\n");
	xuatMin();
	printf("\nSo luong sinh vien nu la: %d", demNu());
	printf("\nNhap mssv can cap nhat diem: ");
	scanf("%d", &x1);
	printf("\nNhap diem can cap nhat: "); scanf("%f", &diemMoi);
	capNhapDiem(x1,diemMoi);
	chen();
	xuatDS();
	printf("\nThuc hien xoa\nNhap gia tri can tim: ");
	scanf("%d", &x);
	if(timSV(x)==NULL)
		printf("Khong tim thay x");
	else
		xoaSV(x);
	xuatDS();
	printf("\nDanh sach sau khi sap xep:\n");
	sapXep();
	xuatDS();
}
node *taoNode(sv x){
	node *p;
	p = new node;
	if(p==NULL)
		return NULL;
	p->data=x;
	p->next=NULL;
	return p;
}
void nhap1SV(sv &x){
	printf("\nNhap MSSV: "); scanf("%d", &x.mssv);
	printf("Ho va ten: "); fflush(stdin); gets(x.hoten);
	printf("Gioi tinh(0:Nu): "); scanf("%d", &x.gioitinh);
	printf("Dia chi: "); fflush(stdin); gets(x.diachi);
	printf("Diem trung binh: "); scanf("%f", &x.diemTB);
}
void nhapDS(){
	sv x;
	int n;
	printf("Nhap so luong sv: ");
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		printf("\nNhap thong tin sv thu %d\n", i+1);
		nhap1SV(x);
		chenCuoi(x);
		//chenDau(x);
	}
}
void xuat1SV(sv x){
	printf("%-6d %-15s %-15s %-15s %20.2f\n", 
	x.mssv ,x.hoten, x.gioitinh?("Nam"):("Nu"), x.diachi, x.diemTB);
}
void xuatDS(){
	printf("\n%-6s %-15s %-15s %-15s %20s\n", 
	"MSSV", "Ho va ten", "Gioi tinh", "Dia chi", "Diem trung binh");
	node *p = head;
	while(p!=NULL){
		xuat1SV(p->data);
		p=p->next;
	}
}
void lietKe5(){
	node *p = head;
	while(p!=NULL){
		if(p->data.diemTB>=5)
			xuat1SV(p->data);
		p=p->next;
	}
}
float timMim(){
	float min = head->data.diemTB;
	node *p = head;
	while(p!=NULL){
		if(p->data.diemTB<min)
			min = p->data.diemTB;
		p=p->next;
	}
	return min;
}
void xuatMin(){
	node *p = head;
	float m = timMim();
	while(p!=NULL){
		if(p->data.diemTB == m)
			xuat1SV(p->data);
		p=p->next;
	}
}
int demNu(){
	node *p = head;
	int dem=0;
	while(p!=NULL){
		if(p->data.gioitinh==0)
			dem++;
		p=p->next;
	}
	return dem;
}
node* timSV(int tim){
	node *p = head;
	while(p!=NULL && p->data.mssv!=tim)
		p=p->next;
	return p;
}
void capNhapDiem(int ma, float diemMoi){
	node *p = timSV(ma);
	if(p!=NULL){
		p->data.diemTB=diemMoi;
		xuatDS();
	}
	else
		printf("\nKhong tim thay sinh vien");
}

void chenDau(sv x){
	node *p = taoNode(x);
	if(head == NULL)
		head = p;
	else{
		p->next=head;
		head=p;
	}
}
void chenCuoi(sv x){
	node *p = taoNode(x);
	if(head==NULL){
		head = p;
		tail = p;
	}
	else{
		tail->next=p;
		tail=p;
	}
}
void chenSauX(sv y, node *p){
	node *moi;
	moi=taoNode(y);
	moi->next = p->next;
	p->next = moi;
}
void chenTruocX(sv y,node *p){
	node *q, *moi;
	q=head;
	moi=taoNode(y);
	if(q->next!=p){
		chenDau(y);
	}
	else{
		while(q->next!=p)
		q=q->next;
		q->next = moi;
		moi->next = p;
	}
	
}
void chen(){
	int ma;
	sv x;
	printf("\nNhap ma sinh vien muon chen trong danh sach: ");
	scanf("%d", &ma);
	node *p = timSV(ma);
	if(p==NULL)
		printf("Khong tim thay sinh vien: ");
	else{
		printf("Nhap du lieu sinh vien moi: ");
		nhap1SV(x);
	//	chenSauX(x,p);
		chenTruocX(x,p);
	}
}

void xoaSV(int x){
	node *q;
	node *p=timSV(x);
	if(p!=NULL){
		if(p==head){
			head=head->next;
			free(p);
		}
		else{
			q=head;
			while(q->next!=p)
				q=q->next;
			q->next = p->next;
			free(p);
		}
	}
}
void sapXep(){
	node *p, *q;
	for(p = head; p!=NULL; p=p->next){
		for(q=p->next; q!=NULL; q=q->next){
			if(p->data.diemTB>q->data.diemTB){
				sv temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
		}
	}
}
