//Atm - Machine Code chef
#include<iostream>
using namespace std;
int main()
{
    int testcase;
    cin>>testcase;
    int n;
    int money;
    int ppl[105];
    while(testcase>0)
    {
        cin>>n>>money;
        for(int i=0;i<n;i++) cin>>ppl[i];

            for(int i=0;i<n;i++)
            {
                if(ppl[i]<=money)
                {
                    money-=ppl[i];
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
            }
            cout<<endl;
        testcase--;

    }
    return 0;
}