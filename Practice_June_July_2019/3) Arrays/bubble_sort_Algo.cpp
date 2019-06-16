//Bubble_sort Algo
#include<iostream>
using namespace std;
void Bubble_sort(int *arr,int n)
{
    for(int i=0;i<=n-1;i++)
    {
        for(int j=0;j<=n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void print(int*arr,int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"  ";
    }
}
int main()
{
    int arr[] = {5,4,2,1,3,9,7,8};
    int n = sizeof(arr)/sizeof(int);

    Bubble_sort(arr,n);
    print(arr,n);

    return 0;
}