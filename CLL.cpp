#include<iostream.h>
#include<conio.h>

struct node
{
    int info;
    struct node *next;
}*last;

class circular_llist
{
    public:
        void create_node(int value);
        void add_begin(int value);
        void add_after(int value, int position);
        void delete_element(int value);
        void search_element(int value);
        void display_list();
        void update();
        circular_llist()
        {
            last = NULL;           
        }
};

void main()
{
    int choice, element, position;
    circular_llist cl;
    while(1)
    {
        cout<<"\nCircular singly linked list\n";
        cout<<"1->Create Node\n";
        cout<<"2->Add at beginning\n";
        cout<<"3->Add after\n";
        cout<<"4->Delete\n";;
        cout<<"5->Search\n";
        cout<<"6->Display\n";
        cout<<"7->Update\n";
        cout<<"8->Quit\n";
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter the element: ";
            cin>>element;
            cl.create_node(element);
            cout<<"\n";
            break;
        case 2:
            cout<<"Enter the element: ";
            cin>>element;
            cl.add_begin(element);
            cout<<"\n";
            break;
        case 3:
            cout<<"Enter the element: ";
            cin>>element;
            cout<<"Insert element after position: ";
            cin>>position;
            cl.add_after(element, position);
            cout<<"\n";
            break;
        case 4:
            if (last == NULL)
            {
                cout<<"List is empty, nothing to delete\n";
                break;
            }
            cout<<"Enter the element for deletion: ";
            cin>>element;
            cl.delete_element(element);
            cout<<"\n";
            break;
        case 5:
            if (last == NULL)
            {
                cout<<"List Empty!! Can't search\n";
                break;
            }
            cout<<"Enter the element to be searched: ";
            cin>>element;
            cl.search_element(element);
            cout<<"\n";
            break;
        case 6:
            cl.display_list();
            break;
        case 7:
            cl.update();
            break;
        case 8:
            exit(1);
            break;
        default:
            cout<<"Wrong choice\n";
        }
    }
getch();
}
 




void circular_llist::create_node(int value)
{
    struct node *temp;
    temp = new(struct node);
    temp->info = value;
    if (last == NULL)
    {
        last = temp;
        temp->next = last;   
    }
    else
    {
        temp->next = last->next; 
        last->next = temp;
        last = temp;
    }
}
 




void circular_llist::add_begin(int value)
{
    if (last == NULL)
    {
        cout<<"First Create the list\n";
        return;
    }
    struct node *temp;
    temp = new(struct node);
    temp->info = value;
    temp->next = last->next;
    last->next = temp;
}





void circular_llist::add_after(int value, int pos)
{
    if (last == NULL)
    {
        cout<<"First Create the list\n";
        return;
    }
    struct node *temp, *s;
    s = last->next;
    for (int i = 0;i < pos-1;i++)
    {
        s = s->next;
        if (s == last->next)
        {
            cout<<"There are less than ";
            cout<<pos<<" in the list\n";
            return;
        }
    }
    temp = new(struct node);
    temp->next = s->next;
    temp->info = value;
    s->next = temp;

    if (s == last)
    { 
        last=temp;
    }
}
 




void circular_llist::delete_element(int value)
{
    struct node *temp, *s;
    s = last->next;
    if (last->next == last && last->info == value)  
    {
        temp = last;
        last = NULL;
        delete temp;
        return;
    }
    if (s->info == value) 
    {
        temp = s;
        last->next = s->next;
        delete temp;
        return;
    }
    while (s->next != last)


        if (s->next->info == value)    
        {
            temp = s->next;
            s->next = temp->next;
            delete temp;
            cout<<"Element "<<value;
            cout<<" deleted from the list\n";
            return;
        }
        s = s->next;
    }

    if (s->next->info == value)    
    {
        temp = s->next;
        s->next = last->next;
        free(temp);		
        last = s;
        return;
    }
    cout<<"Element "<<value<<" not found in the list\n";
}
 




void circular_llist::search_element(int value)
{
    struct node *s;
    int counter = 0;
    s = last->next;
    while (s != last)
    {
        counter++;
        if (s->info == value)    
        {
            cout<<"Element "<<value; 
            cout<<" found at position "<<counter<<"\n";
            return;
        }
        s = s->next;
    }
    if (s->info == value)    
    {
        counter++;             
        cout<<"Element "<<value;
        cout<<" found at position "<<counter<<"\n";
        return;
    }
    cout<<"Element "<<value<<" not found in the list\n";
}
 




void circular_llist::display_list()
{
    struct node *s;
    if (last == NULL)
    {
        cout<<"List is empty, nothing to display\n";
        return;
    }
    s = last->next;
    cout<<"Circular Link List: \n";
    while (s != last)
    {
        cout<<s->info<<"->";
        s = s->next;
    }
    cout<<s->info<<"\n";
}
 




void circular_llist::update()
{
    int value, pos, i;
    if (last == NULL)
    {
        cout<<"List is empty, nothing to update\n";
        return;
    }
    cout<<"Enter the node position to be updated: ";
    cin>>pos;
    cout<<"Enter the new value: ";
    cin>>value;
    struct node *s;
    s = last->next;
    for (i = 0;i < pos - 1;i++)
    {
        if (s == last)
        {
            cout<<"There are less than "<<pos<<" elements\n";
            return;
        }
        s = s->next;
    }
    s->info = value;  
    cout<<"Node Updated\n";
} 