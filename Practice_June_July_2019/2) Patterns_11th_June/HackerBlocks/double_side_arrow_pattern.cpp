//Pattern Double side arrow -
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int curline=1;curline<=(n+1)/2;curline++)
    {
        // For half -
        // if(curline<=(n+1)/2)
        {   for(int space=1;space<=(n - (2*curline)+1);space++) cout<<"  ";

            // Value printing
            int val = curline;
            for(int nvalue = 1;nvalue<=curline;nvalue++)
            {
                cout<<val<<" "; val--;
            }
            //Middle spaces -
            for(int middle_space=1;middle_space<=(2*(curline-1)-1);middle_space++)
            {
                cout<<"  ";
            }
            for(int nvalue2 = 1;nvalue2<=curline&&curline!=1;nvalue2++)
            {
                cout<<nvalue2<<" ";
            }
        }
        cout<<endl;
    }
    // cout<<val<<endl;
    for(int curline=1;curline<=n/2;curline++)
    {
        for(int space=1;space<=2*curline;space++) cout<<"  ";
            // 
        //Value print
            int val = (n+1)/2 -curline;
        for(int nvalue = 1;nvalue<=((n+1)/2)-curline;nvalue++)
        {
            cout<<val<<" "; val--;
        }
        // Check for middle spacing -
        //Problem is Here
        for(int middle_space=1 ;middle_space<=((n-4) - 2*(curline-1));middle_space++) cout<<"  ";
        
        for(int nvalue2= 1;nvalue2<=((n+1)/2)-curline&&curline!=(n/2);nvalue2++)
        {
            cout<<nvalue2<<" ";
        }
        cout<<endl;
    }

return 0;
}