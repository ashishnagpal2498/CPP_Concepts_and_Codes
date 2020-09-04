// A problem with Sticks
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
    cin>>t;
    while(t--)
    {cin>>n;
        priority_queue<ll> pq;
        // pq.push(0);
        unordered_map<int,bool> visited;
        ArrIn(n) {
            cin>>arr[i];
            if(!visited[arr[i]]&&arr[i]!=0){
                visited[arr[i]] = true;
                pq.push(arr[i]);
            }
        }
        ll cnt = 0;
        if(pq.empty() || pq.top() == 0){
            cout<<cnt<<endl;
        }
        else{
            while(!pq.empty()){
                ll tp = pq.top();
                pq.pop();
                cnt++;
            }
            cout<<cnt<<endl;
        }
    }
    return 0;
}    