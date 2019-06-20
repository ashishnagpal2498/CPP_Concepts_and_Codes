// Target sum pair - sliding window approach
#include<iostream>
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
    int i=0,j=n-1;
    
    while(i<j)
    {
        if(arr[i]+arr[j]==key)
        {
            cout<<arr[i]<<" "<<arr[j]<<endl;
            j--;
            i++;
        }
        else if(arr[i]+arr[j]>key)
        {
            j--;
        }
        else{ i++;}
    }
    return 0;
}