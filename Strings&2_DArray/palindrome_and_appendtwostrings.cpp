//Palindrome of a string and append two strings
#include<iostream>
using namespace std;
int length(char st[])
{   int i=0;
    while(st[i]!='\0')
    {
        i++;
    }
    return i;
}
bool Palindrome(char str[])
{ int len=length(str);
    cout<<len;
    int i=0;
    int j=len-1;
    bool ispalindrome=true;
    while(i<j)
    { if(str[i]!=str[j]){
        ispalindrome=false;
        break;
    }
    i++; j--;

    }
    return ispalindrome;
}
void append(char str1[],char str2[])
{
    int i=0;
    while(str2[i]!='\0')
    {
        i++;
    }
    int j=0;
    while(str1[j]!='\0')
    {
        str2[i]=str1[j];
        i++;
        j++;
    }
    str2[i]='\0'; //insertion of null character at end;
}
int main()
{
    char str[100];
   //  cin.getline(str,20);
   // bool palin= Palindrome(str);
   // cout<<palin;
   //append two strings;
   char str1[100], str2[100];
   cin.getline(str1,20);
   cin.getline(str2,20);
   cout<<"String 1: "<<str1<<"\nString 2: "<<str2;
   append(str1,str2);
   cout<<"\n Appended string :"<<str2;
    return 0;
}