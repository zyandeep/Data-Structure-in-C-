// C program for Fibonacci Search

#include <iostream>
#define MAX 100
using namespace std;

class Fibonacci
{
    int arr[MAX];
    int size;
public:
    void input_array(void);
    void search_element(void);
    int min(int, int);
    int fibMonaccianSearch(int);
};

void Fibonacci :: input_array(void)
{
    int i;
    cout<<"Enter the size of the array: ";
    cin>>size;

    cout<<"Enter "<<size<<" elements: "<<endl;
    for (i = 0; i < size; i++)
    {
        cin>>arr[i];
    }
}

void Fibonacci :: search_element(void)
{
    int num;
    cout<<"Enter the element to search for: ";
    cin>>num;

    cout<<"The Element is found at index: "<<fibMonaccianSearch(num);
    cout<<endl;
}


int Fibonacci :: min(int x, int y) 
{ 
    return (x<=y)? x : y; 
}
 

int Fibonacci :: fibMonaccianSearch(int x)
{
    /* Initialize fibonacci numbers */
    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM = fibMMm2 + fibMMm1;
 
    
    while (fibM < size)
    {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM  = fibMMm2 + fibMMm1;
    }
    
    
    int offset = -1;
 
    
    while (fibM > 1)
    {
        int i = min(offset+fibMMm2, size-1);
      
        if (arr[i] < x)
        {
            fibM  = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if (arr[i] > x)
        {
            fibM  = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else return i;
    }
 
   
    if(fibMMm1 && arr[offset+1]==x)
        return offset+1;
 
   
    return -1;
}
 

int main(void)
{
    Fibonacci f;
    f.input_array();
    f.search_element();
    
    return 0;
}
