#include <iostream>

using namespace std;

class linear
{
	int a[100],i,x,n;
public:
	void getdata();
	void search();
};

void linear :: getdata()
{

	cout<<"Enter The Size Of The Arrray:\n";
	cin>>n;
	cout<<"Enter The Array:\n";
	for(i=0;i<n;i++)
		cin>>a[i];
}

void linear :: search()
{
	int flag=0;
	cout<<"Enter The Element To Be Search:\n";
	cin>>x;
	for(i=0;i<n;i++)
	{
		if(x==a[i])
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"Not Found";
    else
    	cout<<"Found at index: "<<i;
}

int main()
{
	linear li;
	li.getdata();
	li.search();

	return 0;
}