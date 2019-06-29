//String Compression
#include<iostream>
using namespace std;
void string_compress(char * str)
{   int i=0,j=0;
    while(str[i]!='\0')
    {   int cnt = 0;
        // char val = str[i];
        j=i;
        while(str[j]==str[i])
        {
            cnt++;
            j++;
        }
        cout<<str[i]<<cnt;
        i= i+ cnt;
    }
}
int main()
{

    char str[1005];
    cin>>str;
    string_compress(str);

    return 0;
}