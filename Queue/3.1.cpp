#include <iostream>
#define MAXSIZE 10

using namespace std;

class MenuQueue
{
	int front, rear;
	int queue[MAXSIZE];
public:
	void qinsert();
	int qdelete();
	void qdisplay();
	MenuQueue()
	{
		front = rear = -1;
	}
};

void MenuQueue :: qinsert()
{
	int num;
	
	if(rear == (MAXSIZE - 1))
	{
		cout << "QUEUE is full"<<endl;
		return;
	}
	else
	{
		 cout << "Enter the number: " ;
		 cin >> num;
		 queue[++rear] = num;

		 if(front == -1)
			front++;
	}
}

int MenuQueue :: qdelete()
{
	int num;

	if(front == -1)
	{
		cout << "The Queue is empty!"<<endl;
		return -1;
	}
	else
	{
		num = queue[front];

		if (front == rear)
			front = rear = -1;
		else
			front++;
		
		return num;
	}
}

void MenuQueue :: qdisplay()
{
	int i;

	if(front == -1)
		cout << "The Queue is empty";
	else
	{
		cout << "The status of the queue..." << endl;
		for(i=front; i<=rear; i++)
		{
			cout<< queue[i] << endl;;
		}
	}
}


int main()
{
	int ch;
	MenuQueue me;

	for(;;)
	{
		cout << endl << "1 - Insert" << endl;
		cout << "2 - Delete" << endl;
		cout << "3 - Display" << endl;
		cout << "4 - Exit" << endl;
		cout << "Enter your choice: ";
		cin >> ch;

		switch(ch)
		{
			case 1:
				me.qinsert();
				break;
			case 2:
				ch = me.qdelete();
				if (ch != -1)
					cout<<"Deleted element: "<<ch<<endl;
				break;
			case 3:
				me.qdisplay();
				break;
			case 4:
				return 0;
		}
	}
}