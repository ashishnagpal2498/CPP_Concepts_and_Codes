//LunchBox - CodeChef
//NightsWatch
#include<iostream>
#include<cstring>
using namespace std;
int nights_watch_ppl(string s,int i,int len)
{    int count = 0;
    if(s[i]=='\0'||i>=len)
    {
        return count;
    }
    if(s[i]!='1'&&s[i+1]!='1')
    {   
        s[i] = '1';
        count++;
      
    }
    int smallans = nights_watch_ppl(s,i+2,len);
    return smallans+count;
}
int main()
{   int testcase;
    cin>>testcase;
    int len;
    string str;
    while(testcase--)
    {
    cin>>len;
    
    cin.get();
    cin>>str;
        cout<<nights_watch_ppl(str,0,len)<<endl;
    
    }
    return 0;
}