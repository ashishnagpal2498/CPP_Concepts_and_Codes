//Token Game
#include<iostream>
using namespace std;
bool CanPlace(char board[][300],int i,int j,int n,int m)
{
    
    for(int row=0;row<n;row++)
        {   if(board[row][j]=='1')
            {
                return false;
            }

        }
        for(int col=0;col<m;col++)
        {
            if(board[i][col]=='1')
            {
                return false;
            }
        }

    return true;
}
bool Tokengame(char board[][300],int i,int n,int m)
{   //Base Case
    if(i==n)
    {
        //Base case aaya h 
        //print configration
         for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return true;
    }

    for(int j=0;j<m;j++)
    {
        if(board[i][j]!='B' &&CanPlace(board,i,j,n,m))
        {
            board[i][j]='1';
            bool smallboard = Tokengame(board,i+1,n,m);
            if(smallboard)
            {
                return true;
            }
        }
        // if(j==m-1&&board[i][j]=='B')
        // {
        //     bool smallboard = Tokengame(board,i+1,n,m);
        //     if(smallboard)
        //     {
        //         return true;
        //     }
        // }
        if(board[i][j]=='1') board[i][j]='W';
    }
    
    return false;

}
int main()
{
     int n,m;
    char board[][300]={"WWW","WBB","WBB"};
    Tokengame(board,0,3,3);
    return 0;
}