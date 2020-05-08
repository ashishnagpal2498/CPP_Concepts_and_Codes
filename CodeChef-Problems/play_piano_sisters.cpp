//Play Piano
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cin.get();
    while(n--)
    { string str;
    cin>>str;
    int i=0;
    int day = 0;
    bool A_played = false;
    bool B_played = false;
    bool flag = true;
    while(str[i]!='\0')
    {   day++;
        if(str[i]=='A')
        {
            if(!A_played)
            {
                A_played = true;
            }
            else
            {
                flag = false;
                break;
            }
        }
        else{
            if(!B_played)
            {
                B_played = true;
            }
            else{
                flag = false;
                break;
            }
        }
        if(day==2)
        {
            day =0;
            A_played = false;
            B_played = false;
        }
        i++;
    }

    if(flag) {cout<<"yes"<<endl;}
    else{cout<<"no"<<endl;}
    }
    return 0;
}