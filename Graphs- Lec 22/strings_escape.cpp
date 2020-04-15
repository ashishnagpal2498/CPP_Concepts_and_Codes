#include<iostream>
using namespace std;
int main()
{
    string s = "a\nu";
    int i=0;
    while(s[i]!='\0')
    {
        if(s[i]=='\n'){cout<<"HEY"<<endl;}
        cout<<s[i];
        i++;
    }
    return 0;
}