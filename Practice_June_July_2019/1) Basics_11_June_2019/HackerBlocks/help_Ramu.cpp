//Help Ramu - 
#include<iostream>
using namespace std;
int main()
{   int T;
    cin>>T;
    while(T--)
    {   int n,m,c1,c2,c3,c4,cabs[10005],rickshaw[10005];
        cin>>c1>>c2>>c3>>c4;
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
        cin>>rickshaw[i];
        }
        for(int i=0;i<m;i++)
        {      //Times ith cab is used;
            cin>>cabs[i];
        }
    //Minimum cost
    int ans1=0,ans2=0,finalans=0;
    for(int i=0;i<n;i++)
    {
        ans1 = ans1 + min(c1*rickshaw[i],c2);
       } 
       // Unlimited ticket 
     ans1 = min(ans1,c3);  
      for(int i=0;i<m;i++)
      {
        ans2 = ans2 + min(c1*cabs[i],c2);
      } 
      ans2 = min(ans2,c3);
      finalans = min(ans1+ans2,c4);
      cout<<finalans<<endl;
    }
    return 0;
}