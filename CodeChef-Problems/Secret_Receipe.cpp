//Chef and kefa Race
#include<iostream>
using namespace std;
int main()
{
    int testcase;
    cin>>testcase;
    while(testcase>0)
    {
        int x1,x2,x3,V1,V2;
        cin>>x1>>x2>>x3>>V1>>V2;
        int disX1 = x3 - x1;
        int disX2 = x2-x3;
        if(disX1<disX2)
        {
            cout<<"Chef"<<endl;
        }
        else if(disX1==disX2)
        {
            if(V1>V2){
                cout<<"Chef"<<endl;
            }
            else if (V1== V2)
            {
                cout<<"Draw"<<endl;
            }
            else{
                cout<<"Kefa"<<endl;
            }
        }
        else
        {
            cout<<"Kefa"<<endl;
        }
        testcase--;
    }
    return 0;
}