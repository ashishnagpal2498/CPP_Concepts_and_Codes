#include<iostream>
#include<string>
using namespace std;
long long int dp[10005]={0};
int digit_Sum(int n)
{
    if(dp[n]!=0||n==0)
    {
        return dp[n];
    }
    int sum = 0;
    int num = n;
    while(n)
    {
        sum = sum + n%10;
        n = n/10;
    }
    dp[num] = sum;
    return sum;
}
long long int primedp[10005]={0};
int prime(int n)
{   primedp[2] = 1;
    if(primedp[n]!=0)
    {
        return primedp[n];
    }
    bool flag = false;
    //cout<<"N here "<<n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            flag = true;
            break;
        }
    }
    if(flag)
    {
        primedp[n]= 2;
    }
    else
    {   //prime -
        primedp[n] =1;
    }
    return primedp[n];
}
long long int* createArr(int n)
{
   long long int*arr = new long long int[n];
    for(int i=0;i<=n;i++)
    {
        arr[i] = digit_Sum(i);
    }
    // for(int i=0;i<=n;i++)
    // {
    //     cout<<arr[i]<<"  ";
    // }
    // cout<<endl;
    return arr;
}
int main()
{
    string str;
    cin>>str;
    //string -
    // int n = str.length();
    //convert string to number -
    long long int n=0;
    long long int len = str.length();
    //cout<<len<<endl;
    for(int i=0;i<len;i++)
    {
        int digit = int(str[i]-'0');
        n = n*10 +digit;
    }
    //cout<<n;
    long long int * arr = createArr(n);
    //count the number of prime nos - till n as 0 ke 
    int count=0;
    for(int i=2;i<=n;i++)
    {   
        if(prime(i)==1)
        {
            count++;
        }
    }
    
    //cout<<"Count After  - "<<count;

    for(int i=1;i<=n;i++)
    {
        //finding pair-
        int element1 = arr[i];
        for(int j=i+1;j<=n;j++)
        {   
            int ele2 = arr[j];
            int s = element1+ele2;
            int primetrue = prime(s);
      //      cout<<"Prime true val  "<<primetrue<<endl;
            if(primetrue==1)
            {   //cout<<"Pairs  "<<element1<<"  "<<ele2<<endl;
                count++;
            }
        }
        count = count%(7+(1000000000));
    }

cout<<count;
return 0;
}