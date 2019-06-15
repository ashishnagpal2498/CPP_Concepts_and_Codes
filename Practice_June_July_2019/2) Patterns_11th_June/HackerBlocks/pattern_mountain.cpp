//Pattern Mountain
#include<iostream>
using namespace std;
int main()
{   
    int n;
    cin>>n;
    for(int curline=1;curline<=n;curline++)
    {
        for(int nvalue = 1;nvalue<=n;nvalue++)
        {   if(nvalue<=curline)
            cout<<nvalue<<"\t";
            else cout<<"\t";
        }
        for(int nvalue=n-1;nvalue>=1;nvalue--)
        {
            if(nvalue<=curline)
            {
                cout<<nvalue<<"\t";
            }
            else{
                cout<<"\t";
            }
        }
        cout<<endl;
    }

    return 0;
}