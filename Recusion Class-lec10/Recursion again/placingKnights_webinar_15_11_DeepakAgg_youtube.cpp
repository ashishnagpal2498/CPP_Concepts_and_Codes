//Placing n*n Knights in chess Board;
#include<iostream>
using namespace std;

bool CanPlace(int board[8][8],int n,int newrow,int newcol)
{
    if(board[newrow][newcol]!=0||newcol>=n||newrow>=n||newrow<0||newcol<0)
    {
        return false;
    }
    return true;
}

bool SolveKnights(int board[8][8],int n,int moves,int i,int j)
{

    //Base case 
    //When no. of moves = n*n tab print config
    if(moves == n*n)
    {
        //Whole board is completeted
        //Print the board;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }

    static int rowDir[] = {+2, +1, -1, -2, -2, -1, +1, +2};
    static int colDir[] = {+1, +2, +2, +1, -1, -2, -2, -1};
    // int RowDir[]={-2,-2,-1,+1,+2,+2,+1,-1}; //This goes anti-clockwise 
    // int ColDir[]={+1,-1,-2,-2,-1,+1,+2,+2}; //Same

    for(int Curpos=0;Curpos<8;Curpos++)
    {
        int nextRow = i + rowDir[Curpos];
        int nextCol = j + colDir[Curpos];

        if(CanPlace(board,n,nextRow,nextCol))
        {
            //Knight can be placed at the position
            board[nextRow][nextCol] = moves +1 ;
           //Moves gives the Current moved Done
            
            bool smallBoard = SolveKnights(board,n,moves +1,nextRow,nextCol);
            if(smallBoard)
            {
                return true;
            }
            else
            {
            board[nextRow][nextCol] = 0;
             }
             

        } 

        //For loop will check for each and every position 
    }
    //If the iteration comes out of for loop , That means we cannot place the knight 
    //according to previous position
    //Backtracking
    // moves = moves -1;
   
    return false;
}

int main()
{
    int n;
    cin>>n;
    int board[8][8]={0};
    board[0][0] = 1;
    SolveKnights(board,n,1,0,0);
    return 0;
}