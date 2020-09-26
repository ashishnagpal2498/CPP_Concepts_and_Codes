// Decrease Sum of Digits 
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n,s;
ll arr[200005];
ll sumOfDigits(ll num){
    ll sum=0;
    // cout<<num<<endl;
    while(num){
        ll digit = num%10;
        sum+=digit;
        num/=10;
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n>>s;    
        ll sum = sumOfDigits(n);
        if(sum<=s){
            // cout<<"Here"<<endl; 
            cout<<0<<endl;
        }
        else{
            int iterations =0;
            ll pow= 1;
            ll ans=0;
            while(iterations<18){
                ll dig = (n/pow) % 10;
                // Number to make that value 0 ->
                ll val = ((10 - dig))*pow;
                ans+=val;
                n+=val;
                sum = sumOfDigits(n);
                if(sum<=s){
                    cout<<ans<<endl;
                    break;
                }
                pow*=10;
                iterations++;
            }
        }
    }
    return 0;
}    