//median of two srted arrays combined 
#include <iostream>
using namespace std;
float medianofarrays(int a[],int b[],int n)
{
    int low1=0,low2=0;
    int hi1=n-1,hi2=n-1;
    while(true)
    {
        int m1,m2,median1,median2;
        m1=(low1+hi1)/2;
        m2=(low2+hi2)/2;
        median1=a[m1];
        median2=b[m2];

        if(hi1-low1==1){
            float smallerElement=max(a[low1],b[low2]);
            float biggerElement=min(a[hi1],b[hi2]);
            return (float)(smallerElement+biggerElement)/2;
        }
        if(median1==median2){
            return median1; //or median2 as same
        }
        if(median1<median2)
        {
            low1=m1;
            hi2=m2;
        }
        else{
            low2=m2;
            hi1=m1;
        }
    }
}
int main()
{ 
    int a[]={1,3,5,7,10};
    int b[]={2,16,18,20,22};
    int n=5;
    cout<<medianofarrays(a,b,n);
    return 0;
}