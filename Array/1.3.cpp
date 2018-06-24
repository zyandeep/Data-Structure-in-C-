#include <iostream>

using namespace std;

class Fact
{
	int number;
	long result;
public:
	Fact()
	{
		result=1L;
	}
	void calc_fact(int);
	void input();
	void output();
};


int main(void)
{
	Fact f;
	f.input();
	f.output();

	return 0;
}


void Fact :: calc_fact(int number)
{
	if (number == 0)
		result = 1L;

	for (int i = number; i > 1; i--)
	{
		result *= i;
	}
}

void Fact::input()
{
	cout<<"Enter the number: ";
	cin>>number;
	calc_fact(number);
}

void Fact::output()
{
	cout<<"The factorial of "<<number<<" is "<<result<<endl;
}