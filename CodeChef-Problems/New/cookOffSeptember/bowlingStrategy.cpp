//Bowling Strategy
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n,k,l;
ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n>>k>>l;    
        // Atmost - L - k players
        if(k==1&&n>1){
            cout<<-1<<endl;
        }
        else{
        int count=0;
            while(n>= k && l>0){
                count++;
                n-=k;
                l--;
        }
        if(l==0 && n>0){
            cout<<-1<<endl;
        }
        else{
            while(count)
            {
                for(int i=1;i<=k;i++) {cout<<i<<" ";
                    }
                count--;
            }
            for(int i=1;i<=n;i++){
                cout<<i<<" ";
            }
            cout<<endl;
        }    
        }
        
    }
    return 0;
}    