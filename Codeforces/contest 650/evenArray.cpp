// parity swap - greedy
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
ll arr[200005];
ll solve(){
    ll ans = 0;
    for(int i=0;i<n;i++){
        if(i&1 && arr[i]&1) continue; //odd odd
        else if(!(i&1) && !(arr[i]&1)) continue; // even even 
        bool findNum = i&1;
         // true - odd number;
        int index = -1;
        if(findNum)
        {   for(int j=i+1;j<n;j++)
            {
                if(arr[j]&1 && j%2 == 0) {
                    index = j;
                    break;
                }
            }
        }
        else{
            for(int j=i+1;j<n;j++){
                if(arr[j]%2 == 0 && j&1){
                    index = j;
                    break;
                }
            }
        }
        if(index == -1) return -1;
        ans++;
        swap(arr[i],arr[index]);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++) cin>>arr[i];
        cout<<solve()<<endl;
    }    
    return 0;
}    