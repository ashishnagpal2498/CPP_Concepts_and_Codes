//Map -
#include<iostream>
#include<map>
using namespace std;
class Comp{
public:
    bool operator() (const int &a,const int &b) {return a>b;}
};
int main()
{
    map<int,int,Comp> mp;
    mp.insert({1,2});
    mp.insert({3,4});
    for(auto it: mp)
    {
        cout<<it.first<<" "<<it.second<<" ";
    }
    map<int,int> m;
    m[1] = 2;
    cout<<endl<<m.size()<<endl;
    int n = m[0];
    cout<<n<<endl<<m.size()<<endl;
    cout<< (m.find(1)== m.end())<<endl;
    return 0;
}