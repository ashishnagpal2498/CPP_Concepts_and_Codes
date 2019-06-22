//target sum triplet
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{   int arr[10005];
    int n,key; 
    //Sliding window approach
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }   
    cin>>key;
    
    sort(arr,arr+n);
    for(int k=0;k<n;k++)
    {   int target_sum = key - arr[k];
        int i=k+1,j=n-1;
        while(i<j)
        {
            if(arr[i]+arr[j]==target_sum)
            {
                cout<<arr[k]<<", "<<arr[i]<<" and "<<arr[j]<<endl;
                j--;
                i++;
            }
            else if(arr[i]+arr[j]>target_sum)
            {
            j--;
            }
            else{ i++;}
        }
    }
    return 0;
}