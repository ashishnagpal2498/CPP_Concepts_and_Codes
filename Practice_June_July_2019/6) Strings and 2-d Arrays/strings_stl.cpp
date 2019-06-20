//Strings
#include<iostream>
#include<string>
using namespace std;
int main()
{   char arr[100];
    string s;
    // cin>>s;
    getline(cin,s);
    cout<<s;
    cin.getline(arr,100);
    cout<<arr;


    return 0;
}