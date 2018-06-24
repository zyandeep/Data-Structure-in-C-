//6.5 binary search

#include <iostream>

using namespace std;

class binary
{
	int a[100],x,n,i,big,end,mid;
public:
	void getdata();
	void search();
};

void binary :: getdata()
{
	cout<<"Enter The Size Of The Arrray:\n";
	cin>>n;
	cout<<"Enter The Array in Ascending Order :\n";
	for(i=0;i<n;i++)
		cin>>a[i];
}

void binary :: search()
{
	cout<<"Enter The Element To Be Search:\n";
	cin>>x;
	big=0;
	end=n-1;
	while(big <= end)
	{
		mid=(big+end)/2;
		if(x<a[mid])
			end=mid-1;
		else if(x > a[mid])
			big=mid+1;
		else
			break;
	}
	if(x==a[mid])
		cout<<"The element is at position: "<<mid;
    else
    	cout<<"The element was not found";
}

int main()
{
	binary bi;
	bi.getdata();
	bi.search();
	
	return 0;
}