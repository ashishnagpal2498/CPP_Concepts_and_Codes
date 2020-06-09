//Codechef unitGCD
// Point to remember - the the event numbers cannot be co-primes
// n and n+1 are always coprimes
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll t,n;
ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>n;
        //Number of values -
        if(n==1)
        {
            cout<<"1\n1 1\n";
        }
        else{
            cout<<n/2<<"\n";
            for(int i=0;i< n/2 ; i++)
            {
            if(i==0)
            {
                if(n==2)
                {
                    cout<<2<<" "<<1<<" "<<2;
                }
                else{
                    cout<<3<<" "<<1<<" "<<2<<" "<<3<<"\n";
                }
            }
            else{
                int val = 2* (i+1);
                if(val+1 <=n)
                {
                    cout<<2<<" "<<val<<" "<<val+1<<"\n";
                }
                else{
                    cout<<1<<" "<<val;
                }
            }
        }
         cout<<"\n";
        }
        
       
    }
    return 0;
}    