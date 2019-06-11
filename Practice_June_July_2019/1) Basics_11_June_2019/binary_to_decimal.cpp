//Binary to Decimal conversion
#include<iostream>
using namespace std;
int main()
{
    int num;
    int p=1;
    int ans = 0;
    cin>>num;
    while(num)
    {
        ans = ans+ p* (num%10);
        p = p<<1;
        num = num/10;
    }
    cout<<ans;
    return 0;
}