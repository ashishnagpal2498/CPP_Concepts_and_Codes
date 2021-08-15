// Group anagrams -
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;
//  Initialising vector - take size mandatory - 
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<string> copy = strs;
    map<string,int> indexs;
    int m=0;
    for(int i=0;i<copy.size();i++)
    {   
        sort(copy[i].begin(),copy[i].end());
         auto indexVal = indexs.find(copy[i]);
         if(indexVal == indexs.end())
         {
            indexs[copy[i]] = m;
            m++;
         }
    }
    vector<vector<string> > ans(m);
    // cout<<"Ans size -- "<<ans.size()<<endl;
    // for(int i=0;i<copy.size();i++)
    // {
    //     cout<<copy[i]<<"  --  ";
    // }

    for(int i=0;i<strs.size();i++)
    {       int indexVal = indexs[copy[i]];
            // element has come onces -
        // cout<<"index val "<<indexVal<<endl;
            ans[indexVal].push_back(strs[i]);
    }
    // cout<<"ANS -:"<<endl;
    //  for(int i=0;i<m;i++)
    // {   cout<<ans[i].size()<<"  ";
    //     for(int j=0;j<ans[i].size();j++)
    //     {   
    //         cout<<ans[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
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