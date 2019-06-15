//Manmohan Loves pattern 2
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int curline=1;curline<=n;curline++)
    {
        for(int nvalue =1;nvalue<=curline;nvalue++)
        {
            if(curline<3)
            {
                cout<<1;
            }
            else if(nvalue>1&&nvalue<curline) cout<<0;
            else cout<<curline-1;
        }
        cout<<endl;
    }
    return 0;
}