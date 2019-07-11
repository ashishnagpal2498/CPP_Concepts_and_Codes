//Time Complexity 
#include<iostream>
#include<ctime>
using namespace std;
void bubble_sort(int*arr,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;i++)
        {
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }
}
void createArr(int*arr,int n)
{
    for(int i=0;i<n;i++)
    {
        arr[i] = n-i-1;
    }
}
 int arr[1000005];
int main()
{   
    int n;
    cin>>n;
   // creating a reverse sorted array-
    createArr(arr,n);
    clock_t start = clock();
    bubble_sort(arr,n);
    clock_t end =clock();
    cout<<end-start;


    return 0;
}