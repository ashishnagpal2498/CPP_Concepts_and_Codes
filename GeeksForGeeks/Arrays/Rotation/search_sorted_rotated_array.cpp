//Searching in sorted Rotated - single pass -
#include<iostream>
using namespace std;
int Search(int*arr,int start,int end,int key)
{
    if(start>end)
    {
        return -1;
    }
    int mid = (start+end)/2;
    // If the lower array is sorted-
    if(arr[start]<arr[mid])
    {
        // Sorted -
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]>key)
        {
            return Search(arr,mid+1,end,key);
        }
        else
        {
            return Search(arr,start,mid-1,key);
        }
    }
    else
    {
         if(arr[mid]==key)
        {
            return mid;
        }
        else if(key>=arr[mid]&& key<=arr[end])
        {
            return Search(arr,mid+1,end,key);
        }
        else
        {
            return Search(arr,start,mid-1,key);
        }
    }
}