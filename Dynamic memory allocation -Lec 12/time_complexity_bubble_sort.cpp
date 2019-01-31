//Calculate execution time of bubblesort function
#include<iostream>
#include<ctime>
using namespace std;

void bubblesort(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
                {swap(arr[j],arr[j+1]);}
        }
    }

}

void CreateArr(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        arr[i]=n-i;
    }
}

int main()
{
    int n; 
    cin>>n;
    int arr[10005];
    CreateArr(arr,n);

//A reverse sorted array has been created by createArray function
    clock_t start = clock();
    bubblesort(arr,n);
    clock_t end = clock();
    //sort function does the merge sort hence algorithm 
    cout<<end-start;
}