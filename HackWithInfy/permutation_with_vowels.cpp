//permuations
#include<iostream>
#include<string>
using namespace std;
// string create_Str(string str,int i,int j)
// {   

    // return temp;
// }
int main()
{   char arr[] = {'a','e','i','o','u'};
    string str ="";
    // string = "aeiou";
    int n;
    cin>>n;
    int i;
    for( i=0;i<n;i++)
    {
        str[i] = arr[i%5];
        // cout<<str[i];
    }
    str[i] ='\0';
    //cout<<str;
    for(int i=0;i<n;i++)
    {
        cout<<str[i];
    }
    return 0;
}