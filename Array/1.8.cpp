#include <iostream>
using namespace std;

struct student
{
    int rollno;
    char sex;
    float height, weight;
};

student data[3] = {
    {12, 'm', 5.7, 59.8},
    {7, 'f', 6.0, 65.2},
    {3, 'm', 6.2, 75.5}
};


class Std_class 
{
public:
    void display();    
};

void Std_class :: display()
{
    cout<<"The initialized structures are -->";
    
    for(int i=0; i<=2; i++)
    {
        cout<<endl<<"**RECORD NO. **"<<endl<<i+1;
        cout<<endl<<data[i].rollno;
        cout<<endl<<data[i].sex;
        cout<<endl<<data[i].height;
        cout<<endl<<data[i].weight;
    }
}


int main()
{
    Std_class st;
    st.display();

    return 0;  
}