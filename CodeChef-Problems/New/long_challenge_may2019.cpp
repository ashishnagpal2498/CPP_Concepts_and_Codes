//Long Challenge - CodeChef 
#include<iostream>
using namespace std;
int main()
{
    int T,n;
    cin>>T;
    while(T--)
    {   int ans= 0;
        cin>>n;
        bool flag=true;
        if(n==1)
        {
            flag = false;
            cout<<"1\n";
        }
        else
        {
            ans += (n+n-1) + (n*(n-1));
            n=n-2;
        }
        while(flag&&n)
        {
            if(n==1||n<=0) break;
              ans = (ans+n) + ans*n;
            n = n-1;
        }
        if(n==1) ans = (ans+1) + (ans*1);
    if (flag) cout<<ans<<endl;
    }
    return 0;
}