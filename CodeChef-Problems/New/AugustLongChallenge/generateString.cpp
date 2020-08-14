// Generate string till 1000
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
    n= 1001;
    string s = "";
    for(int i=0;i<n;i++){
        s+=('a'+ (i%26));    
    }
    cout<<s<<endl;
    return 0;
}    