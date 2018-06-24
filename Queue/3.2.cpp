#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *next;
};

class Queue
{
	Node *front, *rear;
public:
	Queue()
	{
		front=rear=NULL;
	}
	void insert();
	void del();
	void display();
};


void Queue::insert()				// inserts at the end
{
	Node *temp = new Node;
	temp->next = NULL;

	cout<<"Enter the data: ";
	cin>>temp->data;

	if(front == NULL && rear==NULL)			// queue is empty
	{
		front=rear=temp;
	}
	else
	{
		rear->next = temp;
		rear=temp;
	}
}

void Queue::del()
{
	Node *temp;
	int value;
	
	if(front == NULL)
	{
		cout<<"Queue is Empty!"<<endl;
		return;
	}

	temp=front;
	if(front == rear)			// Only one element
	{
		front = rear = NULL;
	}
	else
	{
		front = front->next;
	}

	cout<<"Deleted element is: "<<temp->data <<endl;
	delete temp;
}

void Queue::display()
{
	Node *temp;

	if(front == NULL && rear == NULL)
	{
		cout<<"Queue is Empty!"<<endl;
		return;
	}

	temp=front;
	while(temp != NULL)
	{
		cout<<endl<<"no = "<<temp->data;
		temp=temp->next;
	}
}


int main()
{
	int ch;
	Queue lq;

	for(;;)
	{
		cout<<"1. Insert "<<endl;
		cout<<"2. Delete "<<endl;
		cout<<"3. Traverse "<<endl;
		cout<<"4. Quit "<<endl;
		cout<<"Enter Your Choice: ";
		cin>>ch;

		switch(ch)
		{
			case 1: 
				lq.insert();
				break;
			case 2: 
				lq.del();
				break;
			case 3: 
				lq.display();
				break;
			case 4:
				return 0;
			default: 
				cout<<"Wrong Choice!!";
		}
	}
}