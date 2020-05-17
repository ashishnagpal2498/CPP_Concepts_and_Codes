//The Great Run
#include<iostream>
using namespace std;

//Maximum no of girls need to be impress
int greatRun(int *a,int n,int k)
{   int max_sum = -1;
    for(int i=0;i<n;i++)
    {
        int sum=0;
        int m=i;
        for(int j=0;j<k;j++)
        {   if(m<n)
            sum+=a[m++];

        }
        // cout<<"Sum at i = "<<i<<" is "<<sum<<endl;
        if(max_sum<sum)
        {
            max_sum = sum;
        }
    }
    return max_sum;
}


int main()
{   int testcase;
    cin>>testcase;

    int n,k;
    int arr[105];
    while(testcase>0)
    {   cin>>n>>k;
        for(int i=0;i<n;i++) cin>>arr[i];
        cout<<greatRun(arr,n,k)<<endl;
    testcase--;
    }
    return 0;
}