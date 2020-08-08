// another card game
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
#define modExp(a,x,m) ll modExp(a,x,m){
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
        minLengthN = n/9;
        if(n%9 != 0) minLengthN++;
        minLengthM = m/9;
        if(m%9 != 0) minLengthM++;
        if(minLengthN>=minLengthM){
            cout<<1<<" "<<minLengthM<<endl;
        }
        else{
            cout<<0<<" "<<minLengthN<<endl;
        }
    }  
    return 0;
}    