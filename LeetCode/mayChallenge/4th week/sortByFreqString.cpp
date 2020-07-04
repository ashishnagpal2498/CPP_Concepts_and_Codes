// Sort characters by frequency
#include<iostream>
#include<string>
#include<queue>
using namespace std;
string sortString(string s)
{   priority_queue<pair<int,char> > pq;
    int freq[256] = {0};
    string ans ="";
    for(int i=0;i<s.size();i++)
    {
        freq[s[i]]++;
    }
    for(int i=0;i<256;i++)
    {   if(freq[i]!= 0)
        pq.push(make_pair(freq[i],char(i)));
    }
    while(!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        for(int i=0;i<p.first;i++)
        {
            ans+=p.second;
        }
    }
    return ans;
}
int main()
{
    string s;
    cin>>s;
    string ans = sortString(s);
    cout<<ans;
    return 0;
}