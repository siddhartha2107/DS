#include<iostream.h>
#include<conio.h>
#include<process.h>
struct Node
{ int info;
  Node *next;
} *start, *newptr, *save, *ptr;

Node *create_new_node(int);
void Insert_beg(Node*);
void Display(Node*);

void main()
{ clrscr();
start=NULL;
int inf;
char ch='y';
while(ch=='y'||ch=='Y')
{
  clrscr();
  cout<<"\n Enter info for new Node:- ";
  cin>>inf;
  cout<<"\n Creating new node!!! Press Enter to continue...";
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
  exit(0);
  }
  cout<<"\nInserting in beginning of the list... \n";
  Insert_beg(newptr);
  cout<<"\n\nNow the list is:-   ";
  Display(start);
  cout<<"Enter y or Y to enter more.. N to exit..\n";
  cin>>ch;
}
getch();

}
Node *create_new_node(int n)
{ ptr =new Node;
  ptr->info=n;
  ptr->next=NULL;
  return ptr;
}

void Insert_beg(Node* np)
{ if(start==NULL)
   start=np;
   else
   {
   save=start;
   start=np;
   np->next=save;
   }
}
void Display(Node* np)
{ while(np!=NULL)
  { cout<<np->info<<"->";
  np=np->next;
  }
  cout<<"!!!\n";
}
