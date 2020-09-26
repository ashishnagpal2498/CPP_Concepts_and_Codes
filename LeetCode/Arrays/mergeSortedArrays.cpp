// Merge Sorted Arrays
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n,m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    vector<int> arr1(n+m,0), arr2(m);
    ArrIn(n) cin>>arr1[i];
    ArrIn(m) cin>>arr2[i];
    int j=0,l=0;
    while(j<n && l<m){
        if(arr1[j]<arr2[l]) {j++;}
        else{
            int last = n;
            while(last>0 && last>=j){
                 arr1[last] = arr1[last-1];
                last--;
            }
            n++;
            arr1[j] = arr2[l];
            j++; l++;
        }
    }
    while(l<m){
        arr1[j++] = arr2[l++];
    }
    for(int i=0;i<n;i++){
        cout<<arr1[i]<<" ";
    }
    return 0;
}