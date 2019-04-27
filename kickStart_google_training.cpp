//kickstart google
//Training -
#include<iostream>
#include<algorithm>
using namespace std;
int hoursTraining(int* arr,int n,int k)
{
    if(n==0||k==0)
    {
        return 0;
    }
    int ans=0;
    int smallans =0;
    int minans = INT8_MAX;
    for(int i=0;i<n;i++)
    {   smallans = INT8_MAX;
        for(int j=i;j<n;j++)
        {       ans = 0;
            for(int m=j;m<=k;m++)
            {
                ans+= (arr[m]-arr[j]);
            }
            smallans = min(smallans,ans);
        }
        minans = min(minans,smallans);
    }
    return minans;
}
int main()
{
    int n;
    cin>>n;
    int p;
    cin>>p;
    int *arr;
    arr = new int[n+p];
    arr = {0};
   
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
     sort(arr,arr+n);
    cout<<hoursTraining(arr,n,p);
    return 0;
}