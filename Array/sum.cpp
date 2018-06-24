#include <iostream>

using namespace std;

class Sum
{
    int n;
public:
    void input();
    void output();
    int add(int n);
};

void Sum::input()
{
    cout<<"Enter the integer: ";
    cin>>n;
}

void Sum::output()
{
    cout<<"Sum = " << add(n) <<endl;
}

int Sum::add(int n)
{
    if(n >= 1)
        return n + add(n-1);
    
    return 0;
}

int main()
{
    Sum s;
    s.input();
    s.output();

    return 0;
}