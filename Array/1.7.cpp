#include <iostream>
using namespace std;

class TwoDArray
{
    int arr[4][3];
    int *ptr1, (*ptr2)[3];

public:
    TwoDArray()
    {
        ptr1 = &arr[0][0];
        ptr2 = arr;
        // same as ptr2 = &arr[0]
    }
    void input();
    void output();
};

void TwoDArray::input()
{
    int i, j;

    cout<<"Enter a 4*3 2D array -->"<<endl;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 3; j++)
            cin>>arr[i][j];
}

void TwoDArray::output()
{
    int i, j;

    cout<<"Displaying the 2D array using pointer -->"<<endl;
    /*for (i=0; i < 4; i++)
    {
        for (j= 0; j < 3; j++)
        {
            cout << *ptr1++ << '\t';
        }
        cout<<endl;
    }*/


    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cout << *(*(ptr2 + i) + j) << "\t";
        }
        cout<<endl;    
    }
}


int main()
{
    TwoDArray td;
    td.input();
    td.output();

    return 0;
}