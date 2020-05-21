//Find maximum number of books a person can read in T time - binary search
// Creating a sample space -
// subArray of maximum length -
#include<bits/stdc++.h>
#define ll long long int
#define sum(x) x+x
using namespace std;
ll t,n;
ll arr[200005];
bool checkSum(ll end,ll limit){
    ll sum = 0;
    for(int i=0;i<n;i++)
    {   
        if(i<end)
        {
            sum+=arr[i];
        }
        else{
            sum-=arr[i-end];
            sum+=arr[i];
        }
        if(i >= end-1)
        {
            //check sum
            if(sum<=limit) return true;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>t;
    for(int i=0;i<n;i++) cin>>arr[i];
    ll start = 0,end = n-1,mid;
    while(start<=end)
    {   mid = (start+end)/2;
        if(checkSum(mid,t)){
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    if(checkSum(start,t)) {cout<<start<<endl;}
    else { cout<<start-1<<endl;}
    return 0;
}    