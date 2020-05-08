//Sammy and Simmy , Candies;
#include<iostream>
using namespace std;
int main()
{
    int n;
    int testcase;
    cin>>testcase;
    while(testcase>0)
    {cin>>n;
    int arr[1003],sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
   // cout<<sum;
    if(sum&1)
    {
        cout<<"YES"<<endl;
    }
    else { cout<<"NO"<<endl;}
    testcase--;
}

    return 0;
}
