//Rotate an array by 90 deg
#include<iostream>
using namespace std;
void generatearray(int arr[][10],int r,int c)
{   int val=1;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            arr[i][j]=val;
            val++;
        }
    }
}
void transpose(int arr[][10],int r,int c)
{
    int top=0,left=0,right=c-1,bottom=r-1;
    while(top<bottom && left<right)
    {
        for(int i=left;i<=right;i++)
            { swap(arr[top][i],arr[i][top]);}
        top++;
        left++;
        for(int i=right;i>=left;i++)
        {
            swap(arr[i][bottom],arr[bottom][i]);
        }
        bottom++; right++;

    }

}
void rotateby90(int arr[][10],int r,int c)
{
    //transpose the matrix
    transpose(arr,r,c);
    for(int i=0;i<r;i++)
        {for(int j=0;j<c;j++) cout<<arr[i][j]<<"  ";}
}

int main()
{
    int arr[10][10]; 
    int r,c;
    cin>>r>>c;
    generatearray(arr,r,c);
    rotateby90(arr,r,c);
    return 0;
}