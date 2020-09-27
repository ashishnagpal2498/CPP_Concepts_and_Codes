// Copy paste
#include<bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;
ll t, n,k;
ll arr[200005];
int main()
{           ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n>>k;
        ll minVal = INT_MAX;
        int minIndex = -1;
        for(int i=0;i<n;i++) {
            cin>>arr[i];
            minVal = min(minVal,arr[i]);
           minIndex = minVal == arr[i] ? i: minIndex; 
        }
        ll cnt = 0;
        for(int i=0;i<n;i++){
            if(i != minIndex){
                ll v = k - arr[i];
                int j=1;
                if(v){
                    cnt+= (v/minVal);
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}