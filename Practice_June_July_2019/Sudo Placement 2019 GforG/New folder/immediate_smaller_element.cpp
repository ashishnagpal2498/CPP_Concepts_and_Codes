//Immediate smaller element
#include<iostream>
using namespace std;
int main()
{
    int n;
    int arr[1000005];
    int T;
    cin>>T;
    while(T--)
    {   cin>>n;
    
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        for(int i=0;i<n;i++)
        {
            if(arr[i+1]<arr[i]&&i+1<n)
            {
                cout<<arr[i+1]<<" ";
            }
            else
            {
                cout<<-1<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}