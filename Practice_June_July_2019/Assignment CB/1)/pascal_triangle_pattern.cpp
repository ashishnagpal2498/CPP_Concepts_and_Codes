//Pascal Triangle 
#include<iostream>
using namespace std;
int main()
{   
    int n;
    int arr[105][105];
    cin>>n;
    int i=0,j=0; 
    for(int curline=1;curline<=n;curline++)
    {  j=0;
        for(int nvalue=1;nvalue<=curline;nvalue++)
        {  
            if(nvalue==1||nvalue==curline)
            {
                cout<<1<<"\t";
                arr[i][j++] = 1;
            }
            else
            {   arr[i][j] = arr[i-1][j-1]+arr[i-1][j];
                cout<<arr[i][j]<<"\t";
                j++;
            }
        }
        cout<<endl;
        i++;
    }
    return 0;
}