#include<iostream>
#include<bits/stdc++.h>
#include<cstdlib>
#include<cstring>
using namespace std;
#define mod 1000000007
typedef long long int  ll;
ll modexp(ll base,ll power){
    ll k=base%mod,ans=1;
    while(power){
        if(power%2){
            ans=ans*k;
            ans=ans%mod;
        }
        k=k*k;
        k=k%mod;
        power=power/2;
    }
    return ans;
}
 
void fldsmdfr(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif 
}
 
bool check(int a, int b,int c){
    if(((a+b)>c) && ((a+c)>b) && ((b+c)>a))
    return false;
    return true;
}
int main() 
{ 
    // fldsmdfr();
    int t;
    cin>>t;
    while(t--){
    int n,i,j;
    char a[101];
    cin>>a;
    n=strlen(a);
    int co[n],c=0;
    
    for(i=0;i<n;i++){
        if(a[i]=='1'){
            co[c]=0;
            while(i<n&&a[i]=='1'){
                i++;co[c]++;
            }
            c++;
        }
    }
    
    sort(co,co+c,greater<int>());
    int alice=0;
    for(i=0;i<c;i+=2){
        alice+=co[i];
    }
    cout<<alice<<"\n";
    }   
    return 0; 
}