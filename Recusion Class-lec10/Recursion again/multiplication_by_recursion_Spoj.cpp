//Multiplication recursion 
#include<iostream>
using namespace std;
void multi(int n)
{
    if(n==0)
    {
        return ;
    }
    int l1,l2;
    cin>>l1>>l2;
    cout<<l1*l2<<endl;
    return multi(--n);
}
int main()
{
    int n;
    cin>>n;
    multi(n);
    return 0;
}