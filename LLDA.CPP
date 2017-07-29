#include<iostream.h>
#include<conio.h>
#include<process.h>
struct Node
{ int info;
  Node *next;
} *start, *newptr, *save, *ptr,*rear,*temp,*temp2;

Node *create_new_node(int);
void Insert_End(Node*);
void Display(Node*);
void DelNode(int);
void main()
{ clrscr();
start=rear=NULL;
int inf,nno;
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
do
{ cout<<"To delete an element enter y or Y.. N to exit..\n";
  cin>>ch;
  if(ch=='y'||ch=='Y')
      { cout<<"Enter the node no. to be deleted: ";
	cin>>nno;
	DelNode(nno);
	Display(start);
      }
 else
 {
  Display(start);
 }
}while(ch=='y'||ch=='Y');
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
void DelNode(int n2)
{
  temp2=temp=start;
  while(n2>1)
  { temp=temp->next;
    n2--;
    if(n2!=1)
    temp2=temp;
  }
  cout<<"\n\nn2= "<<n2<<"\n\n";
  if(temp==start)
  {  cout<<"\n\nstart\n\n";
     start=start->next;
     ptr=temp;
     delete ptr;
  }
  else if(temp==rear)
  {
    rear=temp2;
    rear->next=NULL;
  }
  else
  { ptr=temp;
    temp=temp->next;
    delete ptr;
    temp2->next=temp;
  }
}
