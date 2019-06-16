//searching in sorted rotated array
#include<iostream>
using namespace std;
int b_search_pivot(int *arr,int s ,int e)
{
    int mid;
    while(s<=e)
    {   
        mid = (s+e)/2;
        if(arr[mid]>arr[mid+1]&&mid<e)
        {
            return mid;
        }
        else if(arr[mid]<arr[mid-1]&&mid>s)
        {
            return mid-1;
        }
        else if(arr[mid]>=arr[e])
        {
            s = mid+1;
        }
        else
        {
            e = mid-1;
        }
    }
}
int b_search(int*arr,int s,int e,int element)
{
    int mid;
    while(s<=e)
    {
        mid = (s+e)/2;
        if(arr[mid]==element)
        {
            return mid;
        }
        else if(element>arr[mid])
        {
            s = mid+1;
        }
        else 
        {
            e = mid-1;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {5,6,7,8,9,10,1,2,3,4};
    int n = sizeof(arr)/sizeof(int);
    cout<<"N is "<<n<<endl;
    //Find the Pivot Index-
    int element;
    cin>>element;
    int pivot_index = b_search_pivot(arr,0,n-1);
    cout<<pivot_index;
    int s,e;
    if(arr[pivot_index]>=element&&arr[0]<=element)
    {
        s = 0;
        e = pivot_index;
    }
    else
    {   s = pivot_index+1;
        e = n-1;
        
    }
    cout<<"Element found at position  "<<b_search(arr,s,e,element);
    return 0;
}