//Increasing Sequence 
#include<iostream>
using namespace std;
int main()
{   int n;
    int arr[10005];
    cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];
    bool flag=false;
    int i;
    for( i=1;i<n;i++)
    {
        if(!flag)
        {
            if(arr[i-1]<arr[i])
            {
                //less than - 
                //Pivot element found-
                flag = true;
            }
        }
        else
        {
            if(arr[i-1]>arr[i]&&i+1!=n)
            {
                break;
            }
        }
    }    
    if(i==n&&flag)
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }
    return 0;
}