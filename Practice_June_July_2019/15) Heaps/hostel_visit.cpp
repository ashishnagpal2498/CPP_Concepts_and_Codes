#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
int main(int argc, char const *argv[])
{
    priority_queue<int> pq;
    //create a k size max heap
    int q,k;
    cin>>q>>k;
    int query,val1,val2;
    while(q--)
    {
        cin>>query;
        if(query==1)
        {
            cin>>val1>>val2;
            int ans = val1*val1 + val2*val2;
            if(pq.size()<k)
            {
                pq.push(ans);
            }
            else
            {
                if(pq.top()>=ans)
                {
                    pq.pop();
                    pq.push(ans);
                }

            }
        }
        else
        {
            cout<<pq.top()<<endl;
        }
    }
    return 0;
}