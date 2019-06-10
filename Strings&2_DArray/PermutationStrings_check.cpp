//Permutation of a string
#include<iostream>
using namespace std;
bool isPermutation(char str1[],char str2[])
{
    int freq[26]={0};
    for(int i=0;str1[i]!='\0';i++)
        freq[str1[i]-'a']++;
    for(int i=0;str2[i]!='\0';i++)
        freq[str2[i]-'a']--;
    //checking for 0s in array
    for(int i=0;i<26;i++)
    {
        if(freq[i]!=0)
        {
            return false;
        }
    }
    return true;
}

int main()
{   char str1[100],str2[100];
cin.getline(str1,100);
cin.getline(str2,100);
    bool permu =  isPermutation(str1,str2);
if(permu) cout<<"yes";
else cout<<"no";
    return 0;
}