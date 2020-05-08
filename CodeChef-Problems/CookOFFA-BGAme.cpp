//A-B Game
#include<iostream>
#include<string>
using namespace std;
int Canplace(char str[100005],int moveplace,int curpostion)
{   int val=-1;
    if(moveplace&1)
    {   //Odd move right
        
        for(int i=curpostion+1;str[i]!='\0'||str[i]!='A'||str[i]!='B';i++)
        {
            if(str[i]=='.')
            {
                //place exist
                val=i;
            }
            else
            {
                break;
            }
        }
        if(val!=-1)
        {
            str[val]=str[curpostion];
            str[curpostion]='.';
        }
    }
    else
    {
        
        for(int i=curpostion-1;str[i]!='A'||str[i]!='B';i--)
        {
            if(str[i]=='.')
            {
                val=i;
            }
            else
            {
                break;
            }
        }
        if(val!=-1)
        {
            str[val]=str[curpostion];
            str[curpostion]='.';
        }
    }
    return val;
}
int main()
{   int testcase;
    cin>>testcase;
    while(testcase>0)
    {
    char str[100005]="";
    cin>>str;
    int Achar=1,Bchar=1;
    for(int i=0;str[i]!='\0';)
    {
        if(str[i]=='A')
        {   //cout<<"A entered  "<<i;
            int index = Canplace(str,Achar,i);
                if(index==-1)
                {
                    cout<<"B"<<endl;
                    break;
                }
                else{
                    Achar++;
                    i=index+1;
                }
               // cout<<"  "<<index<<endl;
            
        }
        else if(str[i]=='B')
        {   //cout<<"B  entered "<<i;
           int index = Canplace(str,Bchar,i);
                if(index==-1)
                {
                    cout<<"A"<<endl;
                    break;
                }
                else{
                    Bchar++;
                    i=index+1;
                }
               // cout<<"  "<<index<<endl;
        }
        else{
            i++;
        }
    }
    testcase--;
}
    return 0;
}