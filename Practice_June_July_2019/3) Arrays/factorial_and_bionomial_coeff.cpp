//Factorial and Bionomial Cofficient
#include<iostream>
using namespace std;
int fact(int n)
{
    int ans =1;
    for(int i=2;i<=n;i++)
        ans*=i;
    return ans;
} 
int B_coeff(int n,int r)
{
    return fact(n)/(fact(r)*fact(n-r));
}
int main()
{
    int n,r;
    cin>>n>>r;
    cout<<fact(n);
    cout<<endl<<"Bionomial Cofficient  "<<B_coeff(n,r);
    return 0;
}