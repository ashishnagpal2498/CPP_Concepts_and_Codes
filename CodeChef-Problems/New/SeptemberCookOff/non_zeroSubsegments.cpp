// Anmol and Good Subarrays
// Total subarrays whos sum is not zero - 0
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
    map<int,int> prefix;
    int sum = 0;
    prefix[0] = 1;
    ArrIn(n) {
        cin>>arr[i];
        sum+=arr[i];
        prefix[sum]++;
    }
    int badSubArrays = 0;
    for(auto i:prefix){
        int v = i.second;
        badSubArrays+=((v*(v-1))/2);
    }
    // int subarrays = (n*(n+1))/2;
    cout<<badSubArrays<<endl;
    return 0;
}    