#include <iostream>

using namespace std;

class Sum
{
	int sum;
public:
	Sum(void)
	{
		sum = 0;
	}

	void cal_sum(int i)
	{
		if(i > 10)
			return;
		sum += i;
		cal_sum(++i);
	}

	void display()
	{
		cout << "The sum of 1st 10 natural numbers...\n";
		cout << sum <<endl;
	}
};


int main()
{
	Sum s;
	s.cal_sum(1);
	s.display();
	
	return 0;
}