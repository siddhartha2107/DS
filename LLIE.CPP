#include<iostream.h>
#include<conio.h>
#include<process.h>
struct Node
{ int info;
  Node *next;
} *start, *newptr, *save, *ptr,*rear;

Node *create_new_node(int);
void Insert_End(Node*);
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
  cout<<"Enter y or Y to enter more.. N to exit..\n";
  cin>>ch;
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
