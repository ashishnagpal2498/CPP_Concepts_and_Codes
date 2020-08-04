// convex polygon
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
// Wrong -> %4 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
      cin>>n;
      ll count =0;
      if(n&1){
        cout<<"NO"<<endl;
        continue;
      }
      while(n%2 ==0)
      {
            count++;
            n/=2;
      }
      if(!(count&1)){
        cout<<"YES"<<endl;
      }
      else{
        cout<<"NO"<<endl;
      }
    }    
    return 0;
}    