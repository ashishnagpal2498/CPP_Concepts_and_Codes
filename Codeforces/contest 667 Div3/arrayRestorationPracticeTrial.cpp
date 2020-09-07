// Yet Another Array Restoration
// 1 3 5 7 Mine ans ->
// -> Ans-> Actual -> 2 3 4 5
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
        for(int startVal = y;startVal>=1;startVal++){
            bool seriesFound = false;
        for(int jump=1;jump<=50;jump++){
            int cnt = 0;
            bool arr[52] = {false};
            for(int j=startVal;j>=0 && cnt<n;j-=jump){
                arr[j] = true;
                cnt++;
            }
            // cout<<endl;
            if(arr[x] && arr[y]){
                seriesFound = true;
                cnt=0;
                for(int l=1;cnt<n && l<51;l++){
                    
                    if(arr[l]) {cnt++;cout<<l<<" ";}
                }
                ll m = jump;
                while(cnt < n){
                    cnt++;
                    cout<<y+m<<" ";
                    m+=jump;
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