//Rain water Harvesting 
#include<iostream>
#include<vector>
using namespace std;
int main()
{   vector<int> building;
    vector<int> left,right;
    int n;
    cin>>n;
    int d;
    for(int i=0;i<n;i++) {cin>>d; building.push_back(d);}
    //left;
        int left_val = building[0];
        left.push_back(left_val);
    for(int i=1;i<n;i++)
    {
       left_val = max(left_val,building[i]);
       left.push_back(left_val); // = left_val;
    }
    int right_val = building[n-1];
    right.push_back(right_val);
    for(int i=n-2;i>=0;i--)
    {
        right_val = max(right_val,building[i]);
        right.insert(right.begin(),right_val);
    }
    // for(int i=0;i<n;i++)
    // {
    //     cout<<"Building "<<building[i]<<"  Left val "<<left[i]<<" right val "<<right[i];
    //     cout<<endl;
    // }
    // Rain uint logic
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans = ans + (min(left[i],right[i]) - building[i]);
    }
    cout<<ans<<endl;
    return 0;
}