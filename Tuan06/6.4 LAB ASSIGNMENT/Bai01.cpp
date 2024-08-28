#include<stdio.h>
#include<stdlib.h>
int count=0;
struct node
{
	int data;
	struct node *next;
}*head,*newn,*trav;
//----------------------------------------------------------
void insert_at_begning(int value);
void insert_at_end(int value);
void create_list();
int display();
int main()
{
	int ch=0;
	char ch1;
	
	head=NULL;
	while(1)
	{
		printf("\n*** LINKED LIST ***\n");
		printf("\n1.Create linked list");
		printf("\n2.Insertion at begning of linked list");
		printf("\n3.Isertion at the end of linked list");
		printf("\n4.Insertion at the middle where you want");
	
		printf("\n0.exit\n");
		printf("\nEnter the choice of operation to perform on linked list:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				{
					do{
						create_list();
						display();
						fflush(stdin);
						printf("do you want to create list ,y / n: ");
						scanf("%c",&ch1);
					}while(ch1=='y');
					
					break;
				}
			case 2:
				{
					int value;
					printf("\nenter the value to be inserted");
					scanf("%d",&value);
					insert_at_begning(value);
					display();
					break;
				}
			case 3:
				{
					int value;
					printf("\nenter value to be inserted");
					scanf("%d",&value);
					insert_at_end(value);
					display();
					break;
				}
				
			//...
			
			case 0:
			{
				exit(1);
			}
			default:printf("\n****Please enter correct choice****\n");
		}
	}
}

void create_list()
{
	int value;
	struct node *temp;
	temp=head;
	newn=(struct node *)malloc(sizeof (struct node));
	printf("\nEnter the value to be inserted:");
	scanf("%d",&value);
	newn->data=value;
	if(head==NULL)
	{
		head=newn;
		head->next=NULL;
		count++;
	}
	else
	{
		insert_at_end(value);
		count++;
	}
}
//----------------------------------------------------
void insert_at_begning(int value)
{
	newn=(struct node *)malloc(sizeof (struct node));
	newn->data=value;
	if(head==NULL)
	{
		head=newn;
		head->next=NULL;
		count++;
	}
	else
	{
		newn->next=head;
		head=newn;
		count++;
	}
}
//----------------------------------------------------------
void insert_at_end(int value)
{
	struct node *temp;
	temp=head;
	newn=(struct node *)malloc(sizeof (struct node));
	newn->data=value;
	if(head==NULL)
	{
		head=newn;
		head->next=NULL;
		count++;
	}
	else
	{
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=newn;
		newn->next=NULL;
		count++;
	}
}
//------------------------------------------------------
int display()
{
	trav=head;
	if(trav==NULL)
	{
		printf("\nList is Empty\n");
		return 0;
	}
	else
	{
		printf("\n\nElements in the Single Linked List is %d:\n",count);
		while(trav!=NULL)
		{
			printf(" -> %d ",trav->data);
			trav=trav->next;
		}
		printf("\n");
		return 1;
	}
}
//---------------------------------------------------------------

