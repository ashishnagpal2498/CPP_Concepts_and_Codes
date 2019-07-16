//anti_matter Sti 2 
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[1005];
    for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr,arr+n);
    int min_ele = arr[0];
    for(int i=1;i<n;i++)
    {
        int diff = arr[i] - arr[i-1];
        if(diff<min_ele) min_ele = diff;
    }
    cout<<min_ele<<endl;
    return 0;
    
}