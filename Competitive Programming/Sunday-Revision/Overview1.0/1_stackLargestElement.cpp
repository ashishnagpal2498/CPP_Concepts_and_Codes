// Stack - Give me Pizza
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    ArrIn(n) cin>>arr[i];
    stack<int> s;
    vector<int> ans(n);
    for(int i = n-1;i>=0;i--){
    while(!s.empty() && arr[s.top()]<=arr[i]) s.pop();
    if(s.empty()){
       ans[i] = -1;
    }
    else ans[i] = arr[s.top()];
    s.push(i);
    }
    for(int i=0;i<n;i++) {
        cout<<ans[i]<<" ";
    }
    return 0;
}    