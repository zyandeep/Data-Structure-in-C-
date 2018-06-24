#include <iostream>

using namespace std;

class Power
{
	int i,n,p,r;
public:
	void getdata();
	int result();

};

void Power::getdata()
{
	cout<<"Enter the number & the Power: ";
	cin>>n>>p;
}

int Power::result()
{
	r=1;
	for(i=1;i<=p;i++)
	r=n*r;

	return (r);
}

int main()
{
	Power s;
	s.getdata();
	cout<<"The Power of the number is "<<s.result()<<endl;
	
	return 0;
}