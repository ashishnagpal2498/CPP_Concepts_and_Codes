//Pointers
#include<iostream>
using namespace std;
void func(int *ptr)
{
    *ptr=*ptr+1;
    cout<<endl<<endl<<*ptr<<endl;
}
void arrayfunc(int a[])
{ //array - name is alias
    cout<<sizeof(a)<<endl<<a<<endl;
    cout<<*(a+3);
    a[2]=67;
}
int main()
{ //bitmasking ???             

// {   int a=100;
//     int b=2;
//     cout<<a<<endl;
//     cout<<&a<<endl;
//     char c='A';
    
    /* int *ptr; //pointer defination
    ptr=&a; //pointer initialization

    cout<<ptr<<endl<<*ptr<<endl<<&ptr;//dereference operator used here 
    cout<<endl<<b<<endl<<&b<<endl;
    cout<<*(&a)<<endl<<sizeof(ptr)<<ptr+1; 
   */
    // char *charptr;
    // charptr=&c;

    // cout<<c<<endl<<sizeof(charptr)<<charptr+1<<"\n";
 int x=100;
 int arr[]={1,2,3,5};
 cout<<sizeof(arr)<<endl<<arr;
 //cout<<&x<<endl;
  func(&x);
  cout<<x<<endl;
 //cout<<x;
  cout<<arr[2];

    return 0;
}