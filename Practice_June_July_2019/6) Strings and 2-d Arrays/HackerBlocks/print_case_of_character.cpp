//Strings -
#include<iostream>
using namespace std;
int main()
{
    char a;
    cin>>a;
    if(a>='a'&&a<='z')
    {
        cout<<"lowercase"<<endl;
    }
    else if(a>='A'&&a<='Z') {cout<<"UPPERCASE"<<endl;}
    else
    {
        cout<<"Invalid"<<endl;
    }

    return 0;
}