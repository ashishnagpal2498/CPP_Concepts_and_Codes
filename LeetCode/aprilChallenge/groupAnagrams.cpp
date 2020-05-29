// Group anagrams -
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<string> copy = strs;
    vector<string> s;
    vector<vector<string> > ans(strs.size(),s);
    for(int i=0;i<copy.size();i++)
    {
        sort(copy[i].begin(),copy[i].end());
    }
    for(int i=0;i<copy.size();i++)
    {
        cout<<copy[i]<<"  --  ";
    }
    map<string,int> indexs;
    int m=0;
    cout<<strs.size()<<endl;
    for(int i=0;i<strs.size();i++)
    {   auto indexVal = indexs.find(copy[i]);
        if(indexVal == indexs.end())
        {
            // element has come onces -
            indexs[copy[i]] = m;
            m++;
            ans[m].push_back(strs[i]);
            cout<<"Here IF "<<ans[m][0]<<endl;
        }
        else{
            ans[(*indexVal).second].push_back(strs[i]);
            cout<<"IndexVal "<<indexVal->first<<" Index : "<<indexVal->second
            <<"Value : "<<ans[indexVal->second][ans[indexVal->second].size()-1]<<endl;
        }
    }
    cout<<"ANS -:"<<endl;
     for(int i=0;i<ans.size();i++)
    {   cout<<ans[i].size()<<"  ";
        for(int j=0;j<ans[i].size();i++)
        {   
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<string> str(n);
    for(int i=0;i<n;i++){
        cin>>str[i];
    }
    vector<vector<string> > ans = groupAnagrams(str);
}