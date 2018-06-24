#include <iostream>
#define MAXSIZE 5
using namespace std;

class CQueue
{
	int cq[MAXSIZE], rear, front;
public:
    CQueue()
    {
        front = rear = -1;
    }
	void insert();
	void del();
	void display();	
};

void CQueue::insert()
{
	int num;

	if((rear+1) % MAXSIZE == front)
	{
	   cout<<"CQueue is full"<<endl;
	   return;
	}

    cout<<"Enter the element to be inserted: ";
    cin>>num;

    if(front == -1 && rear == -1)
	   front=rear=0;
	else
	   rear=(rear+1) % MAXSIZE;

	cq[rear]=num;
}

void CQueue::del()
{
    int num;

	if(front == -1)
	{
		cout<<"CQueue is empty"<<endl;
	}
	else
	{
		num = cq[front];
		cout<<"del element is: " << num <<endl;

		if(front == rear)         // only one element
			front=rear = -1;
		else
			front=(front+1) % MAXSIZE;
	}
}

void CQueue::display()
{
    int i;
    if(front == -1)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }
    
    cout<<"The status of the queue --->"<<endl;

    for(i=front; i<=rear; i++)
        cout<<cq[i]<<endl;
    
    if(front > rear)
    {
        for(i=front; i < MAXSIZE; i++)
            cout<<cq[i]<<endl;
        
        for(i=0; i<=rear; i++)
            cout<<cq[i]<<endl;
    }
}


int main()
{
    CQueue q;
    char ch;
    int choice;

    for(;;)
    {
        cout<<"1. Insert"<<endl;
        cout<<"2. Delete"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
  
        switch(choice)
        {
            case 1: 
                q.insert();
                break;
            case 2: 
                q.del();
                break;
            case 3: 
                q.display();
                break;
            case 4: 
                return 0;
            default: 
                cout<<"Wrong choice!";            
        }
    }
}