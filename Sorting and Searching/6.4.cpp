#include <iostream>
#define MAX 100

using namespace std;

class Quicksort
{
	int arr[MAX], n;
public: 
	void input();
	void output();
	void quick_sort(int[], int, int);
	int partition(int[], int, int);
	void swap(int *, int *);
};


void Quicksort::input()
{
	int i;

	cout<<"How many elements in the array: ";
	cin>>n;
	cout<<"Enter the elemennts: "<<endl;
	for(i=0; i<n; i++)
	{
		cin>>arr[i];
	}

	quick_sort(arr, 0, n-1);
}

void Quicksort::output()
{
	cout<<"Sorted Array -->"<<endl;

	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<endl;
	}
}

void Quicksort::swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Quicksort::quick_sort(int a[], int start, int end)
{
	if (start < end)
	{
		int pivot_index = partition(a, start, end);

		quick_sort(a, start, pivot_index-1);
		quick_sort(a, pivot_index+1, end);
	}
}

int Quicksort :: partition(int a[], int start, int end)
{
	int pivot = a[end];
	int p_index = start;

	for (int i=start; i<end; i++)
	{
		if(a[i] <= pivot)
		{
			swap(&a[i], &a[p_index]);
			p_index++;
		}
	}
	swap(&a[end], &a[p_index]);

	return p_index;
}


int main()
{
	Quicksort qs;

	qs.input();
	qs.output();

	return 0;
}