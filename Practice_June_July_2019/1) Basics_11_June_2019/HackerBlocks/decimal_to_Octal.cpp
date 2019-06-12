//Decimal to Octal 
#include<iostream>
using namespace std;
int main()
{   int num;
    int ans=0;
    cin>>num;
    int inc = 1;
    while(num)
    {
        ans = ans + ((num%8)*inc);
        num = num/8;
        inc = inc*10;
    }
    cout<<ans;
    return 0;
}