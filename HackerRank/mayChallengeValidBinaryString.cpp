// Maximum length -
#include<iostream>
using namespace std;
int checkString(string s,int start,int end)
{   int lastIndex = -1;
    while(start<=end)
    {   //cout<<s[start]<<endl;
        if(s[start] == '1') lastIndex = start;
        start++;
    }
    return lastIndex;
}
int main()
{
    string s;
    cin>>s;
    int d;
    cin>>d;
    int i=0,j=d-1,n = s.size();
    int count=0;
    while(i<n&&j<n)
    {
        if((j+1-i)==d)
        {
            // got the size -
            // check -
            int index = checkString(s,i,j); 
            if(index == -1)
            {   //cout<<"i "<<i<<"j "<<j<<" index "<<index;
                // put 1 on j and increment to window size  
                j+=d;
                i+=d;
                count++;
            }
            else{
                j+=(index-i);
                i=index+1;
            }
        }
        else{
            j++;
        }
    }
    cout<<count<<endl;
    return 0;
}