//N Queen Problem
#include<iostream>
using namespace std;
bool CanPlace(int board[][10],int i,int j,int n)
{
    for(int row=0;row<i;row++)
    {
        if(board[row][j]==1)
        {
            return false;
        }
    }
    int x=i;
    int y=j;
    //Checking for left Diagonal
    //Since We are placing row wise , so no need to check under it
    while(x>=0&&y>=0)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--;
        y--;
    }
    x=i; y=j;
    while(x>=0&&y<n)
    {
        if(board[x][y]==1)
        {
            return false;
        }
        x--; y++;
    }
    return true;
}

bool SolveN_Queen(int board[][10],int i,int n)
{
    //Base Case - 
    if(i==n)
    {
        //Hit the base case
        //Grid khatam ho gaya h
        //Print the Configration of the board
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==1)
                {
                    cout<<" Q ";
                }
                else{ cout<<" _ ";}
            }
            cout<<endl;
        }
        return true;
    }

    //Recursive Case- 
    for(int j=0;j<n;j++)
    {
        //we Cannot keep the queen as it is 
        //Check if it is a valid position or not
        if(CanPlace(board,i,j,n))
        {
            board[i][j] =1;
            bool chhotaboard = SolveN_Queen(board,i+1,n);
            if(chhotaboard)
            {
                return true;
            }
        }
        //Backtracking Step , If the queen placed was wrong
        board[i][j]=0;
    }
    //This return statement is when full for loop is run and not a single valid position is
    //seen by the Q to place
    return false;
    //This goes to previous iteration of loop , and change the previous queen position
    
}
int main()
{
    int n;
    cin>>n;
    int board[][10]={0};
    SolveN_Queen(board,0,n);
    return 0;
}