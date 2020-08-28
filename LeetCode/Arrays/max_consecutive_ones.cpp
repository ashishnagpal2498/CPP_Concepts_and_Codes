// LeetCode Arrays
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
    ArrIn(n) cin>>n;
    int max1 = 0;
    int maxSoFar=0;
    ArrIn(n){
        if(arr[i]== 1) maxSoFar++;
        else{
            max1 = max(max1,maxSoFar);
            maxSoFar = 0;
        } 
    }    
    if(maxSoFar != 0) max1 = max(max1,maxSoFar);
    cout<<max1<<endl;
    return 0;
}    