// Fractional Knapsack -
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll t,n;
ll arr[200005];
 // first - value , second- weight
bool compare(pair<ll,ll> A, pair<ll,ll> B)
{
    double r1 = A.first / A. second;
    double r2 = B.first / B.second;
    return r1>r2;
}
double fractionalKnapsack(vector<pair<ll,ll> > arr)
{   // Sort array -
    sort(arr.begin(),arr.end(),compare);
    ll currWeight =0;
    ll W = t;
    double priceCollected = 0.0;
    for(int i=0;i<n;i++)
    {
        if(currWeight+ arr[i].second <= W){
            currWeight+=arr[i].second;
            priceCollected+=arr[i].first;
        }
        else{
            double remain = W- currWeight;
            priceCollected+= arr[i].first* (remain/arr[i].second);
            // W-=(remain/arr[i].second);
            break;
        }
    }
    return priceCollected;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t>>n;
    ll a;
    vector< pair<ll,ll> > arr;
    for(int i=0;i<n;i++){
        cin>>a;
        arr.push_back(make_pair(a,0));
    }
    for(int i=0;i<n;i++){
        cin>>a;
        arr[i].second = a;
    }
    cout<<"Maximum value "<<fractionalKnapsack(arr);
    return 0;
}