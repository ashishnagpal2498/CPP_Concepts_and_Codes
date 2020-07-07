//Chefina and Swaps
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
ll arr1[200005],arr2[200005];
int findIndex(int*A,int l,int h,int* B){
    int ans = -1,countA=0,countB=0;
    while(h>l){
        if(arr[h] == arr[h-1]){
           ans = h;
           
        }
        h--;
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n;
        ArrIn(n) cin>>arr1[i];
        ArrIn(n) cin>>arr2[i];
        sort(arr1,arr1+n);
        sort(arr2,arr2+n);
        int low1=0,hi1=n-1,low2=0,hi2 = n-1;    
        int cost=0;
        while(low1<hi1 && low2<hi2){
            if(arr1[low1] == arr2[low2]){
                low1++; low2++;
            }
            else {
                
            }
        }
    }
    return 0;
}    