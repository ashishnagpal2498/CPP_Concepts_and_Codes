//Armstrong number 
#include<iostream>
using namespace std;
int main()
{   int num;
    cin>>num;
    int digit;
    int sum=0;
    int n = num;
    while(num)
    {
        digit = num%10;
        sum = sum + (digit*digit*digit);
        num/=10;
    }
    if(n==sum)
    {
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;
}