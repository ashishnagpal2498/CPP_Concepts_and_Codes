//Fix You
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n,m;
char arr[105][105];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
      cin>>n>>m;
      ArrIn(n){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
      }
      ll ans=0;
      //last column and last row
      for(int i=0;i<n;i++){
        if(arr[i][m-1] == 'R') ans++;
      }
      for(int j=0;j<m;j++){
        if(arr[n-1][j] == 'D') ans++;
      }   
      cout<<ans<<endl;
    }
    return 0;
}    