//mergeSort
#include<iostream>
using namespace std;
void merge(int*arr,int start,int mid,int end)
{
    // if(n==0)
    // {
    //     return b;
    // }
    // if(m==0)
    // {
    //     return a;
    // }
    int n1 = (mid -start) +1 , n2 = (end-mid);
    int *temp = new int [n1];
    int *temp2 = new int [n2];
    // int *c = new int[n+m];
    for (int i = 0; i < n1; i++) 
        temp[i] = arr[start + i]; 
    for (int j = 0; j < n2; j++) 
        temp2[j] = arr[mid + 1+ j]; 
    int i=0,j=0,k=start;
    while(i<n1&&j<n2)
    {
        if(temp[i]<temp2[j])
        {
            arr[k++] = temp[i++];
        }
        else
        {
            arr[k++] = temp2[j++];
        }
    }
    //Array still left
    while(i<n1)
    {
        arr[k++] = temp[i++];
    }
    while(j<n2)
    {
        arr[k++] = temp2[j++];
    }
    cout<<"C ---   "; 
    for(int i=0;i<n1+n2;i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
    // return c;
}
void mergeSort(int*arr,int start,int end)
{
    //Base case -
    if(start<end)
    //Recursive case -
    {int mid = (start+end)/2;
    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    // int sz = (mid -start) +1;
    // int sz2 = (end-mid)+1;
     merge(arr,start,mid,end);
    }
}

int main(int argc, char const *argv[])
{   
    int arr[100005];
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i]; 
       mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++) {cout<<arr[i]<<"  ";}
    return 0;
}