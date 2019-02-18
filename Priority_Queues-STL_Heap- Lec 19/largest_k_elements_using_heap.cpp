//Heap - question ; having largest k elements in running state
#include<iostream>
#include<vector>
#include<queue>
class myCompare{
public:
    bool operator()(int a,int b)
    {
        return a>b;
    }
};
//Top k elements in a heap-
using namespace std;
void print_heap(priority_queue<int,vector<int>,myCompare> p)
{
    while(!p.empty())
    {
        cout<<p.top()<<"  ";
        p.pop();
    }
    cout<<endl;
}
int main()
{   //Maintain a min_heap of fixed size
    int n;
    int k;
    int arr[10005];
    cin>>n;
    cin>>k;
    for(int i=0;i<n;i++) cin>>arr[i];

    priority_queue<int,vector<int>,myCompare> pq;
    for(int i=0;i<n;i++)
    {   if(pq.size()!=k)
        {
            pq.push(arr[i]);
        }
        else
        {
            if(pq.top()<arr[i])
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        if(i%k==0)
        {
            cout<<"Query "<<endl;
            print_heap(pq);
        }
    }
// while(!pq.empty())
// {
//     cout<<pq.top()<<"  ";
//     pq.pop();
    
// }
return 0;
}