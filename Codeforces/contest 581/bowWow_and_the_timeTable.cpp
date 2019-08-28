//CodeForces Contest #581
#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    int p=1;
   long long int ans=0;
    long long int len = s.length();
   while()
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