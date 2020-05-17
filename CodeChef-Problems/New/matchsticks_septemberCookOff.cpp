//Matchsticks
//September CookOFF
#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int arr[]={6,2,5,5,4,5,6,3,7,6};
    int testcase;
    cin>>testcase;
    int n1,n2,ans=0;
    while(testcase--)
    {
        cin>>n1>>n2;
        ans = n1+n2;
        int count=0;
        while(ans)
        {
            int rem = ans%10;
            count+=arr[rem];
            ans/=10;
        }
        cout<<count<<endl;
    }
    return 0;
}