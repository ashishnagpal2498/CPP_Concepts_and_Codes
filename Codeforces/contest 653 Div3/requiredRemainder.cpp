// Required Remainder
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
// #define modExp(a,x,m) ll modExp(a,x,m){
//     ll ans=1,a;
//     while(j)
//     {   if(j&1)
//         {
//             ans = (ans * a) % m;
//         }
//         a = (a*a)% m;   
//         j>>=1;
//     }
//     return ans;
// }
using namespace std;
ll t,n,x,y;
// ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>x>>y>>n;
        ll rem = n%x,num;
        if(rem == y){
            cout<<n<<endl;
        }    
        else if(rem>y){
            num = n - (rem-y);
            cout<<num<<endl;
        }
        else{
            num = (n - (rem + (x-y)));
            cout<<num<<endl;
        }

    }
    return 0;
}    