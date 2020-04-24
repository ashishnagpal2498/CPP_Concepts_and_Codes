#include<iostream>
#include<deque>
using namespace std;
int main()
{   deque<int> d;
    int arr[100005];
    //
    int n,t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<n;i++) cin>>arr[i];
        for(int i=0;i<n;i++)
        {
            if(!d.empty() && d.front()<= i-k)
                d.pop_front();
            while(!d.empty() && arr[d.back()] <= arr[i])
                d.pop_back();
            d.push_back(i);
            if( i >= k) {
                cout<<d.front()<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}