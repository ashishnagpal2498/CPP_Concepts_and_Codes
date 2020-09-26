// Even digits
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
    cin>>n;
    int cnt =0;
    ArrIn(n){
        cin>>arr[i];
        string s = to_string(arr[i]);
        if(s.length()%2==0) cnt++;
    }  
    cout<<cnt<<endl;
    return 0;
}    