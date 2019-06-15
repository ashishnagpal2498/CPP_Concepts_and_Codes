//Pattern Triangle
#include<iostream>
using namespace std;
int main()
{

    int n;
    cin>>n;
    for(int curline=1;curline<=n;curline++)
    {   bool flag = false;
        int val = curline;
        //Print Spaces -
        for(int space=1;space<=(n-curline);space++) cout<<"\t";
        for(int nvalue=1;nvalue<=(2*curline)-1;nvalue++)
        {
            if(!flag)
            {
                cout<<val<<"\t";
                val++;
            }
            else{
                --val;
                cout<<val<<"\t";
                
            }
            if(nvalue==((curline)))
            {   --val;
                flag = true;
            }
        }
        cout<<endl;
    }

    return 0;
}