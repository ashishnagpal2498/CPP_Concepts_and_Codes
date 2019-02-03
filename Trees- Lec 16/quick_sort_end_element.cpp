//quick sort at the end pivot element;
//Complexity
// t(n) = kn + 
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int partition(int *arr,int s,int e)
{   //1) Take two pointers - starting from the initial value;
    //2) If j is <= pivot element - then swap from the ith element ;
    //3) The basic idea is to shift the elements at the right which are greater
    //4)which are less , shift left
    //s - starting of the array , e - ending
    int i=s-1;
    int j=s; 
    int pivot = arr[e];
    for(;j<e;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            // Swapping ith and jth element;
            swap(arr[i],arr[j]);
        }
    }
    // bringing the pivot element to its correct position
    swap(arr[e],arr[i+1]);
    return i+1;
}
void quick_sort(int * arr,int s,int e)
{
    if(s>=e) return;

    int p = partition(arr,s,e);
    quick_sort(arr,s,p-1);
    quick_sort(arr,p+1,e);
}
void random_function(int *arr,int s,int e)
{
    for(int i=e;i>0;i--)
    {   srand(time(NULL));
        int index = rand()%i+1;
        swap(arr[index],arr[i]);
    }
}
int main()
{
    int arr[] ={1,2,3,4,5,6,7};
    int n=7;
    for(int i=0;i<n;i++){cout<<arr[i]<<"  ";}
        random_function(arr,0,n-1);
    cout<<endl;
        for(int i=0;i<n;i++){cout<<arr[i]<<"  ";}
    quick_sort(arr,0,n-1);
cout<<endl;
for(int i=0;i<n;i++){cout<<arr[i]<<"  ";}
}