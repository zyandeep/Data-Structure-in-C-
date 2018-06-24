//6.3 insertion sort

#include <iostream>

using namespace std;

class insertion
{
	int a[100],n,i,j,k,temp;
public :
	void getdata();
	void sort();
};

void insertion :: getdata()
{
	cout<<"Enter The Size of The Array:\n";
	cin>>n;
	cout<<"Enter The Elements:\n";
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
}

void insertion :: sort()
{
	for(i=1; i<n; i++)
	{
		temp=a[i];
		j=i-1;
		while(temp<a[j] && j>=0)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
	cout<<"\n\n\nThe Final Sorted Array Is: \n";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<" "<<endl;
	}
}

int main()
{
	insertion ins;
	ins.getdata();
	ins.sort();

	return 0;
}