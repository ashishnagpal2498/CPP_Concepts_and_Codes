// Winning Strategy
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n;
        priority_queue<ll> pq;
        ll l;
        ArrIn(n){
            cin>>l;
            pq.push(l);
        }
        ll score1=0,score2=0;
        if(!pq.empty()){
            score1+=pq.top();
            pq.pop();
        }
        if(!pq.empty()){
            score2+=pq.top();
            pq.pop();
            if(!pq.empty())
            {
                score2+=pq.top();
                pq.pop();
            }
        }
        bool flag= false;
        while(!pq.empty())     
        {
            if(flag) score2+=pq.top();
            else score1+=pq.top();
            flag = !flag;
            pq.pop();
        }
        if(score1 == score2){
            cout<<"draw"<<endl;
        }
        else if(score1>score2){
            cout<<"first"<<endl;
        }
        else{
            cout<<"second"<<endl;
        }
    }
    return 0;
}    