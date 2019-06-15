//Fibonacci Pattern 
#include<iostream>
using namespace std;
int main()
{
    int n,a=0,b=1;
    int temp;
    cin>>n;
    for(int curline=1;curline<=n;curline++)
    {
        for(int nvalue=1;nvalue<=curline;nvalue++)
        {
            cout<<a<<"\t";
            temp = a;
             a = b;
            b = b + temp;

        }
        cout<<endl;
    }
    // for(int i=0;i<10;i++)
    // {
    //     cout<<a<<"  ";
    //     temp = a;
    //     a = b;
    //     b = b + temp;
    // }
    return 0;
}