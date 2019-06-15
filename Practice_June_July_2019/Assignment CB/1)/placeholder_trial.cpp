//Placeholder - Syntax
//Pattern -
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int curline=1;curline<=n;curline++)
    {
        for(int nvalue=1;nvalue<=n;nvalue++)
        {   if(nvalue>=curline) cout<<"*";
        }
        cout<<endl;
    }

    return 0;
}