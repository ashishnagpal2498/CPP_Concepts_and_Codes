//Staircase Problem Recursion
#include<iostream>
using namespace std;
int stairCase_k3(int n)
{
    if(n==0) return 1;
    if(n<0) return 0;
    int ans=0;
     
   ans = stairCase_k3(n-1)+ stairCase_k3(n-2) + stairCase_k3(n-3);
   return ans;
}
int staircase(int n,int k)
{
    if(n==0)
    {
        return 1;
    }
    if(n<0){
        return 0;
    }
    int ans =0;
    for(int i=1;i<=k;i++)
    {
        ans += staircase(n-i,k);
    }
    return ans;
}
int main()
{
    int n,k;
    cin>>n>>k;
    cout<<staircase(n,k)<<endl;
    cout<<stairCase_k3(n);
    return 0;
}