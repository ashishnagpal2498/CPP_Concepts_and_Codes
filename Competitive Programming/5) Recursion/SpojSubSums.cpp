//SubSums
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n,A,B;
ll arr[200005];
void solution(){
    ll count =0;
    for(int mask=0;mask<(1<<n);mask++)
    {
        ll sum=0,j=0;
        while(j<n)
        {
            if((1<<j) & mask){
                sum+=arr[j];
            }
            j++;
        }
        if(sum>=A && sum<=B) count++;
    }
    cout<<count<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>A>>B;
    ArrIn(n) cin>>arr[i];
    solution();    
    return 0;
}    