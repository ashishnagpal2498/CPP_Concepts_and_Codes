//median of two Sorted Arrays 
#include<iostream>
using namespace std;
void median_sorted(int *arr1,int n,int *arr2,int m)
{   
    if(n==1&&m==1) {cout<<(arr1[0] +arr2[0])/2;}
    int m1,m2,median1,median2;
    int low1 = 0,hi1 =n-1,low2=0,hi2=m-1;
    while(low1<=hi1&&low2<=hi2)
    {
        m1 = (low1+hi1)/2;
        m2 = (low2+hi2)/2;
        median1 = arr1[m1];
        median2 = arr2[m2];
        if(hi1-low1<=1||hi2-low2<=1)
        {
            int ans1 = max(arr1[low1],arr2[low2]);
            int ans2 = min(arr2[hi2],arr1[hi1]);
            cout<< (ans1+ans2)/2;
            break;
        }
        if(median1==median2)
        {
            cout<<median1;
        } 
        else if(median1<=median2)
        {
            low1 = m1;
            hi2 = m2;
        }
        else
        {
            low2 = m2;
            hi1 = m1;
        }
    }
}
int main()
{
    int n,m,arr1[10005],arr2[10005];
    cin>>n;
    cin>>m;
    for(int i=0;i<n;i++) cin>>arr1[i];
    for(int i=0;i<m;i++) cin>>arr2[i];
    median_sorted(arr1,n,arr2,m);    
    return 0;
}