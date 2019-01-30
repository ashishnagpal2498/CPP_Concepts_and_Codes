//Spiral Print 
#include<iostream>
using namespace std;
void generateArr(int arr[][10],int row,int column)
{
    int value=1;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            arr[i][j]=value;
            cout<<arr[i][j]<<"  ";
            value++;
        }
        cout<<"\n";
    }
}
void spiralprint(int arr[][10],int r ,int c)
{
    //take the array 

    int top=0,bottom=r-1,left=0,right=c-1;
    int cnt=0;
    while(top<=bottom && left<=right)
    {
        for(int i=left;i<=right;i++,cnt++)
        {
            cout<<arr[top][i]<<"  ";

        }
        top++;
        for(int i=top;i<=bottom;i++,cnt++)
        {
            cout<<arr[i][right]<<"  ";

        }
        right--;
        if(cnt==r*c)
        {
            break;
        }
        for(int i=right;i>=left;i--,cnt++)
        {
            cout<<arr[bottom][i]<<"  ";
        }
        bottom--;
        if(cnt==r*c)break;
        for(int i=bottom;i>=top;i--,cnt++)
        {
            cout<<arr[i][left]<<"  ";
        }
        left++;
        //lef
    }
}
int main()
{   int r,c;
    cin>>r>>c;
    int arr[10][10];
    generateArr(arr,r,c);
    spiralprint(arr,r,c);
    return 0;
}