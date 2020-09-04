// Yet Another Array Restoration
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n,x,y;
// ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n>>x>>y;
        ll diff = y-x;
        for(int startVal = 1;startVal<=100;startVal++){
            bool seriesFound = false;
        for(int jump=1;jump<=100;jump++){
            int cnt = 0;
            bool arr[200] = {false};
            int lastIndex = -1;
            for(int j=startVal; cnt<n;j+=jump){
                if(j>199) break;
                // cout<<j<<" val->";
                arr[j] = true;
                lastIndex = j;
                cnt++;
            }
            // cout<<endl;
            
            if(arr[x] && arr[y] && cnt == n){
                if((n < (y-x)) && lastIndex>y) continue;
                seriesFound = true;
                cnt=0;
                for(int l=1;cnt<n && l<150;l++){
                    
                    if(arr[l]) {cnt++;cout<<l<<" ";}
                }
                break;
            }
        }
        if(seriesFound) break;    
        }
        cout<<endl;
        
    }
    return 0;
}    