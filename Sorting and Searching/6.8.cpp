#include <iostream>
#define MAX 100

using namespace std;

class Linprob
{
    int i, arr[MAX], loc;
public:
    Linprob()
    {
        for (i = 0; i < MAX; i++)
            arr[i] = -1;
    }
    void insert();
    int hash(int);
    void access();
};

void Linprob :: insert()
{
    int element, str;
    cout<<endl<<"Enter the element: ->";
    cin>>element;

    loc = hash(element);
    str=loc;
    do
    {
        if (arr[loc] == -1)
        {
            arr[loc] = element;
            break;
        }
        else
            loc = (loc+1) % MAX;

    } while(loc != str);
}

int Linprob :: hash(int element)
{
    return(element % MAX);
}

void Linprob :: access()
{
    int element;
    cout<<endl<<"Enter the element to be accessed: ";
    cin>>element;

    loc=hash(element);
    do
    {
        if(arr[loc] != element)
            loc = (loc+1) % MAX;
        else
        {
            cout<<element<<" found at location "<<loc<<endl; 
            break;
        }
    }   

    if (arr[loc] != element)
        cout<<"The element was not found";
}


int main(void)
{
    int ch, i;
    Linprob lp;

    while(1)
    {
        cout<<endl<<"1. Insert";
        cout<<endl<<"2. Access";
        cout<<endl<<"3. Quit";
        cout<<endl<<"Enter your choice: ->";
        cin>>ch;

        switch(ch)
        {
            case 1:
                lp.insert();
                break;
            case 2:
                lp.access();
                break;
            case 3:
                return 0;
        }

    }
}