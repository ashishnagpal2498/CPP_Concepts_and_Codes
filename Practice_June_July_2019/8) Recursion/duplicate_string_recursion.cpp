//Duplicate String Recursion
#include<iostream>
#include<string>
using namespace std;
void duplicate_Str(string str,int i,string &opt)
{
    if(str[i]=='\0')
    {
        return;
    }
    opt += str[i];
    if(str[i]==str[i+1])
    {
        opt +='*';
    }
    i++;
    duplicate_Str(str,i,opt);
    return;
}
int main()
{
    string str,opt="";
    cin>>str;
    int i=0;
    duplicate_Str(str,i,opt);
    cout<<opt;
    return 0;
}
