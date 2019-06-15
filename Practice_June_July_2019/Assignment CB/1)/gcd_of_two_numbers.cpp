//GCD of two Numbers 
#include<iostream>
using namespace std;
int main()
{
    int n1,n2;
    cin>>n1>>n2;
    int ans;
    while(true)
    {
        int rem = n1%n2;
        if(rem==0)
        {
            cout<<"GCD - "<<n2;
            break;
        }
        n1 = n2;
        n2 = rem;
    }
    return 0;
}