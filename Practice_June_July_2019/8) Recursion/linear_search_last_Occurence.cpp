//last occurence of a number - recursion
#include<iostream>
using namespace std;
int last_occ(int *arr, int n,int key)
{   //Base case when no element is in the array
    if(n==0)
    {
        return -1;
    }
    int chhotaarr = last_occ(arr+1,n-1,key);

    if(chhotaarr==-1)
    {
        if(arr[0]==key)
        {
            return 0;
        }
        else
            return-1;
    }
    return 1+chhotaarr;
}
int main()
{
    int n;
    cin>>n;
    int arr[10005];
    for(int i=0;i<n;i++) cin>>arr[i];
    int m;
    cin>>m;
    cout<<last_occ(arr,n,m);

    return 0;
}