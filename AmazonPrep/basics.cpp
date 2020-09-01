// vector array strings and character array
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
ll arr[200005];
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cin>>n;
    // int arr[100005];  
    // vector<int> a;
    // int arr[200][200];
    // // int n,m ;
    // // cin>>n>>m;
    // vector<pair<int,int> > ab[10];
    // vector<vector<int> > ans;
    // // 
    // // A[0] -> that is a vector
    // int lmn;
    // // No of rows->
    // int n = ans.size();
    // for(int i=0;i<n;i++){
    //     int m = ans[i].size();
    //     for(int j=0;j<m;j++){
    //         // ans[i][j] -->
    //     }
    // }
    // for(int i=0;i<n;i++){
    //     // cin>>lmn;
    //     ans[i].push_back(i);
    //     ans[i].push_back(i*i);
    // }
    // // ans[0] -> 0  0     
    // // ans[1] -> 1  1
    // // ans[2] -> 2 4
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         ans[i].push_back(j);
    //     }
    // }
    // ans [0] -> 0 1 2.......
    // ans [1] -> 
    // ans [2] -> 2 2
    //

    // Subarray -> [1,2,3]
    // [1][1,2][1,2,3][2][2,3][3]
    // (n*(n+1))/2 = 6
    int arr[] = {1,2,3};
    int n=3;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int k=i;k<=j;k++){
                cout<<arr[k]<<" ";
            }
            cout<<endl;
        }
    }
    // O(n^3) -> 
    //-> 
    // 1 sec -> 10^8 , n 10^5 -> O(n) , O(nlogn)

    //sorting =- O(nlogn)


    // char s1[10];
    // string s;
    // getline(cin,s);
    // cin.getline(s1,100,'\n');
    // cout<<s<<" -> "<<s1;

    // Subarray -> total -> sum % n;
    // Prefix -> 
    // [1,] 


    //->

    // subset/ SubSequence -> [1,2,3]
    // [][1][1,2][1,2,3][2][2,3][3][1,3]
    // subsets -> '1>>n' -> 2^3 = 8



    return 0;
}    