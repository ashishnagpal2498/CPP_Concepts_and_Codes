// Codechef Long
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
        ll sum = 0;
        bool flag = false;
        ll index = 0;
        cin>>n>>k;
        for(int i=0;i<n;i++) cin>>arr[i];
        ll i=0; // day -> 
        for(;i<n;i++){
            arr[i]+=sum;
            // cout<<arr[i]<<" -> "<<endl;
            if(k-arr[i]>0){
                flag = true;
                index = i+1;
                break;
            }
            else{
                arr[i]-=k;
                sum = arr[i];
            }
        }
        // Final -> Sum / k ;
        if(flag){
            cout<<index<<endl;
        }
        else{
            i+= (sum/k);
            // if(sum%k != 0) i++;
            cout<<i+1<<endl;
        }
    }
    return 0;
}