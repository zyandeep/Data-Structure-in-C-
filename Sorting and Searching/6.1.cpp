//6.1 Bubble sort

#include <iostream>

using namespace std;

class bubblesort
{
    int a[100],n,i,j,temp;
public:
    void in();
    void out();
};

int main()
{
    bubblesort bs;
    bs.in();
    bs.out();

    return 0;
}

void bubblesort::in()
{
    cout<<"How many elements ";
    cin>>n;
    cout<<"Enter the element of array"<<endl;
    for(i=0; i < n; i++)
    {
        cin>>a[i];
    }
}

void bubblesort::out()
{
    int pass;

    for (pass=n-1; pass >= 1; pass--)
    {
        for (i = 0; i < pass; i++)
        {
            if(a[i] > a[i+1])
            {
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
    }
    cout<<endl<<"Elements of array after the sorting are:";
    for(i=0;i<=n-1;i++)
    {
        cout<<endl<<a[i];
    }

}
