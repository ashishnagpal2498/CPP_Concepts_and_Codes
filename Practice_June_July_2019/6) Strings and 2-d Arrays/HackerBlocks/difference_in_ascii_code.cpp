//difference in Ascii Codes 
#include<iostream>
using namespace std;
int main()
{   char str[10005];
    cin>>str;
    char temp[10005];
    int i=0,j=0;
    while(str[i]!='\0')
    {
        //copy the character 
        if(i>0)
        {
            cout<<str[i]-str[i-1];
        }
        cout<<str[i];
        
        i++;
    }
    // temp[j]='\0';
    // cout<<temp;
    return 0;
}