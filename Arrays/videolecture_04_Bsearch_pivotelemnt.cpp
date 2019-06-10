//pivot element using B_search
#include<iostream>
using namespace std;
int optimisedBsearch_pivot(int start,int n,int arr[100])
{
    int beg =start,end=n,mid;
    while(beg<=end)
    { mid=(beg+end)/2;
        if(arr[mid]>arr[mid+1]&&mid<end)
        {
            return arr[mid];
        }
        if(arr[mid]<arr[mid-1]&&mid>start)
        {
            return arr[mid];
        }
        if(arr[end]<=arr[mid]) beg = mid+1;
        else end = mid-1;
    }
}
int bsearch(int start,int n,int arr[100])
{
    int beg =start,end=n,mid;
    
    while(beg<=end)
    {  cout<<"beg  "<<beg<<"  end "<<end<<"\n";
        mid=(beg+end)/2;
        if(arr[mid]>arr[mid+1]&&arr[mid]>arr[mid-1]) return arr[mid];
        else if( arr[mid]<arr[mid-1]&&arr[mid]<arr[mid+1]) end=mid-1;
        else beg=mid+1;
    }
    return -1;
}
int main()
{ int n,arr[100];
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    //Pivot element 
       int pivotele= optimisedBsearch_pivot(0,n-1,arr);
   cout<<"\n Pivot element is: "<<pivotele;
    return 0;
}