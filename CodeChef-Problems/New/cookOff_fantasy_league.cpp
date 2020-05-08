//Players codechef
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
class Comp {
public:
    bool operator()(int a,int b)
    {
        return a>b;
    }
};
int T;
int n;
int arr[100005];
int main()
{   cin>>T;
    while(T--)
    {cin>>n;
       int a; 
    int price;
    cin>>price;
    // priority_queue<int,vector<int>,Comp> def,striker;
    // def.push(8);
    // def.push(9);
    // while(!def.empty()) {cout<<def.top()<<" "; def.pop();}
    for(int i=0;i<n;i++)
        cin>>arr[i];
    long long int def_Min = INT8_MAX,strike_Min= INT8_MAX;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(a==0&& arr[i]<def_Min)
        {
            def_Min = arr[i];
        }
        else if(a==1 && arr[i]< strike_Min)
        {
            strike_Min = arr[i];
        }
    }
    if(price+def_Min+strike_Min<=100) 
    {
        cout<<"yes"<<endl;
    }
    else
    {
        cout<<"no"<<endl;
    }
    }
    return 0;
}