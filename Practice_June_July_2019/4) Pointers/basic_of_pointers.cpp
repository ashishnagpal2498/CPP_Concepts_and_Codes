//Pointers - and Pointers and Functions
#include<iostream>
using namespace std;
void array_fun(int a[])
{
    cout<<sizeof(a)<<endl;
    cout<<a<<endl;
}

void fun(int* y)
{
    // y = y+1;
    *y = *y+1;
    cout<<y<<endl;
}
int main()
{

    //Pointers are passed by value -

    int x =10;
    int *y = &x;
    // Dereferencing
    cout<<&x<<endl;
    fun(&x);
    cout<<&x<<endl;
    cout<<x<<endl;
    // cout<<y<<" "<<*y;
    //basic
    // cout<<&(*y)endl;
    // cout<<*(&y)<<endl;
    // // cout<<&(*x)<<endl; invalid statement
    // cout<<*(&x)<<endl;
    cout<<"ARRAYS\n";
    int arr[] = {1,2,3,4};
    cout<<sizeof(arr)<<endl;
    cout<<arr<<endl;
    cout<<*arr<<endl<<*arr+2<<endl<<2[arr]<<endl;
    array_fun(arr);
    return 0;
}