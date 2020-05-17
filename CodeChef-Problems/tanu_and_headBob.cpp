//Tanu and head - bob
#include<iostream>
using namespace std;
int main()
{
    int testcase;
    cin>>testcase;
    int n;
    char gesture[1005];
    while(testcase>0)
    {   bool flag = false;
        cin>>n;
        for(int i=0;i<n;i++)cin>>gesture[i];
        for(int i=0;i<n;i++)
        {
            if(gesture[i]=='I')
            {   flag=true;
                cout<<"INDIAN"<<endl;
                break;
            }
            else if(gesture[i]=='Y')
            {   flag=true;
                cout<<"NOT INDIAN"<<endl;
                break;
            }
        }
        if(!flag)
        {
            cout<<"NOT SURE"<<endl;
        }
        testcase--;
    }
    return 0;
}