//ValueLabs-
#include<iostream>
#define ArrIn for(int i=0;i<n;i++) cin>>arr[i];
using namespace std;
int dp[100005]={0};
bool divisible_one(int a,int b,int c,int sum)
{
    int ans=0;
    if(sum%a==0) ans++;
    if(sum%b==0) ans++;
    if(sum%c==0) ans++;
    return ans==1;
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int arr[100005];
    ArrIn;
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                int triplet = arr[i]+arr[j]+arr[k];
                if(dp[triplet]||divisible_one(arr[i],arr[j],arr[k],triplet))
                {
                    count++;
                }
            }
        }
    }
    cout<<6*count;
    return 0;
}