#include<iostream>
#include<string>
using namespace std;
void all_Xs(char*str,string s,int i,int count)
{
    if(str[i]=='\0')
    {
        //reached at the end of string
        for(int i=0;i<count;i++)
            s+='x';
        cout<<s<<endl;
        return;
    }
    if(str[i]=='x')
    {
        count++;
        all_Xs(str,s,i+1,count);
    }
    else
    {
        s+=str[i];
        all_Xs(str,s,i+1,count);
    }
}
int main()
{
    char str[100005];
    cin>>str;
    all_Xs(str,"",0,0);
    return 0;
}