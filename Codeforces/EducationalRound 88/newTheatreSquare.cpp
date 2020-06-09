//New Theatre Square
#include<bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;
ll t,n,m,x,y;
char sq[105][1005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>x>>y;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++) cin>>sq[i][j];
        }
        ll minVal  = min(x*2,y);
        ll cost =0;
        for(int i=0;i<n;i++)
        {   
            for(int j=0;j<m;j++)
            {   
                if(sq[i][j] == '.')
                {
                    if(j+1<m&&sq[i][j+1] == '.'&& minVal == y)
                    {
                        cost+=y;
                        j++;
                    }
                    else{
                        cost+=x;
                    }
                }
            }
        }
        cout<<cost<<endl;
    }

    return 0;
}    