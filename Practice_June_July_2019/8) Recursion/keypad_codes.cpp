//Keypad Recursion
#include<iostream>
#include<string>
using namespace std;
string table[] = {" ","abc", "def", "ghi", "jkl" , "mno",
 "pqrs" , "tuv", "wx","yz" };
int keypadStrings(char*str,int i,string opt)
{
    if(str[i]=='\0')
    {
        cout<<opt<<" ";
        return 1;
    }
    int num = (int)(str[i]-'0');
    int ans =0;
    for(int j=0;j<table[num].length();j++)
    {   string temp =opt;
        opt+=table[num][j];
       ans+=keypadStrings(str,i+1,opt);
        //Restore the string - backtrack-
        opt = temp;
    }
    return ans;
} 
int main()
{
    char arr[11];
    cin>>arr;
    cout<<endl<<keypadStrings(arr,0,"");
    return 0;
}