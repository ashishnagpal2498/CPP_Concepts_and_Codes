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
    vector<ll> subSet1,subSet2;
    for(int mask=0;mask<(1<<(n/2));mask++)
    {
        ll sum=0,j=0;
        while(j<n)
        {
            if((1<<j) & mask){
                sum+=arr[j];
            }
            j++;
        }
        subSet1.push_back(sum);
        // if(sum>=A && sum<=B)
    }
    for(int mask=0;mask<(1<<((n+1)/2));mask++)
    {
        ll sum=0,j=0;
        while(j<n){
            if((1<<j) & mask){
                sum+=arr[j+((n)/2)];
            }
            j++;
        }
        subSet2.push_back(sum);
    }
    sort(subSet1.begin(),subSet1.end());
    sort(subSet2.begin(),subSet2.end());
    // cout<<"Subset 1 \n";
    // for(auto v:subSet1) {cout<<v<<" ";}
    // cout<<"\nSubset 2\n";
    // for(auto v:subSet2) {cout<<v<<" ";}
    //     cout<<endl;
    int j=subSet2.size()-1;
    int k = j-1;
    ll ans =0;
    // USING TWO POINTERS
    for(int i=0;i<subSet1.size();i++)
    {   ll val1 = subSet1[i];
        while(k>0 && val1+subSet2[k-1]>A) k--;
        while(j>=k && val1+subSet2[j]>B) j--;
        if(k>=0&& j!=k)
        ans+= (j-k)+1;
    }
    if(0>=A && 0<=B) ans++;
    cout<<ans<<endl;
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