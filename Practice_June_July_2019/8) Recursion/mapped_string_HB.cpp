//Mapped String 
#include<iostream>
#include<string>
using namespace std;
char strings[] = {' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O',
'P','Q','R','S','T','U','V','W','X','Y','Z'};
void mapped_str(char *str,int i,string s)
{
    //Base Case-
    if(str[i]=='\0')
    {
        cout<<s<<endl;
        return;
    }

    int num;
    num =(int)str[i]-'0';
    string temp =s;
    s+=strings[num];
    mapped_str(str,i+1,s);
    s= temp;
    //How to restore the string back to what it was init
    if(str[i+1]!='\0')
    {
        num = (int)(str[i]-'0')*10 + str[i+1]-'0';
         if(num<27)
        {  s+=strings[num];
        mapped_str(str,i+2,s);
        }
    }


    // for(int j=i;j<i+2&&str[j]!='\0';j++)
    // {  
    //     //create the number -
    //     int num;
    //     if(i!=j)
    //     {    num = (int)(str[i]-'0')*10 + str[j]-'0';}
    //     else num = (int)str[i]-'0';
    //     s+= strings[num];
    //     mapped_str(str,i+1,s);
    // }
}
int main()
{
    char str[10005];
    cin>>str;
    cout<<(int)str[0]-'0'<<endl;
    mapped_str(str,0,"");
    return 0;
}