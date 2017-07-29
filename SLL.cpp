#include <iostream>
#include <stdio.h>
#include <conio.h>
struct node
{
    int data;
    node *next;
}*front=NULL,*rear=NULL, *ptr = NULL, *np = NULL;
void push(int x)
{
    np=new node;
    np->data=x;
    np->next=NULL;
    if(front==NULL)
    {
        front=rear=np;
        rear->next = NULL;
    }
    else
    {
        rear->next=np;
        rear=np;
        rear->next=NULL;
    }
}
int remove()
{
    int x;
    if (front==NULL)
    {
        cout<<"empty queue\n";
    }
    else
    {
        ptr=front;
        x=ptr->data;
        front=front->next;
        delete(ptr);
        return(x);
    }
}
void main()
{
    int n,c=0,x;
    cout<<"Enter the number of values to be pushed into queue\n";
    cin>>n;
    while(c<n)
    {
	cout<<"Enter the value to be entered into queue\n";
	cin>>x;
        push(x);
        c++;
    }
    cout<<"\n\nRemove Value?\n\n";
    char rem;
    rem='Y';
    while(rem=='y'||rem--'Y')
    {
        cin>>rem;
        if(front==NULL)
            break;
        if(rem='Y'||rem='y')
        {
            if(front != NULL)
            cout<<remove()<<"\n";    
        }
    }
    getch();
}