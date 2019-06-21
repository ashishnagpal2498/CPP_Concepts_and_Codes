//Vector Basics
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> v;
    v.reserve(10);
    for(int i=1;i<=4;i++) v.push_back(i*i);
        //Cannot cin directly vector as it will not expand
    for(int i=0;i<v.size();i++) {cout<<v[i]<<"  ";}
    cout<<endl<<v.capacity()<<endl;
    v.push_back(25);
    //Twice its capacity
    v.shrink_to_fit();
    v.resize(3);
    for(int i=0;i<v.size();i++) {cout<<v.at(i)<<" ";}
    cout<<endl<<v.capacity()<<endl;
    
    v.insert(v.begin(),2,33);
    for(int i=0;i<v.size();i++) {cout<<v.at(i)<<" ";}
      sort(v.begin(),v.end());
      cout<<endl; 
      for(int i=0;i<v.size();i++) {cout<<v.at(i)<<" ";} 
    return 0;    
}