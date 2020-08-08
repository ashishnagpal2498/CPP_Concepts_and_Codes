// Min Factor
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(a,n) for(int i=a;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n,m;
ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n>>m;
        ll minLengthN=INT_MAX,minLengthM=INT_MAX;
        if(n==1 && m == 1){
            cout<<1<<" "<<1<<endl;
        }
        else if(n==1){
            cout<<0<<" "<<1<<endl;
        }
        else if(m==1){
            cout<<1<<" "<<1<<endl;
        }
        else{
            ll q = min(n,m);
        ArrIn(2,10){
            if(n>=i && n%i == 0){
                ll num = n/i;
                string nStr = to_string(num);
                // cout<<nStr<<" -> "<<i<<endl;
                if(n == i) minLengthN = 1;
                else {ll v = nStr.length()*i;
                                minLengthN = min(minLengthN,v);}
            }
            if(m>=i && m%i == 0){
                ll num = m/i;
                string mStr = to_string(num);
                // cout<<mStr<<" -> "<<i<<endl;
                if(m==i) minLengthM = 1;
                else {ll v = mStr.length()*i;
                                minLengthM = min(minLengthM,v);}
            }
        }
        if(minLengthN>=minLengthM){
            cout<<1<<" "<<minLengthM<<endl;
        }
        else{
            cout<<0<<" "<<minLengthN<<endl;
        }
    }
    }    
    return 0;
}    