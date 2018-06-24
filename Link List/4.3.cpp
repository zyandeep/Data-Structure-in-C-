#include <iostream>

using namespace std;

struct Node
{
	int info;
	Node *next;
};

class llist
{
	Node *head;
	int count;

public:
	llist(void)
	{
		head=NULL;
		count=0;
	} 
	void insert(void);		// always inserts at the end
	void traverse(void);
	void delete_node(void);
};


void llist::traverse(void)
{
	Node *start;

	if (head == NULL)
	{
		cout << "The linked list is empty!";
		return;
	}
	start = head;
	cout<<"The items in the list: "<<endl;
	while (start!= NULL)
	{
		cout<<endl<<start->info;
		start=start->next;
	}
}


void llist::insert(void)
{
	Node *temp, *ptr;
	temp=new Node;
	temp->next=NULL;
	count++;
	cout<<"Enter the item: ";
	cin>>temp->info;
	
	if(head != NULL)
	{
		for (ptr=head; ptr->next != NULL; ptr=ptr->next);

		ptr->next=temp;
	}
	else
	{
		head = temp;
	}
}


void llist::delete_node(void)
{
	int pos, i;
	Node *ptr, *temp;

	if (head == NULL)
	{
		cout<<"The list is empty!"<<"\n";
		return;
	}
	
	cout<<"Enter the position: "<<endl;
    cin>>pos;

	if (pos < 1 || pos > count)
	{
		cout<<"Invalid position!"<<endl;
	}
	else if (pos==1)
	{
		cout<<"Deleted element is = "<< head->info <<endl;
		temp=head;
		head=head->next;
		delete temp;
		count--;
	}
	else
	{
		for(i=1, ptr=head; i < pos-1; i++, ptr=ptr->next);

		temp = ptr->next;
		cout<<"Deleted element is = "<< temp->info <<endl;
		ptr->next = temp->next;
		delete temp;
		count--;
	}

}


int main(void)
{
	int choice,item,pos;
	char ch;
	llist l;
	do
	{
		cout<<"1. Insert a node"<<endl;
		cout<<"2. Delete a node"<<endl;
		cout<<"3. Display the list"<<endl;
		cout<<"4. Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: 
				l.insert();
				break;
			case 2:
				l.delete_node(); 
				break;
			case 3: 
				l.traverse();
				break;
			case 4: 
				return 0;
		}

		cout<<endl<<"Do you want to continue(y/n) ";
		cin>>ch;

	} while((ch=='Y')||(ch=='y'));
}
