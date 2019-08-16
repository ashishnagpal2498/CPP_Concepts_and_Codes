//Sum it up - 
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#define ArrIn for(int i=0;i<n;i++) cin>>arr[i];
#define Arrout for(int i=0;i<n;i++) {cout<<arr[i]<<" ";}
using namespace std;
set< vector<int > > s;
void target_sum(int*arr,int n,vector<int> v,int target)
{
    if(n==0)
    {
        return;
    }
    if(target==0)
    {   //cout<<"SUM EQUAL "<<endl;
        s.insert(v);
        // for(int i=0;i<v.size();i++)
        // {
        //     cout<<v[i]<<" ";
        // }
        // cout<<endl;
        return;
    }
    if(arr[0]<=target)
    {   
        target -= arr[0];
        // cout<<target<<endl;
        v.push_back(arr[0]);
        target_sum(arr+1,n-1,v,target);
        //BackTrack - 
        target+= arr[0];
        v.pop_back();
    }
    //leave the number and then test -
    //back track
    target_sum(arr+1,n-1,v,target);
    
    return;
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int arr[10005];
    ArrIn;
    sort(arr,arr+n);
    int target ;
    vector<int> v;
    cin>>target;
    // Arrout;
    // cout<<endl;
    int sum=0;
    target_sum(arr,n,v,target);
    for(auto i=s.begin();i!=s.end();i++)
    {   vector<int > temp = *i;
        for(int j=0;j<temp.size();j++)
        {
            cout<<temp[j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}