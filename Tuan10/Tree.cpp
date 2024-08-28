#include<stdio.h>
typedef struct TNODE{
	int key;
	struct TNODE *pLeft, *pRight;	
} *Tree;
int themNut(Tree &t, int x){
	if(t!=NULL){
		if(x==t->key)
			return 0;
		else{
		if(x<t->key)
			themNut(t->pLeft,x);
		else
			themNut(t->pRight,x);
		}
	}
	else{
		t=new TNODE;
		if(t==NULL)
			return -1;
			t->key=x;
			t->pLeft=t->pRight=NULL;
			return 1;
	}
}
void NLR(Tree t){
	if(t!=NULL){
		NLR(t->pLeft);
		printf("%d	", t->key);
		
		NLR(t->pRight);
	}
}
void xuatChan(Tree t){
	if(t!=NULL){
		if(t->key%2==0)
			printf("%d	", t->key);
		xuatChan(t->pLeft);
		xuatChan(t->pRight);
	}
}

int timMin(Tree t){
	if(t!=NULL){
		if(t->pLeft==NULL)
			return t->key;
		else
			return timMin(t->pLeft);
	}
}
int timMax(Tree t){
	if(t!=NULL){
		if(t->pRight==NULL)
			return t->key;
		else
			return timMax(t->pRight);
	}
}
int xuatLonHonX(Tree t, int x){
	if(t!=NULL){
		if(t->key>x)
			printf("%d	", t->key);
		xuatLonHonX(t->pLeft,x);
		xuatLonHonX(t->pRight,x);
	}
}

int doCao(Tree t){
	if(t!=NULL){
		int l = doCao(t->pLeft);
		int r = doCao(t->pRight);
//		int max = (l>r) ? l:r; return 1 + max;
		int max;  
		if(l>r)
			max=l;
		else
			max=r;
		return 1 + max;
	}
}

int sum(Tree t){
	if(t==NULL)
		return 0;
	return (t->key + sum(t->pLeft) + sum(t->pRight));
}
int demNode(Tree t){
	if(t==NULL)
		return 0;
	else
		return 1+ demNode(t->pLeft) + demNode(t->pRight);
}
int demNodeLa(Tree t){
	int count =0;
	if(t==NULL)
		return 0;
	else if(t->pLeft==NULL && t->pRight==NULL)
		count=1;
	return count + demNodeLa(t->pLeft) + demNodeLa(t->pRight);
}
int demNodeBac1(Tree t){
	int count=0;
	if(t==NULL)
		return 0;
	else if((t->pLeft!=NULL && t->pRight==NULL) || 
	(t->pLeft==NULL && t->pRight!=NULL))
		count=1;
	return count + demNodeBac1(t->pLeft) + demNodeBac1(t->pRight);
}
int demNodeBac2(Tree t){
		int count=0;
	if(t==NULL)
		return 0;
	else if(t->pLeft!=NULL && t->pRight!=NULL)
		count=1;
	return count + demNodeBac2(t->pLeft) + demNodeBac2(t->pRight);
}

TNODE* timX(Tree t, int x){
	if(t==NULL)
		return NULL;
	else{
		if(t->key==x)
			return t;
		else if(t->key>x)
			return timX(t->pLeft,x);
		else
			return timX(t->pRight,x);
	}
}

//Xoa node
//Tim phan tu the cho
void timTheCho(Tree &p, Tree &q){
	if(q->pLeft)
		timTheCho(p,q->pLeft);
	else{
		p->key=q->key;
		p=q;
		q=q->pRight;
	}
}
//Xoa
int xoaNode(Tree t, int x){
	if(t==NULL)
		return 0;
	if(t->key>x)
		return xoaNode(t->pLeft,x);
	if(t->key<x)
		return xoaNode(t->pRight,x);
	TNODE *p=t;
	if(t->pLeft==NULL)
		t=t->pRight;
	else if(t->pRight==NULL)
		t=t->pLeft;
	else //t co du 2 con
		timTheCho(p,t->pRight);
	delete p;	
}

void xuatNode(Tree t, int n) {
    if (t==NULL)
        return;
    if (n == 0)
        printf("%d	 ", t->key);
    else {
        xuatNode(t->pLeft, n - 1);
        xuatNode(t->pRight, n - 1);
    }
}
int tongMuc(Tree t, int n){
	if(t==NULL)
	return 0;
	for(int i=0; i<n; i++)
		return t->key + tongMuc(t->pLeft,n-1) + tongMuc(t->pRight,n-1);
}
void xuatNodeMucN(Tree t) {
	int n;
	printf("\nNhap muc n: "); scanf("%d", &n);
    for (int i=0; i<n; i++) {
        xuatNode(t, i);
    }
   	printf("\nTong %d ", tongMuc(t,n));
}

int doDaiTuGocDenX(Tree t, int x){
    if (t == NULL)
      return -1;
    int dist = -1;
    if (t->key == x || (dist = doDaiTuGocDenX(t->pLeft, x)) >= 0 ||
	(dist = doDaiTuGocDenX(t->pRight, x)) >= 0)
        return dist + 1;
    return dist;
}

int main(){
	int x1;
	Tree T=NULL;
	int a[]={20,15,35,30,11,13,17,36,47,16,38,28,14};
	for(int i=0; i<13; i++)
		themNut(T,a[i]);
	NLR(T);
	printf("\nXuat so chan\n");	xuatChan(T);
	printf("\nTong: %d", sum(T));
	printf("\nMin: %d", timMin(T));
	printf("\nMin right: %d", timMin(T->pRight));
	printf("\nMax: %d", timMax(T));
	printf("\nXuat lon hon x\n");
	xuatLonHonX(T,25);
	printf("\nDo cao cua cay: %d", doCao(T));
	printf("\nDem node: %d", demNode(T));
	printf("\nDem node la: %d ", demNodeLa(T));
	printf("\nDem node bac 1: %d ", demNodeBac1(T));
	printf("\nDem node ben phai: %d", demNode(T->pRight));
	printf("\nDem node ben trai: %d", demNode(T->pLeft));
	printf("\nDem node bac 2: %d ", demNodeBac2(T));
	printf("\n(Tim node) Nhap node muon tim: ");
	scanf("%d", &x1);
	TNODE *t=timX(T,x1);
	if(t==NULL)
		printf("Khong tim thay");
	else
		printf("Tim thay");

	printf("\nDo dai tu goc den x: %d", doDaiTuGocDenX(T,38));
	xuatNodeMucN(T);
	
	//	xoaNode(T,20);
	//	printf("\nSau khi xoa: ");
	//	NLR(T);
}

