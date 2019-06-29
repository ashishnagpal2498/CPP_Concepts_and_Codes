//Strings -
#include<iostream>
using namespace std;
char character_Type(char a)
{
     if(a>='a'&&a<='z')
    {
        return 'L';
    }
    else if(a>='A'&&a<='Z') {return 'U';}
    else
    {
        return 'I';
    }
}
int main()
{
    char a;
    cin>>a;
   cout<<character_Type(a)<<endl;

    return 0;
}