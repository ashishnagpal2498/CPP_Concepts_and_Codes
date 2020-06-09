// Even Matrix
#include<bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;
ll t,n;
ll arr[1005][1005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll nSq = n*n;
        ll val = 1;
        for(int i=1; i<=n;i++)
        {   
            for(int j=1;j<=n;j++,val++)
            {   
                arr[i][j] = val;
            }
        }
        if(!(n&1)){
            for(int i=1;i<=n;i++)
            {   if(!(i&1)){
                        //even -
                     for(int j=1;j<=n;j+=2)
                {   if(j+1<=n)
                    swap(arr[i][j],arr[i][j+1]);
                }         
                    }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}    