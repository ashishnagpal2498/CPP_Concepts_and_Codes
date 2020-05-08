//Smallest Word Choosen
#include<iostream>
using namespace std;
void iterativeMethod(string s1,string s2,string s3,int l3)
{   string ans=s1+s2+s3;
    for(int i=0;i<(1<<l3);i++)
    {    string x="";
        int j=i;
        int l=0;
        while(j)
        {   int rem = j&1;
            if(rem==1)
            {
                x=x+s2[l];
            }
            l++;
            j= j>>1;
        }
        // cout<<x<<" ";
        string smallAns = s1+x+s3;
        // int ascii_val = int(x);
        if(smallAns<ans)
        {   //cout<<"Here  "<<ascii_val<<" Ans "<<int(x)<<endl;
            ans=smallAns;
        }
    }
    // cout<<"Ans "<<endl;
    cout<<ans<<endl;
}
void findString(string s1,string &s2,string s3,string &finalAns,string output,int i)
{
    if(s2[i]=='\0')
    {   
        string temp = s1+output+s3;
        //cout<<"Here "; cout<<temp<<endl;
        if(temp<finalAns)
        {   
            finalAns= temp;
        }
        return;
    }
    //Include the character-
    findString(s1,s2,s3,finalAns,output+s2[i],i+1);
    //
    findString(s1,s2,s3,finalAns,output,i+1);
}
int main(int argc, char const *argv[])
{
    int l1,l2,l3;
    cin>>l1>>l2>>l3;
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    string finalAns=s1+s2+s3;
    //find x - which is a subsequence of string s2;
    findString(s1,s2,s3,finalAns,"",0);
    cout<<finalAns<<endl;
    iterativeMethod(s1,s2,s3,l3);
    return 0;
}