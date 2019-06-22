//Maximum Circular sum 
#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {   int arr[1000];
        int n;
        cin>>n;
        for(int i=0;i<n;i++) cin>>arr[i];
            int max_val=0;
        for(int start=0;start<n;start++)
        {   int max_so_far=0;
            for(int i=start;i<n+start;i++)
            {   
                max_so_far+= arr[i%n];
                if(max_so_far<0) max_so_far=0;
                if(max_so_far>max_val) max_val = max_so_far;
            }
      
        }
        cout<<max_val<<endl;
    }
      
    return 0;
}