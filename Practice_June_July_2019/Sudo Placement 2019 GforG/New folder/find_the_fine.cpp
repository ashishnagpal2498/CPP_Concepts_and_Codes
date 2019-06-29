//Find the Fine
#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {   int n;
    cin>>n;
    int d;
    cin>>d;
    int car[100005];
    int penalty[100005];
    for(int i=0;i<n;i++)
        cin>>car[i];
    for(int i=0;i<n;i++) cin>>penalty[i];
    bool flag = d&1;
long long int ans =0;
    // cout<<flag;
    for(int i=0;i<n;i++)
    {
        if(flag&&!(car[i]&1))
        {
            ans += penalty[i];
        }
        else if(!flag&&(car[i]&1))
        {
            ans+= penalty[i];
        }
    }    
    cout<<ans<<endl;
    }
    return 0;
}