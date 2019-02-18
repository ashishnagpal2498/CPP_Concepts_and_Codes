#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>solution(vector<int>&house,vector<int>stores)
{
    int szofhouse = house.size();
    int szofstores = stores.size();
    vector<int> ans;
    int dis;

    for(int i=0;i<szofhouse;i++)
    {   int mindistance= 1000000;
        int pos=-1;
        for(int j=0;j<szofstores;j++)
        {   
            dis = (house[i] - stores[j]);
            if(dis<0) 
                { dis=dis*-1;
                    //wasnegative=true;
                 }
            if(mindistance>dis)
            {   pos = j;
                mindistance= dis;
            } 
        }
        //if(wasnegative) mindistance*=-1;
        ans.push_back(stores[pos]);
    }


    return ans;
}


int main()
{
    vector<int> stores;
    vector<int> house;
    int n,m;
   
    int a;
    cin>>n>>m;
    //n is the no. of stores
    //m is the no. of houses
    //max gives the max distance
    for(int i=0;i<n;i++)
    {
        cin>>a;
       
        stores.push_back(a);
    }
   for(int i=0;i<m;i++)
    {
        cin>>a;
        house.push_back(a);
    }
    sort(stores.begin(),stores.end());
    vector<int> ans;
    ans = solution(house,stores);
    for(int i=0;i<ans.size();i++)
        {cout<<ans[i]<<"   ";}
    return 0;
}