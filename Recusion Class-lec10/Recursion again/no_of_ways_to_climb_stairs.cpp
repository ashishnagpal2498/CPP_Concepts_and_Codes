//No. of ways to climb a platform .
#include<iostream>
using namespace std;

int ways(int n,int k)
{
    if(n==0)
    {
        return 1;
    }
    if(n<0) return 0;

    int ans=0;
    for(int i=1;i<=k;i++)
    {
        ans+=ways(n-i,k);
    }
    return ans;
}
int main()
{
    cout<<ways(3,3);
    return 0;
}