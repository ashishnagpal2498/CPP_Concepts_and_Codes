//N queen Problem Recursion
#include<iostream>
using namespace std;
bool CanPlace(int board[][10],int i,int j,int n)
{
    
    for(int row=i;row>=0;row--)
        {   if(board[row][j]==1)
            {
                return false;
            }

        }
        int x=i;
    int y=j;
    while(x>=0&&y>=0)
    {
        if(board[x][y]==1) return false;

        x--;
        y--;
    }
    x=i;
    y=j;
    while(x>=0&&y<n)
    {
        if(board[x][y]==1) return false;
        x--;
        y++;
    }
    return true;
}
bool Nqueen(int board[][10],int i,int n)
{   //Base case
        if(i==n)
        {
            //Configration print 
            for(int m=0;m<n;m++)
            {
                for(int j=0;j<n;j++)
                   { if(board[m][j]==1)cout<<"Q";
                        else cout<<"_";
                    }
              cout<<endl;             
            }
            cout<<endl;
            // return true;
        }
        //recursive call
    for(int j=0;j<n;j++)
    {   //Check If the position to place the queen is save or not 
        if(CanPlace(board,i,j,n))
        {   board[i][j]=1;
            bool nextQueen = Nqueen(board,i+1,n);
            if(nextQueen)
            {
                return true;
            }
        }
        ///Backtracking
        board[i][j]=0;
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    int board[10][10]={0};
    Nqueen(board,0,n);
    return 0;
}