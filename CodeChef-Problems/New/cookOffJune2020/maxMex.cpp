// Mex 
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
    cin>>t;
    while(t--)
    {   bool arr[100005] ={false};
        int a; 
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {   cin>>a;
            arr[a] = true;
        }
        if(arr[m]){
            cout<<-1<<endl;
        }
        else{
            ll start=0,end = 100000;
            for(ll i=m-1;i>=0;i--)
            {   // backward loop
                if(!arr[i]){
                    start = i+1;
                    break;
                }
            }
            for(ll i=m+1;i<100000;i++)
            {   // forward loop
                if(!arr[i]){
                    end = i-1;
                    break;
                }
            }
            cout<<(end-start)<<endl;
        }
    }
        
return 0;
}    