#include<iostream.h>
#include<conio.h>
 
using namespace std;
 
 
int STACK[MAX],TOP;
void initStack(){
    TOP=-1;
}
int isEmpty(){
    if(TOP==-1)
        return 1;
    else
        return 0;
}
int isFull(){
    if(TOP==MAX-1)
        return 1;
    else   
        return 0;
}
 
void push(int num)
{
    if(isFull()){
        cout<<"STACK is FULL.\n";
        return; 
    }
    ++TOP;
    STACK[TOP]=num;
    cout<<num<<" has been inserted.\n";
}
 
void display()
{
    int i;
    if(isEmpty()){
        cout<<"STACK is EMPTY.\n";
        return;
    }
    for(i=TOP;i>=0;i--){
        cout<<STACK[i]<<" ";
    }
    cout<<endl;
}
void pop(){
    int temp;
    if(isEmpty()){
        cout<<"STACK is EMPTY.\n";
        return;
    }
     
    temp=STACK[TOP];
    TOP--;
    cout<<temp<<" has been deleted.\n";   
}
void main()
{
    int num;
    initStack();
    char ch;
    do{
            int a;
            cout<<"Chosse \n1.push\n"<<"2.pop\n"<<"3.display\n";
            cout<<"Please enter your choice: ";
            cin>>a;
            switch(a)
            {
                case 1:
                    cout<<"Enter an Integer Number: ";
                    cin>>num;
                    push(num);
                break;
                 
                case 2: 
                    pop();
                    break;
                 
                case 3: 
                    display();
                    break;
                 
                default : 
                cout<<"An Invalid Choice!!!\n";
                 
                 
            }
            cout<<"Do you want to continue ? ";
            cin>>ch;                      
            }while(ch=='Y'||ch=='y');
    getch();
}