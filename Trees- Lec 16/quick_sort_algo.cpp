//Trees class - 28-07
//21 -12 -18
//Quick-sort
//Divide and conquer approach
#include<iostream>
using namespace std;

int my_partition(int *arr,int upper,int lower)
{   //1st element is the pivot element
    int pivot = arr[lower];
    int p=lower+1;
    int q=upper;
    while(q>=p)
    {
        while(pivot>arr[p]) p++;
        while(pivot<arr[q]) q--;
        if(q>p)
        {
            //swaping
            swap(arr[p],arr[q]);
        }
    }
    swap(arr[q],arr[lower]);
    return q;
}

void quick_sort(int *arr,int upper,int lower)
{
    if(upper>lower) 
    {int i = my_partition(arr,upper,lower);
    quick_sort(arr,i-1,lower);
    quick_sort(arr,upper,i+1);
    }
}

int main()
{
    int arr[]={3,1,4,2,5};
    int n = 5;
    for(int i=0;i<5;i++) cout<<arr[i];
        cout<<endl;
    quick_sort(arr,4,0);
     for(int i=0;i<5;i++) {cout<<arr[i]<<"  "; }

    return 0;
}