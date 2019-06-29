//form Biggest Number
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool myCompare(string s1,string s2)
{
    return s1>s2;
}
int main()
{   int T;
    cin>>T;
    while(T--)
    {   vector<string> str;
        int n;
        cin>>n;
        string s;
        cin.get();
        for(int i=0;i<n;i++) 
            { cin>>s;
                str.push_back(s);
             }
        sort(str.begin(),str.end(),myCompare);
        string ans="";
        for(int i=0;i<n;i++) 
            {  ans+=str[i];
                // cout<<str[i];

            } 
            // cout<<ans.length();
            cout<<ans<<endl;
    }
    return 0;
}