//XOR of array
//Find B such that b = Ai+1 +Aj+1;
#include<iostream>
using namespace std;

int Xor_of_Array(int *a,int n)
{   
    int sum=0,l=0;
    for(int i=0;i<n;i++)
    {
        // for(int j=i;j<n;j++)
            // {   if(i==j)
                {int val=a[i]+a[i];
                    sum = sum^val;}
                // else{
                //     // int val = a[i]+a[j];
                //     // b[l++] =val ^val; 
                // }
            // }
    }
    // cout<<l;
    // int bans=0;
    // for(int i=0;i<l;i++)
    // {   //cout<<b[i]<<" ";
    //     bans= bans^b[i];
    // }
    return sum;
}


int main()
{   int testcase;
    cin>>testcase;
    int arr[100005];
    int n;
    while(testcase>0)
    {
    
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans= Xor_of_Array(arr,n);
    cout<<ans<<endl;
    // cout<<Xor_of_Array(arr,4);
    testcase--;
    }
    return 0;
}