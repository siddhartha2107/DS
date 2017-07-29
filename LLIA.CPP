#include<iostream.h>
#include<conio.h>
#include<process.h>
struct Node
{ int info;
  Node *next;
} *start, *newptr, *save, *ptr,*rear,*temp;

Node *create_new_node(int);
void Insert_End(Node*);
void Insert_Pos(Node*,pos);
void Display(Node*);

void main()
{ clrscr();
start=rear=NULL;
int inf;
char ch='y';
while(ch=='y'||ch=='Y')
{
  clrscr();
  cout<<"\n Enter info for new Node:- ";
  cin>>inf;
  cout<<"\n Creating new node!!! Press Enter to continue...";
  getch();
  newptr=create_new_node(inf);
  if(newptr!=NULL)
  {
  cout<<"\n\nNew Node Created...";
  getch();
  }
  else
  {
  cout<<"Cannot create new node.. Aborting";
  getch();
  exit(1);
  }
  cout<<"\nInserting in End of the list... \n";
  Insert_End(newptr);
  cout<<"\n\nNow the list is:-   ";
  Display(start);
  cout<<"Enter y or Y to enter more.. N to continue..\n";
  cin>>ch;
}
ch='y';
  while(ch=='y'||ch='Y')
  {
  cout<<"\nEnter y or Y to enter at any position..\n";
  cin>>ch;
  	if(ch=='y'||ch=='Y')
  	{
  		cout<<"Enter the position:- ";
  		cin>>pos;
  		Insert_Pos(newptr,pos);
  	}
  }

getch();

}
Node *create_new_node(int n)
{ ptr=new Node;
  ptr->info=n;
  ptr->next=NULL;
  return ptr;
}

void Insert_End(Node* np)
{ if(start==NULL)
   start=rear=np;
   else
   {
   rear->next=np;
   rear=np;
   }
}
void Display(Node* np)
{ while(np!=NULL)
  { cout<<np->info<<"->";
  np=np->next;
  }
  cout<<"!!!\n";
}
void Insert_Pos(Node* np,int n)
{
	temp=start;
	while(n>1)
	{
	 temp=temp->next; 	
	 n--;
	}
	if(start==NULL)
   start=rear=np;
   else
   {
   	 if(pos==1)
   	 {
   	  save=start;
	  start=np;
	  np->next=save;
   	 }
   	 else
   	 {
	    start->next=np;
	    np->next=temp;
   	 }
   }
}