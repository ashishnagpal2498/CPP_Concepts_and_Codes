//CodeChef Paying Up 
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll t,n,amt;
ll arr[200005];
bool findSubset(){
    for(int mask=0;mask<(1<<n);mask++)
    {
        ll sum=0;
        for(int j=0;j<n;j++)
        {
            if(mask& (1<<j)){
                sum+=arr[j];
            }
        }
        if(sum == amt)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>n>>amt;
        for(int i=0;i<n;i++) cin>>arr[i];
        bool ans = findSubset();
        if(ans) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;    
    }
    return 0;
}    