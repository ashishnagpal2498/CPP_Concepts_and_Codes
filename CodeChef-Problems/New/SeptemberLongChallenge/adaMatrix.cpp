// Ada Matrix 
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=1;i<=n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
// ll arr[200005];
void transpose(ll arr[65][65],int k){
    for(int i =1 ;i<=k;i++){
        for(int j=1;j<=k;j++){
            if(j>i){
                swap(arr[i][j],arr[j][i]);
            }
        }
    }
}
void printMatrix(ll arr[65][65],int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
  cin>>t;
  while(t--)
  {  cin>>n;
      ll arr[65][65];
      ll ansArr[65][65];
      ll val = 1;
      for(int i=1;i<=n;i++){
          for(int j=1;j<=n;j++){
              cin>>arr[i][j];
              ansArr[i][j] = val;
              // cout<<val<<" ";
              val++;
          }
          // cout<<endl;
      }
      // cout<<"Print Matrix\n";
      // printMatrix(arr,n);
      // printMatrix(ansArr,n);
      ll cnt = 0;
     while(true){
          bool flag = true;
          for(int i=n;i>=1;i--){
                  if(arr[1][i] != ansArr[1][i]){
                      flag = false;
                      transpose(arr,i);
                      // printMatrix(arr,n);
                      cnt++;
                      break;
                  }
              }
          if(flag) break;
     }
     cout<<cnt<<endl;
    }
    return 0;
}    