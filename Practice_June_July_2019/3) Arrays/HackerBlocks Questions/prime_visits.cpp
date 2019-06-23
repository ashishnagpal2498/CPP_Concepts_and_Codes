//Prime Visits
#include<iostream>
using namespace std;
bool isPrime(int n)
{
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0) return false;
    }
    return true;
}
int main()
{
    int arr[100005];
    arr[0] =0; arr[1]=0; arr[2] =1;
    for(int i=3;i<10000;i++)
    {
        if(isPrime(i))
        {
            arr[i]= arr[i-1]+1;
        }
        else
        {
            arr[i] = arr[i-1];
        }
    }
    int n;
    cin>>n;
    //for(int i=0;i<21;i++) {cout<<arr[i]<<" ";} cout<<endl;
    while(n--)
    {   int a,b;
        cin>>a>>b;
        cout<<arr[b]-arr[a-1]<<endl;
    }
    return 0;
}