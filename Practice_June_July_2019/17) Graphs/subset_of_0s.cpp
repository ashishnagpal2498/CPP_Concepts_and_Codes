//SUBSETS of '0' s
#include <iostream>
using namespace std;
int countWays(int n,int k)
{
    if(n==0)
    {
        return 1;
    }
    int ans = countWays(n-1,k);
    //every element is in 
    for(int i=0;i<n;i++) 
    {
        
    }
    return ans+ans2;
}
int main(int argc, char const *argv[])
{
    cout<<countWays(7,2);
    return 0;
}