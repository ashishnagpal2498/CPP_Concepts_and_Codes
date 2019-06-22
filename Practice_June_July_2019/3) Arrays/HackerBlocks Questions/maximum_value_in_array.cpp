//hackerBlocks Questions - Max value in array
#include<iostream>
using namespace std;
int max_val(int *arr,int n)
{   int max_v = -100000000;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max_v)
        {
            max_v = arr[i];
        }
    }
    return max_v;
}

int main()
{
    int n,arr[10005];
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
     cout<<max_val(arr,n)<<endl;   
    return 0;
}