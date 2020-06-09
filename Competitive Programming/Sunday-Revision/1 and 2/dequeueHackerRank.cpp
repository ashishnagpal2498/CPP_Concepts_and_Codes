//Deque - Doubly ended - find max element in range k - 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll t,n;
ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    deque < ll > d;
    ll k;
    cin>>t;
    while(t--)
    {cin>>n>>k;
    
        for(int i=0;i<n;i++)
        {
         cin>>arr[i];   
        }
        for(int i=0;i<n;i++)
        {
            if(!d.empty() && d.front()<= i-k) d.pop_front();
            while(!d.empty() && arr[d.back()] <= arr[i]) d.pop_back();
            d.push_back(i);
            if(i>=k-1)
            {
                cout<<arr[d.front()]<<" ";
            }
        }
    cout<<endl;
    }
    return 0;
}    