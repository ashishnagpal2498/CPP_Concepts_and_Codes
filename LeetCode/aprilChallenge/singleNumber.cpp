// LeetCode April Challenge
#include<iostream>
#define ll long long int
using namespace std;
int main()
{
    ll n;
    ll arr[100005];
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    // Bitmasking
    ll zorVal = 0;
    for(int i=0;i<n;i++)
    {
        zorVal^=arr[i];
    }
    cout<<zorVal<<endl;
    return 0;
}