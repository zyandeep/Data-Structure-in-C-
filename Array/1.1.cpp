#include <iostream>

using namespace std;

class Student
{
	int roll_no;
	char name[15];
public:
	void getData()
	{
		cout << "Enter Name: ";
		cin >> name;
		cout << "Enter roll no: ";
		cin >> roll_no;
	}
	void dispaly()
	{
		cout << "Name: " << name<<endl;
		cout << "Roll no: " << roll_no<<endl;
	}
};

int main()
{
	int size, i;
	Student *ptr;
	cout << "How many records do you want to enter: ";
	cin >> size;
	ptr = new Student[size];

	cout << "Enter the records of " << size << " students -->" <<endl;
	for (i = 0; i < size; i++)
	{
		ptr[i].getData();
	}

	cout<<endl<<"Details of the students are..."<<endl;
	for (i = 0; i < size; i++)
	{
		ptr[i].dispaly();
	}

	return 0;
}