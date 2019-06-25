//arrange in pendulum form 
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {   int n;
        int arr[105];
        cin>>n;
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr,arr+n);
        int i=0; //j=n-1,k=n-2,;
        int temp[105];
    int j= n-1;
    int newsize = n-1;
    bool flag;
    if(n&1)
     flag = true;
    else flag = false;
    while(i<=newsize)
    {   if(flag)
        {   temp[i++] = arr[j];
            flag = false;
        } 
        else
        {
            temp[newsize--] = arr[j];
            flag = true;
        }
        j--;
    } 
    for(int i=0;i<n;i++)
    {
        cout<<temp[i]<<" ";
    }
    cout<<endl;
    }
    return 0;   
}