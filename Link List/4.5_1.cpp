#include <iostream>

using namespace std;

struct Node
{
   int data;
   Node *next;
};

class cir_ll
{
	Node *head;
    int count;

public: 
	void insert_at_end(int);             // inserts at the end
    void delt(int);                      // delete from any position                  
	void display();
	int select();

	cir_ll()
	{
        count=0;
		head=NULL;
	}
};

int main(void)
{
	int choice, item, pos;
	cir_ll ls;
	
	for(;;)
	{
		choice=ls.select();
		switch(choice)
		{
			case 1:
				cout<<"Enter the item: ";
				cin>>item;
				ls.insert_at_end(item); 
                break; 
			case 2:
				cout<<"Enter the positon: ";
				cin>>pos;
				ls.delt(pos); 
                break;
			case 3:
				ls.display();
				break;
			case 4:
				return 0;
		}
	}
}

int cir_ll :: select()
{
	int selection;
	do
	{
		cout<<endl<<"Enter 1: Insert at the end";
		cout<<endl<<"Enter 2: Delete a node";
		cout<<endl<<"Enter 3: Display the list";
		cout<<endl<<"Enter 4: Exit";
		cout<<endl<<"Enter your choice: ";
		cin>>selection;
	} while(selection<1 || selection>4);
	
	return selection;
}

void cir_ll :: insert_at_end(int item)
{
    Node *ptr, *temp;
    temp=new Node;
    temp->data=item;
    count++;

    if (head == NULL)       // empty list
    {
        head=temp;
        head->next=head;
    }
    else
    {
        // go to the last node
        for (ptr=head; ptr->next != head; ptr=ptr->next);

        ptr->next=temp;
        temp->next=head;
    }
}

void cir_ll :: display(void)
{
    Node *ptr;

    if (head == NULL)
    {
        cout << "The linked list is empty!!"<<endl;
        return;
    }

    cout<<"The items in the list: "<<endl;
    ptr=head;

    do
    {
        cout << ptr->data << endl;
        ptr=ptr->next;

    } while(ptr != head);
}

void cir_ll :: delt(int pos)
{
    int i;
    Node *ptr, *temp;

    if (head == NULL)
    {
        cout<<"The list is empty!"<<"\n";
        return;
    }

    if (pos < 1 || pos > count)
    {
        cout<<"Invalid position!"<<endl;
        return;
    }
    
    else if (pos==1)        // delete at the beginning
    {
        temp=head;

        if(head->next == head)        // Only one node in the list
        {
            head=NULL;
        }
        else
        {
            // go to the last node and change its next pointer to point to the
            // new head node

            for (ptr=head; ptr->next != head; ptr=ptr->next);

            head=head->next;
            ptr->next=head;
        }

    }
    
    else            // delete elsewhere
    {
        for(i=1, ptr=head; i < pos-1; i++, ptr=ptr->next);

        temp = ptr->next;
        ptr->next = temp->next;
    }

    cout<<"Deleted element is = "<< temp->data <<endl;
    delete temp;
    count--;
}