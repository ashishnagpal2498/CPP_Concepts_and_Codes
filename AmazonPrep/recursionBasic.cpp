// Recursion Check array is sorted, linear search and x^y
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
ll arr[200005];
bool isSorted(int n){
    if(n==0) return true;

    bool smallAns = isSorted(n-1);
    if(smallAns && arr[n] >= arr[n-1]) return true;
    return false;
}
int linearSearch(int n,int ele){
    if(n==-1) return -1;
    if(arr[n] == ele) return n;

    int chhotaAns = linearSearch(n-1,ele);
    if(chhotaAns == -1) return -1;
    return chhotaAns;
}
int xPowerY(int x,int y){
    if(y == 0) return 1;
    if(y==1) return x;
    int ans = xPowerY(x,y/2);
    int halfPower = ans *ans ;
    if(y&1) halfPower*=x;
    return halfPower;

}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    cin>>n;
    ArrIn(n) cin>>arr[i];
    bool ans = isSorted(n-1);
    ans ? cout<<"YES\n" : cout<<"NO\n";
    int ele;
    cout<<"Enter element to be searched -> ";
    cin>>ele;
    cout<<linearSearch(n,ele)<<endl;
    cout<<"Enter x and y "<<endl;
    int x,y;
    cin>>x>>y;
    cout<<xPowerY(x,y)<<endl;
    return 0;
}    