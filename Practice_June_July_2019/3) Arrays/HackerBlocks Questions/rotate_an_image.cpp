//Rotate and image , AntiClock wise
#include<iostream>
using namespace std;
int main()
{
    int arr[100][100];
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) cin>>arr[i][j];
    }
    
    // Rotate an image by 90 deg
    //1) Transpose
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i<=j)
            {
                swap(arr[i][j],arr[j][i]);
            }
        }
    }
    //2) Swapping in terms of column
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j<(n/2))
            {
                swap(arr[j][i],arr[n-j-1][i]);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++) { cout<<arr[i][j]<<" ";} 
        cout<<endl;
    }
    return 0;
}