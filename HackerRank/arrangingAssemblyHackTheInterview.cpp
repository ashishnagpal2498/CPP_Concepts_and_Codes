// Arranging for assembly
#include<iostream>
#include<algorithm>
using namespace std;
string arrangeStudents(vector<int> a,vector<int> b)
{
    int i=0,j=0,n = a.size();
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
   // start
    bool flag = false;
    for(int m=0;m<n;m++)
    { if(a[i]<b[i]) {flag = true; break;}}
    while(i<n&&j<n)
    {
        if(!flag and b[j]<=a[i]) {j++; flag=true;}
        else if(flag and a[i]<=b[j]){i++; flag=false;}
        else {
            return "NO";
        }
    }
    return "YES";
}
int main()
{
    int n;
    cin>>n;
    vector<int> boys(n),girls(n);
    for(int i=0;i<n;i++) cin>>boys[i];
    for(int i=0;i<n;i++) cin>>girls[i];    
    string ans = arrangeStudents(boys,girls);
    cout<<ans<<endl;
    return 0;
}