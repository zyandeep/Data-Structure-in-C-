#include <iostream>
using namespace std;

class Prime
{
	int number;
	char is_prime;
public:
	Prime()
	{
		is_prime=1;
	}
	void check_prime(int);
	void input();
	void output();	
};


void Prime::input()
{
	cout<<"Enter the number: ";
	cin>>number;
	check_prime(number);
}

void Prime::output()
{
	if (is_prime == 1)
		cout<<number<<" is a Prime number."<<endl;
	else
		cout<<number<<" is not a Prime number."<<endl;
}

void Prime::check_prime(int number)
{
	if (number <= 1)
		is_prime=0;
	else
	{
		for(int i=2; i <= number/2; i++)
		{
			if(number%i == 0)
			{
				is_prime=0;
				break;
			}
		}
	}
}


int main()
{
	Prime p;
	p.input();
	p.output();

	return 0;
}