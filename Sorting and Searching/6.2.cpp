//6.2 selection sort

#include <iostream>
#define MAX 20

using namespace std;

class selection
{
	int a[MAX],i,j,n,temp;
public:
	void getdata();
	void sort();
};

void selection :: getdata()
{
	cout<<"Enter The Size Of Array:\n";
	cin>>n;
	cout<<"Enter The Elements:\n";
	for(i=0;i<n;i++)
		cin>>a[i];
}

void selection :: sort()
{
	int pass = n-1;
	for (i=0; i < pass; i++)
	{
		for (j=i+1; j<n; j++)
		{
			if(a[i] > a[j])
			{
			    temp = a[i];
			    a[i] = a[j];
			    a[j] = temp;
			}
		}
	}

	cout<<"The Sorted List Is:\n";
	for(i=0;i<n;i++)
		cout <<a[i] << " " << endl;
}

int main()
{
	selection sel;
	sel.getdata();
	sel.sort();
	return 0;
}