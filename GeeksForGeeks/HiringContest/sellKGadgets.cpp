// GeeksForGeeks Sell K gadgets 
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
using namespace std;
ll t,n,k;
class myComp {
public:
bool operator()(pair<int,int> A, pair<int,int> B)
{
        if(A.first == B.first) 
        {
            return A.second < B.second;
        }
        return A.first < B.first;
}
};
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--)
    {   priority_queue< pair<int,int>, vector<pair<int,int> >, myComp> pq;
        cin>>n;
        int a;
        int arr[100005] = {0};
        for(int i=0;i<n;i++)
        {   cin>>a;
            arr[a]++;    
        }
        for(int i=0;i<100005;i++)
        {
            if(arr[i] !=0) pq.push(make_pair(arr[i],i)); 
        }
        int k;
        cin>>k;
        int i=0;
        while(!pq.empty() && i<k)
        {   auto TopVal = pq.top();
            cout<<TopVal.second<<" ";
            pq.pop();
            i++;
        }
        cout<<endl;
    }
    return 0;
}