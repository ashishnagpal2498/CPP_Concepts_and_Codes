//sum of two arrays
#include<iostream>
using namespace std;
void sumoftwoArrays(int a[],int n,int b[],int m,int c[])
{
    int i=n-1;
    int j=m-1;
    int k=0;
    int sum=0,carry=0;
    while(i>=0&&j>=0)
    {   sum =a[i]+b[j];
        c[k]=sum%10+carry;
        carry=sum/10;
        k++;
        j--;
        i--;

    }
    //For unequal arrays;
    while(i>=0)
    {
        c[k]=a[i]+carry;
        i--; k++;
    }
    //case where carry is 1
    if(carry==1)
    {
        c[k]=carry;
        k++;

    }
    for(int i=k-1;i>=0;i--)
    {
        cout<<c[i]<<", ";
    }
}
int main()
{   
    //Always take values according to given contraints
    int a[1000],b[1000],c[1000]={0};
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
        cin>>m;
    for(int i=0;i<m;i++) cin>>b[i];
        if(n>m) sumoftwoArrays(a,n,b,m,c);
    else sumoftwoArrays(b,m,a,n,c);
    return 0;
}