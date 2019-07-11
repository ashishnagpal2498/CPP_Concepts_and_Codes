//Keypad Recursion
#include<iostream>
#include<string>
using namespace std;
string table[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno",
 "pqrs" , "tuv", "wxyz" };
void keypadStrings(char*str,int i,string opt)
{
    if(str[i]=='\0')
    {
        cout<<opt<<endl;
        return;
    }
    int num = (int)(str[i]-'0');
    for(int j=0;j<table[num].length();j++)
    {   string temp =opt;
        opt+=table[num][j];
        keypadStrings(str,i+1,opt);
        //Restore the string - backtrack-
        opt = temp;
    }
} 
int main()
{
    char arr[11];
    cin>>arr;
    keypadStrings(arr,0,"");
    return 0;
}