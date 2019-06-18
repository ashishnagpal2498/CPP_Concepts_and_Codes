//Character Array Concepts and Questions MEnu
#include<iostream>
#include<iomanip>
using namespace std;
int length(char *str)
{   int i=0,count=0;
    while(str[i++]!='\0')
    {
        count++;
    }
    return count;
}
bool isPalindrome(char *str)
{
    int i=0 , j = length(str) -1;
    while(i<=j)
    {
        if(str[i++]!=str[j--]) return false;
    }
    return true;
}
void revrse_by_k(char *str,int k)
{   int len = length(str);
    int kshift = len-k;
    char str1[10005];
    int i=0;
    int j= len-k-1;
    while(str[j]!='\0')
    {
        str1[i] = str[j];
        i++;
        j++;
    }
    int m=0;
    // i = len -k;
    while(str[m]!='\0')
    {
        str1[i++] = str[m++];
    }
    str1[len+1] = '\0';
    cout<<str1;
}
int main()
{
    int option;
    char str[10005];
    cout<<setw(50)<<"$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
     cout<<setw(50)<<"$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
     cout<<setw(50)<<"$$$$$$$$ STRING MENU $$$$$"<<endl;
      cout<<setw(50)<<"$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
       cout<<setw(50)<<"$$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl;
       cout<<setw(50)<<"1. Length of string\n";
       cout<<setw(50)<<"2. Check Palindrome\n";
        cout<<setw(50)<<"3. Reverse by K Character \n";
     cin>>option;
     cin.get();
     switch(option)
     {
        case 1 : cin>>str;
                 cout<<length(str);
                 break;
        case 2 : cin>>str;
                 cout<<isPalindrome(str);
                 break;
         case 3 : cin.getline(str,100);
                    int k;
                    cin>>k;
                   revrse_by_k(str,k);
                   break;         
         default : cout<<"Invalid Input";                       
     }  
return 0;
}
