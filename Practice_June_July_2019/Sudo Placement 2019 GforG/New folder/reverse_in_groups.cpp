//Reverse K sub-aarays - Reverse in groups
#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {   int n;
        cin>>n;
        int k;
        cin>>k;
        long long int arr[10005];
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n;i=i+k)
        {   int m=i,j=k+i-1;
            if(j>=n) j= n-1;
            while(m<j)
            {
                swap(arr[m++],arr[j--]);
            }
            // 
            // cout<<"After ith iteration "<<i<<endl;
            // for(int q=0;q<2;q++){
            //     cout<<arr[q]<<" ";
            // }
            // cout<<endl;
        }
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
    cout<<endl;
    }
    return 0;
}