//Reference variables and pointers
//dereferncing
#include<iostream>
using namespace std;
void myswap(int &a,int &b)
{
    int temp=a;

    a=b;
    b=temp;
    cout<<"Swap function  values "<<a<<"  "<<b<<endl;
}
int main()
{
    //In basic course we have learnt 
    //How to create a pointer 
    //how to store address of variable in a pointer
    //how can we use arithematic operations on pointer
    //return a pointer through functions 
    int *ptr =NULL;
    int a =500;
    ptr=&a;
    cout<<a<<"  "<<ptr<<"  "<<*ptr<<"  ";
    int b=200;
    cout<<b<<endl;
    myswap(a,b);
    cout<<"Values after function  "<<a<<"  "<<b<<endl;
    
    return 0;

}