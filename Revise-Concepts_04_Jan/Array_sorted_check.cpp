//Check if the array is sorted or not
//using recursion
#include<iostream>
using namespace std;

bool sorted_arr(int *arr,int n)
{
    // Base Case
    if(n==1)
    {
        return true;
    }
    // Recursive case
    if(arr[0]<arr[1])
    {
        bool smallarr = sorted_arr(arr++,n-1);
        if(smallarr)
        {
            return true;
        }
    }
    return false;
}

// Linear Search Using Recursion
int l_search(int *arr,int n,int element)
{
    // Base Case
    if(n==0)
    {
        return -1;
    }
    // Recursive
    if(arr[0]==element)
    {
        return 0;
    }
    int chottaarray = l_search(arr+1,n-1,element);
    if(chottaarray ==-1)
    {
        return -1;
    }
    else{
        return 1+chottaarray;
    }
}

int main()
{
    int a[] ={1,3 ,6,8,10};
    int n = 5;
    cout<<sorted_arr(a,n);
    cout<<l_search(a,5,6); 
    return 0;
}