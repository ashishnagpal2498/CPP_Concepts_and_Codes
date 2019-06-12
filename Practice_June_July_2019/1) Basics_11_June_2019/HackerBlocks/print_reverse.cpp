//Print Reverse -
#include<iostream>
using namespace std;
int main()
{
    int num;
    int ans=0;
    cin>>num;
    while(num)
    {
        ans = ans*10 + (num%10);
        num = num/10;
    }
    cout<<ans;
    return 0;
}