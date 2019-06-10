//reverse a string 
#include<iostream>
#include<cstring>
using namespace std;
void reversestring(char str1[])
{   int len=strlen(str1);
    int i=0;
    int j= len-1;
    while(i<j)
    {
        swap(str1[i],str1[j]);
        i++; j--;
    }
}
void reverseKcharacters(char str[],int k)
{
    int len = strlen(str);
    cout<<len<<endl<<str[len]<<endl;
    for(int i=len;i>=0;i--)
    {
        str[k+i]=str[i];
    }
    for(int i=0;i<k;i++)
    {
        str[i]=str[len+i];
    }
    str[len]='\0';
    cout<<str;
}
int main()
{   char str[100];
    cin.getline(str,100);
    //reversestring(str);
    //cout<<str;
    int k; cin>>k;
    reverseKcharacters(str,k);
    return 0;
}