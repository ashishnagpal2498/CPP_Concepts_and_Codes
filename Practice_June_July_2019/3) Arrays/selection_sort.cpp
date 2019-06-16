//Selection Sort
#include<iostream>
using namespace std;
int main()
{
    int arr[] ={ 2,4,1,0,8,7,5,6};
    int n = sizeof(arr)/sizeof(n);

    for(int i=0;i<n;i++)
    {
        //Minimum element -
        int minIndex = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[minIndex]) minIndex = j;
        }
        swap(arr[i],arr[minIndex]);
    }
    for(int i=0;i<n;i++) { cout<<arr[i]<<" ";}
        return 0;
}