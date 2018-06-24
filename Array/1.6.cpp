#include <iostream>
using namespace std;
#define SIZE 10

class Menu
{
	int a[SIZE], count;
	int array1[SIZE],array2[SIZE],array3[SIZE * 2];

public: 
	void bubble_sort(int[], int);
	void insert();
	void del();
	void traversal();
	void merged();
	Menu()
	{
		count=0;
		for (int i = 0; i < SIZE; i++)		// array is empty
			a[i]=0;
	}
};

int main()
{
	int n;
	Menu mn;
	for(;;)
	{
		cout<<endl<<"*** YOUR CHOICES ARE ***"<<endl;
		cout<<"1. Insert\n";
		cout<<"2. Delete\n";
		cout<<"3. Traverse\n";
		cout<<"4. Merged\n";
		cout<<"5. Exit\n";
		cout<<"NOW ENTER YOUR CHOICE :"<<endl;
		cin>>n;
	
		switch(n)
		{
			case 1:
				mn.insert();
				break;
			case 2:
				mn.del();
				break;
			case 3:
				mn.traversal();
				break;
			case 4:
				mn.merged();
				break;
			case 5:
				return 0;
			default:
				cout<<"SORRY!YOUR CHOICE IS INVALID!!"<<endl;
		}
	}
}

void Menu::insert()				
{
	int num, pos, i, temp;

	if(count < 10)
	{
		cout<<"Enter the number and its positon: ";
		cin>>num>>pos;
		pos--;

		if(a[pos] == 0)
			a[pos]=num;
		else
		{
			for (i = pos; i < SIZE; i++)
			{
				temp=a[i];
				a[i]=num;
				num=temp;
			}
		}
		count++;
	}
	else
	{
		cout<<"The Array is Full";
	}
}

void Menu::traversal()		
{
	int i;
	for(i=0; i<SIZE; i++)
	{
		cout<<endl<<a[i];
	}
}

void Menu::del()				//Body of del function
{
	int item, i, flag=0, pos;
	cout<<"Enter the number to delete : "<<endl;
	cin>>item;

	// locate the element in the array
	for (i=0; i < SIZE; i++)
	{
		if(a[i]==item)
		{
			flag=1;
			pos=i;
			break;
		}
	}

	if(flag)
	{
		for(i=pos; i<SIZE-1; i++)
		{
			a[i]=a[i+1];
		}
		a[i] = 0;
		count--;
	}
	else
	{
		cout<<"The numner is not in list"<<endl;
	}
}

void Menu::merged()
{
	int i, j, k;

	cout<<"Enter the 1st array: "<<endl;
	for (i = 0; i < SIZE; i++)
		cin>>array1[i];

	cout<<"Enter the 2nd array: "<<endl;
	for (i = 0; i < SIZE; i++)
		cin>>array2[i];

	// sort the arrays in ascending order
	bubble_sort(array1, SIZE);
	bubble_sort(array2, SIZE);

	// Sorting while merging
	for (i=0, j=0, k=0; i < SIZE && j < SIZE; )
	{
		if( array1[i] < array2[j] )
		{
			array3[k] = array1[i];
			i++;
		}
		else if ( array2[j] < array1[i] )
		{
			array3[k] = array2[j];
			j++;
		}
		else
		{
			array3[k] = array1[i];
			i++;
			j++;
		}
		k++;
	}

	if(i == SIZE)		// 1st array has been fully copied
	{
		while(j < SIZE)
		{
			array3[k++] = array2[j++];
		}
	}
	else if (j == SIZE)   // 2nd array has been fully copied
	{
		while(i < SIZE)
		{
			array3[k++] = array2[i++];
		}
	}

	// Display the sorted merged array
	cout<<"The sorted merged array--->" <<endl;
	for (i = 0; i < k; i++)
	{
		cout<<array3[i]<<" ";
	}

	cout<<"\n";
}


void Menu :: bubble_sort(int arr[], int n)
{
	int i, pass, temp;

	for (pass = n-1; pass >= 1; pass--)
	{
		for (i = 0; i < pass; i++)
		{
			if (arr[i] > arr[i+1])
			{
				temp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = temp;
			}
		}
	}
}