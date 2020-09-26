// Game on strip
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
    while(t--){
        cin>>n;
        ArrIn(n) cin>>arr[i];
        int cnt=0;
        priority_queue<int> pq;
        ArrIn(n){
            if(arr[i] == 0) cnt++;
            else{
                if(cnt != 0) pq.push(cnt);
                cnt =0;
            }
        }
        if(cnt != 0) pq.push(cnt);
         // cout<<pq.size()<<endl;
        if(!pq.empty() && pq.size() == 1 && pq.top() == 1 ) {cout<<"Yes"<<endl;}
        else if(!pq.empty() && pq.top() == 1 && pq.size() >= 2){
            // checked
            cout<<"No"<<endl;
        } 
        else if(!pq.empty() && pq.top()&1){
            int v = pq.top()/2;
            pq.pop();
            if(!pq.empty() && pq.top()>v) {
                cout<<"No"<<endl;
            }
            else
            {cout<<"Yes"<<endl;}
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}    