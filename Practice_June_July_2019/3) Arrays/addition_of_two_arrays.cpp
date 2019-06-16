//Addition of two arrays 
#include<iostream>
using namespace std;
void array_sum(int *a,int n,int*b,int m)
{   int c[10005];
    int k=0;
    int carry =0;
    int i=n-1,j=m-1;
    int s=0;
    while(i>=0&&j>=0)
    {   
        s = a[i] + b[j] + carry;
        c[k] = s%10;
        carry = s/10;
        i--; j--; k++;
    }
    while(i>=0)
    {
        c[k++] = a[i--];
    }
    for(int l = k-1;l>=0;l--)
    {cout<<c[l]<<" ";}  
    cout<<"END";
}
int main()
{

    int n,m;
    int a[10005],b[10005];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>m;
    for(int i=0;i<m;i++) cin>>b[i];

    if(n>m) array_sum(a,n,b,m);
    else array_sum(b,m,a,n);    

    return 0;
}