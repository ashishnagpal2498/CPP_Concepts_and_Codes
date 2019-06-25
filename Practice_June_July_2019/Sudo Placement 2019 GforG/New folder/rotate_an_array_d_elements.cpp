//rotate an array by d elements
#include<iostream>
using namespace std;
int main()
{   int T;
    cin>>T;
    while(T--)
    {   int n;
        int arr[205];
        int d;
        cin>>n;
        cin>>d;
    for(int i=0;i<n;i++) cin>>arr[i];
     
    int temp[205];
    //int temp_size =0;
     for(int i=0;i<d;i++)
     {
        temp[i] = arr[i];
    
     }

     for(int i=d;i<n;i++)
     {
        arr[i-d] = arr[i];
     }   
     for(int i=0;i<d;i++)
     {
        arr[n-d+i] = temp[i];
     }
     for(int i=0;i<n;i++){cout<<arr[i]<<" ";}
     cout<<endl;
     }   

    return 0;
}