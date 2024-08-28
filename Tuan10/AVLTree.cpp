#include<stdio.h>
#define LH -1 //cay con trai cao hon
#define EH 0 //2 cay con bang nhau
#define RH 1 //cay con phai cao hon
struct AVLNode{
	char balFactor; //chi so can bang
	int data;
	AVLNode *pLeft, *pRight;
};
typedef AVLNode *AVLTree;

//quay don Left-Left
void rotateLL(AVLNode &t){
	AVLNode* t1=t->pLeft;
	t->pLeft=t1->pRight;
	t1->pRight=t;
	switch(t1->balFactor){
		case LH: t1->balFactor=EH;
		t1->balFactor=EH;
		break;
		case EH: t1->balFactor=LH;
		t1->balFactor=RH;
		break;
	}
	t=t1;
}
int main(){
	
}

