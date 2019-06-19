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
bool isPermutation(char *str1,char *str2)
{
    int freq[26] = {0};
    int i=0;
    while(str1[i]!='\0'&&str2[i]!='\0')
    {
        freq[str1[i] - 'a']++; freq[str2[i] - 'a']--;
        i++;
    }
    for(int i=0;i<26;i++)
    {
        if(freq[i]!=0)
        {
            return false;
        }
    }
    return true;
}
bool isAnagram(int *T,int * P)
{
    for(int i=0;i<256;i++)
    {
        if(T[i]!=P[i]) return false;
    }
    return true;
}
void string_matching(char *str,char * pattern)
{
    int n = length(str);
    int m = length(pattern);
    //Frequency Array and precompute till m
    int T[256] = {0};
    int P[256] = {0};
    for(int i=0;i<m;i++)
    {
        T[str[i]] ++;
        P[pattern[i]]++;
    }
    for(int i=m;i<=n;i++)
    {
        if(isAnagram(T,P))
        {
            cout<<(i-m)<<endl;
            //break; 
            return;
        }
        T[str[i-m]]--;
        T[str[i]]++;
    }
    cout<<-1;
}
void print_substrings(char *str)
{
    for(int i=0;str[i]!='\0';i++)
    {
        for(int j=i;str[j]!='\0';j++)
        {
            for(int k=i;k<=j;k++)
            {
                cout<<str[k];
            }
            cout<<endl;
        }
    }
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
        cout<<setw(50)<<"4. Permutation\n";
        cout<<setw(50)<<"5. String Matching + Anagram\n";
        cout<<setw(50)<<"6. Substrings of a String\n";
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
         case 4 : cin>>str;
                    char str2[10005];
                    cin>>str2;
                    cout<<isPermutation(str,str2);
                    break;          
         case 5 : cin>>str;
                    char pattern[10005];
                    cin>>pattern;
                    string_matching(str,pattern);
                    break;           
         case 6 : cin>>str;
                    print_substrings(str);
                    break;           
         default : cout<<"Invalid Input";                       
     }  
return 0;
}
