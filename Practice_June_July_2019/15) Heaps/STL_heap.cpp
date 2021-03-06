//Priority Queue
#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
class myCompare{
public:
    bool operator()(int a,int b){
        return a>b;
    }
};
int main()
{   
    int arr[] = {1,4,6,2,3,0,10,12};
    int n = sizeof(arr)/sizeof(int);
    priority_queue<int> pmax;
    priority_queue<int , vector<int> , myCompare > pq;
    for(int i=0;i<n;i++)
    {
        pq.push(arr[i]);
    }
    while(!pq.empty())
    {
        cout<<pq.top();
        cout<<" ";
        pq.pop();
    }
    return 0;
}