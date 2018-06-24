#include <iostream>
#define MAXSIZE 5

using namespace std;

class Stack
{
	int stack[MAXSIZE];
	int top;
public:
	Stack()
	{
		top = -1;
	}
	int pop();
	void push(int);
	void traverse();
};

void Stack::push(int item)
{
	if(top == MAXSIZE-1)
	{
		cout << "Stack Overflow!" << endl;
		return;
	}
	stack[++top] = item;
}

int Stack::pop()
{
	if(top == -1)
	{
		cout << "Stack Underflow!" << endl;
		return -1;
	}
	return stack[top--];
}

void Stack::traverse()
{
	if(top == -1)
	{
		cout << "The stack is empty"<<endl;
		return;
	}

	cout << "The items in the stack are..." << endl;
	int i;

	for(i = top; i >= 0; i--)
		cout << stack[i] << endl;
}

int main()
{
	Stack s;
	int answer, item;

	for(;;)
	{
		cout << "1. Push."<< endl;
		cout << "2. Pop."<< endl;
		cout << "3. Traverse" << endl;
		cout << "4. Quit" << endl;
		cout << "Enter your choice: "<< endl;
		cout << "> ";
		cin >> answer;

		switch(answer)
		{
			case 1:
				cout << "Enter the element: ";
				cin >> item;
				s.push(item);
				break;
			case 2:
				item = s.pop();

				if(item != -1)
					cout << item << " has been poped off"<<endl;

				break;
			case 3:
				cout << "Elements in the stack: "<< endl;
				s.traverse();
				break;
			case 4:
				return 0;
				
		}
	}
}