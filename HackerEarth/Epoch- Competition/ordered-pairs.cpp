//ordered pairs
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
int main()
{   set <int,int> s;
    int n;
    cin>>n;
    int arr[100];

    for(int i=1;i<=n;i++) cin>>arr[i];
        int frequency[100]={0};
    //Frequency array
    sort(arr,arr+n+1);
    for(int i=1;i<=n;i++) cout<<arr[i];
        cout<<endl;
    for(int i=1;i<=n;i++)
    {
        // int temp = arr[i];
        // for(int j=1;j<=n;j++)
        // {
        //     if(arr[j]==temp)
        //     {   
        //         frequency[i]++;
        //     }
        // }
        auto uppbound = upper_bound(arr,arr+n+1,arr[i]);
        auto lowbound = lower_bound(arr,arr+n+1,arr[i]);
        frequency[arr[i]] = uppbound - lowbound;
    }
    //Frequency array
    for(int i=1;i<=n;i++)
    {
        cout<<frequency[i]<<"  ";
    }
    int orderedpairs=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(arr[j]<=frequency[arr[i]]&&arr[i]<=frequency[arr[j]])
                {   
                    cout<<arr[i]<<", "<<arr[j]<<endl;
                    orderedpairs++;
                }
            }
        }
        cout<<orderedpairs;
        return 0;
}