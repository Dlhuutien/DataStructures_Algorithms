#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	node *next;
};
node *head = NULL;
node *taoNode(int x);
void insert_at_beginning(int x);
void insert_at_end(int x);
void xuatDS();
node* timKiem(int x);
void insert_at_middle(int y, node *p);
void delete_at_begging();
void delete_at_middle(int x);
void delete_at_end();
int countNodes();
//------------------------------------------------------
int main(){
	int ch=0;
	int x, n, x1;
	node *p;
	while(1)
	{
		printf("\n***SINGLE LINKED LIST ***\n");
		printf("\n1. Insertion at beginning");
		printf("\n2. Insertion at the middle");
		printf("\n3. Isertion at the end");
		printf("\n4. Delete at beginninng");
		printf("\n5. Delete at middle");
		printf("\n6. Delete at end");
		printf("\n7. Travelsal forwarl");
		printf("\n8. Count number of nodes");
		printf("\n0.exit\n");
		printf("\nEnter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{
					int value;
					printf("\nEnter data: ");
					scanf("%d",&value);
					insert_at_beginning(value);
					break;
				}
			case 2:
				{
					int x;
					printf("\nNhap gia tri can tim: ");
					scanf("%d", &x);
					if(timKiem(x)==NULL)
						printf("Khong tim thay x");
					else{
						printf("Tim thay x\n");
					//Them gia tri y vao sau x
					int value;
					printf("\nEnter data: ");
					scanf("%d",&value);
					insert_at_middle(value, timKiem(x));
					break;
				}
			case 3:
				{
					int value;
					printf("\nEnter data: ");
					scanf("%d",&value);
					insert_at_end(value);
					break;
				}
			case 4:
				{
					
					delete_at_begging();
					break;
				}
			case 5:
				{
				int x;
				printf("\nNhap gia tri can tim: ");
				scanf("%d", &x);
				if(timKiem(x)==NULL)
					printf("Khong tim thay x");
				else{
					printf("Tim thay x\n");	
				delete_at_middle(x);
				}
				break;
			case 6:
				delete_at_end();
				break;
			case 7:
				printf("Traversal forward\n");
				xuatDS();
				break;
			case 8:
				printf("Count number of nodes= %d", countNodes());
				break;
			case 0:
			{
				exit(1);
			}
			default:printf("\n****Please enter correct choice****\n");
			}
		}	
	}
}
}
//------------------------------------------------------
node *taoNode(int x){
	node *p;
	p = (node*)malloc(sizeof(node));
	p->data = x;
	p->next = NULL;
	return p;
}
void insert_at_beginning(int x){
	node *p = taoNode(x);
	if(head == NULL)
		head = p;
	else{
		p->next=head;
		head=p;
	}
}
void insert_at_end(int x){
	node *p = taoNode(x);
	node *t;
	if(head == NULL)
		head = p;
	else{
		//tim node cuoi danh sach
		t=head;
		while(t->next!=NULL)
			t=t->next;
		//bo sung b vao cuoi danh sach
		t->next=p;
	}
}

void xuatDS(){
	node *p;
	for(p=head; p!=NULL; p=p->next)
		printf("%d	", p->data);
}

node* timKiem(int x){
	node *p;
	for(p=head; p!=NULL; p=p->next)
		if(x==p->data)
			return p;
	return NULL;
}
void insert_at_middle(int y, node *p){
	node *moi;
	moi=taoNode(y);
	moi->next = p->next;
	p->next = moi;
}
void delete_at_begging(){
	node *p;
	p==head;
	head=head->next;
	p->next==NULL;
}
void delete_at_middle(int x){
	node *q;
	node *p=timKiem(x);
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
void delete_at_end(){
	node *p;
	p=head;
	while(p->next->next!=NULL)
	p=p->next;
	p->next = p->next->next;
	printf("\nNode delete %d", p->data);
}

int countNodes(){
	node *p;
	int s=0;
	for(p=head; p!=NULL; p=p->next)
		s++;
	return s;
}
