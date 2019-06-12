//Delhi Odd - Even
#include<iostream>
using namespace std;
int main()
{   

    int T;
    cin>>T;
    while(T--)
    {    
    int num;
    cin>>num;
    int oddsum=0 ,evensum=0;
    int digit;
    while(num)
    {
        digit = num%10;
        if(digit&1)
        {
            //Odd
            oddsum+=digit;
        }
        else
        {
            evensum+=digit;
        }
        num = num/10;
    }
    if(oddsum%3==0||evensum%4==0)
    {
        cout<<"Yes"<<endl;
    }
    else
    {
        cout<<"No"<<endl;
    }
    }
    return 0;
}