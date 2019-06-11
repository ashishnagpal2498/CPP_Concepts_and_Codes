//Square Root till p places -
#include<iostream>
using namespace std;
int main()
{
    int num, p;
    cin>>num>>p;
    float ans =1;
    float inc = 0.1;
    int times=1;
    while(ans*ans<=num)
    {
        ++ans;
    }
    ans--;
    ans = ans+inc;
    while(times<=p)
    {
        while(ans*ans<=num)
        {
            ans+=inc;
        }
        ans = ans-inc;
        inc = inc*0.1;
        times = times+1;
    }
    cout<<ans;
    return 0;
}