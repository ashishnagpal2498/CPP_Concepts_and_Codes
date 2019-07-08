//STring to number 
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int number(string str,int i)
{
    if(str[i]=='\0')
    {
        return 0;
    }
    
    
    int digit = int(str[i] - '0');
    int ans = digit*pow(10,str.length()-i-1) + number(str,i+1);
    return ans;
}
int main()
{
    string str;
    cin>>str;
    // cout<<str.length()<<endl;
    cout<<number(str,0);
    return 0;    
}