//Pattern
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int val;
    for(int curline=1;curline<=n;curline++)
    {   bool flag =false;
        val =curline;
        for(int spaces=1;spaces<=(n-curline);spaces++) cout<<" ";
            for(int nvalues=1;nvalues<=2*curline-1;nvalues++)
            {
                if(nvalues==curline) flag =true;
                if(flag) { cout<<val; val--; }
                else{
                    cout<<val; val++;
                } 
            }
            cout<<endl;
    }
    
    for(int curline=1;curline<n;curline++)
    {  bool flag=false;
        int nvalues = 2*(n-curline) -1;
        for(int spaces=1;spaces<=curline;spaces++) cout<<" ";
            for(;nvalues>0;nvalues--)
            {   
                 
                 if(val==2*(n-curline)-1)
                 {
                    flag=true;
                 }
                 if(flag)
                 {
                    cout<<val--;
                 }
                 else{
                    cout<<val++;
                 }
            }
            cout<<endl;
    }

}