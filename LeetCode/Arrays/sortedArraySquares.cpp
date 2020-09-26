// Sorted array squares ->
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
    ArrIn(n) cin>>arr[i];
    // Since array is sorted we can use two pointer approach

    int* ans = new int[n];
    int j=0;
    while(j<n && arr[j]<0) j++;
    int i = j;
    j--;
    int index = 0;
    while(j>=0 && i<n && index<n){
        if(arr[j] * arr[j] < arr[i] * arr[i]){
            ans[index] = arr[j]*arr[j];
            j--;
        }
        else{
            ans[index] = arr[i]*arr[i];
            i++;
        }
        index++;
    }
    while(j>=0){
        ans[index++] = arr[j]*arr[j--]; 
    }
    while(i<n){
        ans[index++] = arr[i]*arr[i++];
    }

    // int * ans = new int[n];
    // for(int i=0;i<n;i++){
    //     ans[i] = arr[i]*arr[i];
    // }    
    // sort(ans,ans+n);
    ArrIn(n){
        cout<<ans[i]<<" ";
    }
    return 0;
}    