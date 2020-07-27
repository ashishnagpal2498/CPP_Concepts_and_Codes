// Birthday Paradox
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    double p;
    cin>>p;
    double ans = 1.0;
    double days = 365.0;
    while(ans >= (1-p)){
        ans*=(double)(days/(double)365.0);
        days--;
    }
    cout<<(365-days)<<endl;
    return 0;
}    