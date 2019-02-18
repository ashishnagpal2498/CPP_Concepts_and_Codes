//time complexity 
//Linear search , Binary search 
#include<iostream>
#include<ctime>
#include<algorithm>
//Merge sort - Sort function
using namespace std;
int binarysearch(int *arr,int n,int ele)
{
    int start=0,end=n-1,mid;
    while(start<=end)
    {
        mid = (start+end)/2;
        if(arr[mid]==ele)
        {
            return mid;
        }
        else if(arr[mid]<ele)
        {
            start=mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return -1;
}
int main()
{
    int arr[1005];
    int n;
    cin>>n;

    for(int i=0;i<n;i++)cin>>arr[i];
        int ele;
    cin>>ele;
//Start time of algorithm - 
      time_t start = time(0);
       int ans= binarysearch(arr,n,ele);
  //Ending time
   time_t end = time(0);
   cout<<end - start<<endl;
    return 0;

}