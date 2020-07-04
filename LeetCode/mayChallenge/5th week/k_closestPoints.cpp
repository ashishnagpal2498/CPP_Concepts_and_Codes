// K closest points to origin 
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<functional>
using namespace std;
double eucleidDistance(int x,int y)
{
    double v = double(sqrt(x*x + y*y));
    return v;
}
class myComp {
public:
    bool operator() (pair<double,int> A, pair<double,int> B)
    { 
        return abs(A.first) > abs(B.first);
    }
};
vector<vector<int> > kClosest(vector<vector<int> > points,int k)
{   long long int n = points.size();
    priority_queue< pair<double,int> ,vector<pair<double,int> >, myComp >  q;
    // 1st distance 2nd index;
    vector<vector<int> > ans(k);
    for(int i=0;i<n;i++)
    {
        double distance = eucleidDistance(points[i][0],points[i][1]);
        q.push(make_pair(distance,i));
    }
    int i=0;
    while(!q.empty() && i<k)
    {
        auto p = q.top();
        q.pop();
        ans[i].push_back(points[p.second][0]);
        ans[i].push_back(points[p.second][1]);
        i++;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int> > points(n);
    int a;
    int k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>a;
            points[i].push_back(a);
        }
    }
    cin>>k;
    vector<vector<int> > ans = kClosest(points,k);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
}