//D-days of chef Lunchtime - 
#include<iostream>
using namespace std;
int main()
{       int testcase;
    cin>>testcase;
    while(testcase--)
       { long long int A;
        cin>>A;
       long long int profit =0;
        long long int maxsum = 0;
       long long  int D1,D2;
      long long  int i=1;
        int day = 1;
       long long int chef_money=0;
       long long int chef_friend = 0;
        while(profit>=0)
        {       
                chef_friend+=i;
                    chef_money+=A;
                    profit = chef_money - chef_friend;
                    if(profit>maxsum)
                    {
                        maxsum = profit;
                        D2 = day;
                    }
                    if(profit>0)
                    {
                        D1 = day;
                    }
                    i = i<<1;
                    day++;
        }
        cout<<D1<<" "<<D2<<endl;
            }
    return 0;

}