//Manmohan Loves Patterns
#include<iostream>
using namespace std;
int main()
{   
    int n;
    cin>>n;
    for(int curline=1;curline<=n;curline++)
    {
        for(int nvalues=1;nvalues<=curline;nvalues++)
        {
            if(curline>=(n/2)&&(curline%2==0)&&nvalues>1&&nvalues<curline)
            {
                cout<<"0";
            }
            else
            {
                cout<<1;
            }
        }
        cout<<endl;
    }

    return 0;
}