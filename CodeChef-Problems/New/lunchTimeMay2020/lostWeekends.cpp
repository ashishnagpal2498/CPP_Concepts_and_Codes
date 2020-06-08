// Lost weekends -
#include<bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;
ll t,n;
ll arr[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    const ll numberOfHours = 120;
    while(t--)
    {   ll hours =0;
        for(int i=0;i<5;i++) cin>>arr[i];
        cin>>n;
        for(int i=0;i<5;i++)
        {
            hours+=(arr[i]*n); 
        }

        if((hours - numberOfHours) <= 0) {
            cout<<"No"<<endl;
        }
        else {
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}    