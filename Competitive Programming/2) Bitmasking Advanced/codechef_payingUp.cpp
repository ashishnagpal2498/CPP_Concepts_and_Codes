//Paying Up Codechef
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    ll t,n;
    cin>>t;
    while(t--)
    {
        ll sum=0,notes[25] ={0},amt;
        bool exist = false;
        cin>>n>>amt;
        for(ll i =0;i<n;i++) cin>>notes[i];
        for(ll mask=0;mask < (1<<n); mask++)
        {   sum=0;
            
            for(ll j=0;j<n;j++)
            {
                if((1<<j)&mask) sum+=notes[j];
            }
            if(sum == amt) {
                exist = true;
                break;
            }
        }
        if(exist) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}