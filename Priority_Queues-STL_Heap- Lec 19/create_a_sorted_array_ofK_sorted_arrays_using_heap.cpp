//Create a sorted array of K - sorted array elements
#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
class myCompare{
public:
    bool operator()(pair<int,int> a,pair<int,int> b)
    {
        return a.first>b.first;
    }
};
int main()
{
    int n;
    int k;
    priority_queue<pair<int,int>,vector<pair<int,int>,myCompare> pq;
    //First store - that is the element - second - value
    cin>>k>>n;
    //Put infinity in every
    int arr[10005][10005];
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<n;j++)
            cin>>[i][j];
    }
    for(int i=0;i<n;i++)
    {

    }
    return 0;
}