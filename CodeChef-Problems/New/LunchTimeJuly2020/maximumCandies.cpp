// Maximum Candies
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n,m,x,y;
ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        cin>>n>>m>>x>>y;
        ll ans = 0;
        ll num = n*m;
        ll halfNum = num/2;
        if(x>=y){
            // place y/2 value
            if(y&1){
                // Odd ->
                ll val = (y/2);
                ll otherVal = (y/2) + 1;
                bool flag= false;
                for(int i=0;i<n;i++)
                    {   bool internalFlag = flag;
                        for(int j=0;j<m;j++){
                            if(!internalFlag){
                            ans+=(otherVal);
                            }
                            else{
                            ans+=(val);
                            }
                            internalFlag = !internalFlag;
                        }
                        flag = !flag; 
                    }           
            }
            else{
                // Y is even ->
                // m is odd -> 
                // Share a side -> upper and right ->
                ans += num*(y/2);
            }
        }
        else{
        ll z = (y-x);
        if(z>=x){
            // place all X 
            ans+= num*x;
        }
        else{
            // z -> 
            ll val = z;
            ll otherVal = x;
            bool flag= false;
            for(int i=0;i<n;i++)
                    {   bool internalFlag = flag;
                        for(int j=0;j<m;j++){
                            if(!internalFlag){
                            ans+=(otherVal);
                            }
                            else{
                            ans+=(val);
                            }
                            internalFlag = !internalFlag;
                        }
                    flag = !flag; 
                    }    
        }
        }
        cout<<ans<<endl;
    }
    return 0;
}    