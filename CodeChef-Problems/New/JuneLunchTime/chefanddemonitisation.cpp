// Chef and demonitisation
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n,s;
ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>s>>n;
        if(s==1){
            cout<<1<<endl;
        }
        else if(s<=n && !(s&1)){
            cout<<1<<endl;
        }
        else if(s<=n && s&1){
            cout<<2<<endl;
        }
        else{
            ll sum =0;
            ll cnt=0;
            ll p = n;
            while(n*p<s){
                p*=n;
                sum = p;
                cnt = p/n;
            }
            while(sum + n < s)
            {
                sum+=n;
                cnt++;
            }
            if(sum == s)
            {
                cout<<cnt<<endl;
            }
            else{
                // find nearest even number to that -
                int rem = (s-sum);
                if(rem == 1){
                    cout<<cnt+1<<endl;
                }
                else if(rem&1){
                    cout<<cnt+2<<endl;
                }
                else {
                    cout<<cnt+1<<endl;
                }
            }
        }
    }    
    return 0;
}    