// chef and card game
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
ll digitSum(ll v){
    ll sum = 0,digit;
    while(v){
        digit = v%10;
        v/=10;
        sum+=digit;
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;

    while(t--)
    {   ll a,b,sumA=0,sumB=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a>>b;
            a = digitSum(a);
            b = digitSum(b); 
            if(a == b){  sumA++; sumB++;}
            else if(a<b) sumB++;
            else sumA++;
        }
        if(sumA>sumB){
            cout<<0<<" "<<sumA<<endl;
        }
        else if(sumB>sumA){
            cout<<1<<" "<<sumB<<endl;
        }
        else{
            cout<<2<<" "<<sumA<<endl;
        }
    }
    return 0;
}    