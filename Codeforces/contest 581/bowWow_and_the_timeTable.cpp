//CodeForces Contest #581
#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    int p=1;
    int ans=0;
    int len = s.length();
    for(int i=0;i<len;i++)
    {
        ans+= ((int) (s[len-i-1] -'0'))*p;
        p=p*2;
    }   
    p=1;
    int count=0;
    while(p<ans)
    {
        p=p*4;
        count++;
    }
    cout<<ans<<endl;
    cout<<count;
    return 0;
}