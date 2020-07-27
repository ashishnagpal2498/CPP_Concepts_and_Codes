// Deque STL
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n,k;
ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n;
        cin>>k;
        ArrIn(n){
            cin>>arr[i];
        }
        deque<int> dq;
        for(int i=0;i<n;i++){
            if(!dq.empty() && dq.front() <= i-k){
                dq.pop_front();
            }
            while(!dq.empty() && arr[dq.back()] <= arr[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1){
                cout<<arr[dq.front()]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}    