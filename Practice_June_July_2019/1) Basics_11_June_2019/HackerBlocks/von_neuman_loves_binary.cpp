//Von neuman loves binary
#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    int num;
    while(T--)
    {
        cin>>num;
        int p=1;
        int ans=0;
        while(num)
        {
            ans = ans + p*(num%10);
            num = num/10;
            p = p<<1;
        }
        cout<<ans<<endl;
    }
    return 0;
}