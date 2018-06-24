#include <iostream>

using namespace std;

struct Node
{
	int num;
	Node *next;
};

class link_lst
{
	Node *head, *temp, *ptr;
	int count,ch;

	public:
		link_lst()
		{
			count=0;
			ch=1;
			head=NULL;
		}

		void insert(void);
		void output(void);
};

void link_lst::insert(void)
{
	while(ch)
	{
		temp=new Node;
		temp->next=NULL;
		count++;
		cout<<"Enter the item: ";
		cin>>temp->num;
		if(head != NULL)
		{
			for (ptr=head; ptr->next != NULL; ptr=ptr->next);

			ptr->next=temp;
		}
		else
		{
			head = temp;
		}
		cout<<"Do you want to continue (type 0 or 1): ";
		cin>>ch;
	}
}

void link_lst::output(void)
{
	ptr=head;
	cout<<"The items in the list: "<<endl;
	while (ptr!= NULL)
	{
		cout<<endl<<ptr->num;
		ptr=ptr->next;
	}
	cout<<endl<<"No. of nodes = "<<count<<endl;
}

int main(void)
{
	link_lst l;
	l.insert();
	l.output();
	
	return 0;
}
