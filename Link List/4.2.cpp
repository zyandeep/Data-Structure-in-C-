#include <iostream>

using namespace std;

struct Node
{
	int info;
	Node *next;
};

class list
{
	Node *head;
	int count;
public:
	list(void)
	{
		head=NULL;
		count=0;
	} 
	void traverse(void);
	void insert_at_begin(int);
	void insert_at_end(int);
	void insert_at_spe(int, int);
};


void list::traverse(void)
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

void list::insert_at_begin(int item)
{
	Node *ptr;
	ptr=new Node;
	ptr->info=item;
	count++;

	if(head == NULL)
	{
		ptr->next=NULL;
		head=ptr;
	}
	else
	{
		ptr->next=head;
		head=ptr;	
	}
		
}

void list::insert_at_end(int item)
{
	Node *ptr, *temp;
	temp=new Node;
	temp->info=item;
	temp->next=NULL;
	count++;

	if(head == NULL)
	{
		head=temp;
	}
	else
	{
		for (ptr=head; ptr->next != NULL; ptr=ptr->next);

		ptr->next=temp;	
	}
}

void list::insert_at_spe(int item, int pos)
{
	int i; 
	Node *temp, *ptr;

	// check if the positon is invalid
	if (pos < 1 || pos > count+1)
	{
		cout<<"Invalid position!"<<endl;
		return;
	}	
	if (pos==1)
	{
		insert_at_begin(item);
		return;
	}

	// create the new node
	temp=new Node;
	temp->info=item;
	count++;
	
	// go to n-1 th node
	for (ptr=head, i = 1; i < pos-1; i++, ptr=ptr->next);

	temp->next = ptr->next;
	ptr->next = temp;
}

int main(void)
{
	int choice,item,pos;
	char ch;
	list l;
	do
	{
		cout<<"\n"<<"1. Insert at beginning"<<endl;
		cout<<"2. Insert at end"<<endl;
		cout<<"3. Insert at specific position"<<endl;
		cout<<"4. Traverse"<<endl;
		cout<<"5. Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: 
				cout<<"Enter the item: "<<endl;
				cin>>item;
				l.insert_at_begin(item);
				break;
			case 2: 
				cout<<"Enter the item: "<<endl;
				cin>>item;
				l.insert_at_end(item);
				break;
			case 3:
				 cout<<"Enter the item: "<<endl;
				 cin>>item;
				 cout<<"Enter the position: "<<endl;
				 cin>>pos;
				 l.insert_at_spe(item, pos);
				break;
			case 4: 
				l.traverse();
				break;
			case 5: 
				return 0;
		}

		cout<<endl<<"Do you want to continue(y/n) ";
		cin>>ch;

	} while((ch=='Y')||(ch=='y'));
}
