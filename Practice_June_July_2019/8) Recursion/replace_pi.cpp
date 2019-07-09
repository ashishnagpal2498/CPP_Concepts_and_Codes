//Replace Pi with 3.14
#include <iostream>
#include<string>
using namespace std;
void replace_PI(string str,string &opt,int i)
{
    if(str[i]=='\0')
    {
        return;
    }

    if(str[i]=='p'&&str[i+1]=='i'&&str[i+1]!='\0')
    {
        //append pi
        opt+="3.14";
        i++;
    }
    else
    opt+=str[i];
    replace_PI(str,opt,i+1);

}
int main()
{   int T;
    cin>>T;
    cin.get();
    while(T--)
    {   //cin.get();
        string str;
        string opt = "";
        getline(cin,str);
        replace_PI(str,opt,0);
        cout<<opt<<endl;
    }
    return 0;
}