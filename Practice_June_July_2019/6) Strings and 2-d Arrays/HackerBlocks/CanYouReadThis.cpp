//Camel Case Print - words
#include<iostream>
using namespace std;
int main()
{
    char str[10005];
    cin>>str;
    int i=0;
    while(str[i]!='\0')
    {
        if(str[i]>='A'&&str[i]<='Z')
        {
            //New word begining
            if(i!=0)
            {
                cout<<endl;
            }
            
        }
        cout<<str[i];
        i++;
    }

    return 0;
}