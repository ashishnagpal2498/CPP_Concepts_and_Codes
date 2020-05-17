//Atm Withdrawal
#include<iostream>
using namespace std;
int main()
{
    int amt;
    float balance;
    cin>>amt>>balance;
    float remaining = balance - amt - 0.50;
    if(remaining>=0&&amt%5==0)
        {cout<<remaining<<endl;}
    else
    {
        cout<<balance<<endl;
    }
    return 0;
}