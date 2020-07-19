// Three pairWise maximums 
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n,a,b,c;
ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        bool flag = true;
        ll minEle = min(a,min(b,c));
        if(a != b && a != c && b != c){
            flag = false;
            cout<<"NO"<<endl;
        }
        else if( a == b && b == c){
            cout<<"YES"<<endl<<a<<" "<<b<<" "<<c<<endl;
        }
        else{
            ll maxEle = max(a,max(b,c));
            if(minEle == a && minEle == b || minEle == b && minEle == c || minEle == a && minEle == c){
                cout<<"NO"<<endl;
            }
            else{
                cout<<"YES"<<endl<<maxEle<<" "<<minEle<<" "<<1<<endl;
            }
        }    
        
    }
    return 0;
}    