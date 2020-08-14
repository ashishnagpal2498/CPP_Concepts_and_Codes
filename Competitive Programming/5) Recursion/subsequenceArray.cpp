// Subsequences of an Array
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
ll arr[200005];
vector<ll> result;
void subsequence(ll n)
{   
    if(n==-1){

        for(int i=0;i<result.size();i++) {cout<<result[i]<<" ";}
        cout<<endl;
    return;
    }

    // Push the element ->
    result.push_back(arr[n]);
    subsequence(n-1);
    result.pop_back();
    subsequence(n-1);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    ArrIn(n) cin>>arr[i];
    subsequence(n-1);   
    return 0;
}    