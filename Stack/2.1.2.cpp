#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Stack
{
    Node *top;
public:
    Stack()
    {
        top=NULL;
    }
    void push();
    void pop();
    void display();
};


void Stack::push()              // Inserts at the beginning
{
    Node *temp = new Node;

    cout<<"Enter the number to insert: ";
    cin>>temp->data;

    temp->next = top;
    top = temp;
}

void Stack::pop()
{
    Node *temp;

    if(top == NULL)
    {
        cout<<"Stack overflow!"<<endl;
    }
    else
    {
        cout<<"The delete element is: "<< top->data<<endl;
        
        temp = top;
        top=top->next;
        delete temp;
    }
}

void Stack::display()
{
    Node *temp;

    if(top == NULL)
    {
        cout<<"Stack is empty!"<<endl;
    }
    else
    {
        cout<<"Items in the stack -->"<<endl;
        for (temp=top; temp != NULL; temp=temp->next)
            cout << temp->data <<endl;
    }
}


int main()
{
    Stack s;
    int choice;

    for(;;)
    {
        cout<<"1. PUSH "<<endl;
        cout<<"2. POP "<<endl;
        cout<<"3. TRAVERSE "<<endl;
        cout<<"4. EXIT "<<endl;
        cout<<"Enter your choice-->"<<endl;
        cin>>choice;
        
        switch(choice)
        {
            case 1: 
                s.push();
                break;
            case 2: 
                s.pop();
                break;
            case 3: 
                s.display();
                break;
            case 4:
                return 0;
        }
    }
}