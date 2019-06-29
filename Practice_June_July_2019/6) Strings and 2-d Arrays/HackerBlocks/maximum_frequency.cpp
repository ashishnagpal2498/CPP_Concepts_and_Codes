//Maximum frequency
#include<iostream>
#include<cstring>
using namespace std;
char max_freq(char *s)
{   int len = strlen(s);
    int freq[26] ={0};
    for(int i=0;i<len;i++)
    {
        freq[s[i] - 'a']++;
        // cout<<s[i]<<" ";
    }
    int max_val = -10000000;
    char max_char;
    for(int i=0;i<26;i++)
    {
        if(freq[i]>max_val) { 

          max_val = freq[i];
          max_char = 'a' + i;
      }
    }
    return max_char;
}
int main()
{
    char s[1005];
    cin>>s;
    cout<<max_freq(s);
    return 0;
}