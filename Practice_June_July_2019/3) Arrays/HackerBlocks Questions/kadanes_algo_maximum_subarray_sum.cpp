//Kadane's Algorithm - Maximum subarray sum-
#include<iostream>
using namespace std;
int main()
{   int T;
    cin>>T;
    while(T--)
    {   int arr[100005];
        int n;
        cin>>n;
        for(int i=0;i<n;i++) cin>>arr[i];
        //Kadanes's algorithm
        int max_val=0,max_sofar =0;
        for(int i=0;i<n;i++)
        {
            max_sofar+= arr[i];
            if(max_sofar<=0) max_sofar=0;
            
            if(max_sofar>max_val) max_val = max_sofar;

        }       
        cout<<max_val<<endl;
    }
    return 0;
}