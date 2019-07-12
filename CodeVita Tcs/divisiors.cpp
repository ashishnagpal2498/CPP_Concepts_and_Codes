//Divisors of a number
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int T;
    cin>>T;
    int n;
    while(T--)
    {
        cin>>n;
        vector<int> divisors;
        for(int i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                divisors.push_back(i);
                divisors.push_back(n/i);
            }
        }
        int sz = divisors.size();
        sort(divisors.begin(),divisors.end());
        for(int i=0;i<sz;i++)
        {
            cout<<divisors[i]<<" ";
         }
    }

    return 0;
}