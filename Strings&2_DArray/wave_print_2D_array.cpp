//2-D Array Wave Print
// 1 2 3 4 
// 5 6 7 8
// 9 10 11 12
// OutPut - 1 5 9 10 6 2 3 7 11 12 8 4
#include<iostream>
using namespace std;
int main()
{   int a=76;
    a=a>>3; //shift right
    int msb = 3&1;
    
    cout<<a;  cout<<endl<<msb<<endl;
msb=3>>1;
    cout<<msb<<endl;
    int arr[][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    for(int curcol=0;curcol<4;curcol++)
    {
        
        if(curcol%2==0)
        {
            for(int j=0;j<3;j++)
            {
                cout<<arr[j][curcol]<<"  ";
            }
        }
        else{
            for(int j=2;j>=0;j--)
            {
                cout<<arr[j][curcol]<<"  ";
            }
        }
    }
    return 0;

}