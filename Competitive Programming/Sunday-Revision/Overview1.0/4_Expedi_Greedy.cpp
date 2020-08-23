// EXPEDI - fuelTank Cows
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n,L,P;
ll arr[200005];
class myComp{
public:
    bool operator()(pair<ll,ll> A,pair<ll,ll> B)
    {
        return A.first >B.first;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n;
        priority_queue<pair<ll,ll>> pq;
        ll a,b;
        ArrIn(n){
            cin>>a>>b;
            pq.push(make_pair(a,b)); // a distance , b fuel tank ->
        }
        cin>>L>>P;
        ll maxP = INT_MIN;
        ll ans =0,fuel=P;
        bool flag = true;
        int i=0;
        int m=0;
        while(i<L){
            if(!pq.empty())
            {   
                auto f = pq.top();
                // cout<<L-f.first<<" fuel -> "<<fuel<<endl;
                if(L - f.first <= i){
                    // cout<<" HERE "<<f.first<<" -> "<<f.second<<endl;
                    maxP = max(maxP,f.second);
                    pq.pop();
                }
            }
            i++; // Add distance ->
            if(fuel==0){
                // add fuel to tank ->
                if(maxP== INT_MIN){
                    // cout<<"No tank reached -> "<<i<<endl;
                    flag = false;
                    break;
                }
                // Else ------>>
                // cout<<"Fuel refilled \n";
                fuel+= maxP;
                maxP = INT_MIN;
                ans++;
            }
            fuel--; // Reduce fuel for distance
        }
        if(flag&& i==L){
            cout<<ans<<endl;
        }    
        else {
            cout<<-1<<endl;
        }
    }
    return 0;
}    