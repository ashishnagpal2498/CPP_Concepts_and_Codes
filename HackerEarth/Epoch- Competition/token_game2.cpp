#include<iostream>
using namespace std;
bool CanPlace(char board[][10],int i,int j,int n,int m)
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
    //     int x=i;
    // int y=j;
    // while(x>=0&&y>=0)
    // {
    //     if(board[x][y]==1) return false;

    //     x--;
    //     y--;
    // }
    // x=i;
    // y=j;
    // while(x>=0&&y<n)
    // {
    //     if(board[x][y]==1) return false;
    //     x--;
    //     y++;
    // }

    return true;
}
bool Nqueen(char board[][10],int i,int n,int m,int &count)
{   //Base case
        if(i==n)
        {
            //Configration print 
            // for(int m=0;m<n;m++)
            // {
            //     for(int j=0;j<n;j++)
            //        { if(board[m][j]==1)cout<<"Q";
            //             else cout<<"_";
            //         }
            //   cout<<endl;             
            // }
            // cout<<endl;
            cout<<count;
            return true;
            // return true;
        }
        //recursive call
    for(int j=0;j<m;j++)
    {   //Check If the position to place the queen is save or not 
        if(CanPlace(board,i,j,n,m))
        {   board[i][j]='1';
            bool nexttoken = Nqueen(board,i+1,n,m,count);
            if(nextQueen)
            {
                return true;
            }
        }
        ///Backtracking
        board[i][j]='';
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