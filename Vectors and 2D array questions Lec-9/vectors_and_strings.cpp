#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
bool mycomapre(string s1,string s2)
{
    return s1>s2; //decreasing order
}
int main()
{
    vector<string> v;
    string s;
    // char arr[100];
    // cin>>s;
    getline(cin,s);
    // cout<<s;
    while(s!="-1")
    {
        v.push_back(s);
        getline(cin,s);
    }
    sort(v.begin(),v.end(),mycomapre);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }
    return 0;
}