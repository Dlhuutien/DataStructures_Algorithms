#include<conio.h>
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
struct 	Node
{	
int 	Data;
	Node * pNext;
};

struct	List
{
Node *pHead,*pTail;
};

Node* GetNode(int x)
{	
Node *p;
	p=new Node;
	if (p==NULL)
		{	
		printf("Khong du bo nho");
			return NULL;
		}
	p->Data=x;
	p->pNext=NULL;
	return p;
}

void Init(List &L)
{
	L.pHead = L.pTail = NULL;
}

void AddHead(List &L, Node* p)
{	if (L.pHead == NULL)  // DS r?ng
		L.pHead = L.pTail = p;	
	else 
	{	p->pNext = L.pHead;  
		L.pHead = p; 	
	}
}
void AddFirst(List &L, int x)
{	
Node *p = GetNode(x);
	if (L.pHead == NULL)  // DS r?ng
		L.pHead = L.pTail = p;	
	else 
	{	p->pNext = L.pHead;  
		L.pHead = p; 	
	}
}

void addTail(List &L, Node *p)
{	
if (L.pHead == NULL)  
		L.pHead = L.pTail = p;
	else
	{
		L.pTail->pNext = p;
		L.pTail = p ;
	}	
}
void AddLast(List &L, int x)
{	Node * p = GetNode (x);
if (L.pHead == NULL)  
		L.pHead = L.pTail = p;
	else
	{	L.pTail->pNext = p;
		L.pTail = p ;
	}	
}
void CreateListHead (List &L, int &n)
{
int x; Node *p;
 	printf("Nhap so node n = ");
 	srand (time (NULL));
 	for (int i=1; i<=n; i++)
  	{	
    		x = rand()%90 +10;
		p = GetNode (x); 
AddHead (L,p);	
  	}
}	

void CreateListTail (List &L, int &n)
{
	int x; Node *p;
 	printf("Nhap so node n = "); scanf("%d", &n);
 	srand (time (NULL));
 	for (int i=1; i<=n; i++)
  	{	
    		x = rand()%199 - 99;
		// x   [-99 .. 99]
		p = GetNode (x); 
AddTail (L,p);	 
  	}
}

void PrintList (List L)
{	
for(Node* p = L.pHead; p!=NULL; p=p->pNext)
		cout<<p->info<<" ";
}
int main(){
	
}
