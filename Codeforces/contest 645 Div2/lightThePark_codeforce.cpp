// Codeforces - Light the park
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll t,n,m;
ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        ll i=1;
        ll lampCount=0;
        if(n==1)
        {   if(m&1)
            lampCount+=(m/2) +1 ; // m floor 2
            else lampCount+= (m/2);
        }
        else{
            for(i;i<n;i+=2)
            {
                for(ll j=1;j<=m;j++) lampCount++; 
            }
        }
        if(n!=1&&(n&1)&&(m&1)) lampCount+=(m/2)+1;
        else if(n!=1 &&(n&1)) lampCount+= (m/2);
        cout<<lampCount<<endl;
    }
    return 0;
}    