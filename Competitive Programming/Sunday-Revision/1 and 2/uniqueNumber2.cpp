//Unique number II - there are two numbers which comes 1 time - all other occurs 2 times
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll t,n;
ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    ll zorVal = 0;
    for(int i=0;i<n;i++)
    {
        zorVal^=arr[i];
    }    
    //This comes the point where the zorVal is the zor of two numbers
    // Find 1st position of set bit in the zorVal
    ll j = 0;
    while(true)
    {
        if(zorVal& (1<<j)) break;
        j++;
    }
    // Find all the numbers with set bit here - and zor them
    ll zor2 = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]&(1<<j))
        {
            zor2^= arr[i];
        }
    }
    cout<<"First number is "<<zor2<<endl;
    cout<<"Second number is "<<(zorVal^zor2)<<endl;
    return 0;
}    