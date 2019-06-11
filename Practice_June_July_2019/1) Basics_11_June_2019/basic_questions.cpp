//Basics Of C++
//Largest of Three Numbers
//Decimal to binary conversion
#include<iostream>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;

    (a>b) ? (a>c) ? cout<<"A is largest" : cout<<"C is largest" : (b>c) ? cout<<"B is largest" : cout<<"C is largest";
    cout<<endl<<"Enter a number";
    int num;
    cin>>num;
    int ans[100]={};
    int i=0;
    int rem;
    while(num)
    {
        rem = num%2;
        ans[i] = rem;
        i++;
        num = num>>1;
    }
    for(int l=i-1;l>=0;l--)
        {cout<<ans[l];}
    // while(ans)
    // {
    //     num = num*10 + ans%10;
    //     ans = ans/10;
    // }
    cout<<num;    
    return 0;
}