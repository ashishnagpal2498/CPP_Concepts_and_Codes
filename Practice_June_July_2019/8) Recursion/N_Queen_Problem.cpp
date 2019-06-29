//N-queen Problem - Backtracking -
#include<iostream>
using namespace std;
bool CanPlace(int board[10][10],int i,int j,int n)
{
    for(int col=i;col>=0;col--)
    {
        if(board[col][j]==1)
        {
            return false;
        }
    }
    // Diagonals ;
    int x = i ,y = j;
    // Left diagonal
    while(x>=0&&y>=0)
    {
        if(board[x][y]==1) return false;
        x--; y--;
    }
    x = i ; y =j;
    //Right Diagonal
    while(x>=0&&y<n)
    {
        if(board[x][y]==1) return false;
        x--; y++;
    }

    return true;
}
bool N_queen(int board[10][10],int i,int n)
{
    if(i==n)
    {
        ///Board print
        for(int a=0;a<n;a++)
        {
            for(int b=0;b<n;b++)
            {   if(board[a][b]==1)
                {cout<<"Q"<<"  ";}
                else {cout<<"-"<<"  ";}
            }
            cout<<endl;
        }
        return true;
    }
    for(int j=0;j<n;j++)
    {
        //Check if the position is safe to place -
        if(CanPlace(board,i,j,n))
        {
            board[i][j] = 1;
            bool smallboard = N_queen(board,i+1,n);
            if(smallboard)
            {
                return true;
            }
        }
        //If I tried all the positions and is not able to place , then 
        //Previous Queen - Galat
        board[i][j] = 0;
    }
    return false;
}
int main()
{   int n;
    cin>>n;
    int board[10][10] ={0};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<board[i][j]<<"  ";
        }
        cout<<endl;
    }
    N_queen(board,0,n);

    return 0;
}