//codechef LunchTime - 
#include<iostream>
#define ArrIn for(int i=0;i<n;i++) cin>>arr[i];
using namespace std;
int sumOfDigits(int num)
{   int sum=0;
    while(num)
    {
        sum+=num%10;
        num = num/10;
    }
    return sum;
}
int FindMaxSum(int*arr,int n)
{   int smallAns ;
    int mSum = -10000000;
    for(int i=0;i<n;i++)
    {   
        for(int j=i+1;j<n;j++)
        {
            smallAns = arr[i]*arr[j];
            int ans1 = sumOfDigits(smallAns);
            mSum = mSum > ans1 ? mSum : ans1 ;
        }
    }
    return mSum;
}
int main(int argc, char const *argv[])
{   int T;
    cin>>T;
    while(T--)
    {int n;
    cin>>n;
    int arr[10005];
    ArrIn;
    cout<<FindMaxSum(arr,n)<<endl;
    }
    return 0;
}