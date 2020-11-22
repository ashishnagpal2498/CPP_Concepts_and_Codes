// Novemeber CookOff
#include<bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;
ll t,n,k,m;
ll arr[200005];
int main(){
           ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m>>k;
    ll qi,a,count=0;
    for(int i=0;i<n;i++){
        ll sum =0;
        for(int j=0;j<k+1;j++){
            if(j==k){
                cin>>qi;
            }
            else
            {   cin>>arr[j];
                sum+= arr[j];    
            }

            
        }
        if(sum>=m && qi<=10){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}