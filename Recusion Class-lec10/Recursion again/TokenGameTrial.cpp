//TokenGame - Epoch HackerEarth
#include<iostream>
using namespace std;

bool CanPlace(char board[][300],int sol[300][300],int i,int j,int n,int m)
{   if(board[i][j]=='B')return false;
    for(int row=0;row<n;row++)
    {
        if(sol[row][j]==1)
            {return false;}
    }
    for(int col=0;col<m;col++)
    {
        if(sol[i][col]==1)
        {
            return false;
        }
    }
    return true;
}

bool TokenGame(char board[][300],int sol[300][300],int i,int n,int m)
{   //Base Case
    if(i==n)
    {   
        //Print the configration
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout<<sol[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
        return false;
    }
    // if(j==m)
    // {
    //     return TokenGame(board,sol,i+1,n,m);
    // }
    // if(board[i][j]=='B')
    // {
    //     return TokenGame(board,sol,i,n,m);
    // }
    for(int j=0;j<m;j++)
    {   if(CanPlace(board,sol,i,j,n,m))
        {   sol[i][j]=1;
            bool chota = TokenGame(board,sol,i+1,n,m);
            if(chota)
            {
                return true;
            }
        }

        // if(j==m)
        // {
        //     return TokenGame()
        // }
        sol[i][j]=0;
    }
    return false;
    // if(CanPlace(board,i,j,n,m))
    // {
    //     board[i][j]='1';
    //     bool chotagrid = TokenGame(board,i+1,j,n,m);
    //     if(chotagrid)
    //     {
    //         return true;
    //     }
    //     else
    //     {
    //         return false;
    //     }
    // }
    // return TokenGame(board,i+1,j,n,m);
}

int main()
{   int n,m;
    char board[][300]={
   "WWW",
"WBB",
"WBB"
    };
    int sol[300][300]={0};
    // cout<<board[1][0];
    TokenGame(board,sol,0,3,3);
    return 0;
}


/*// if(j==m)
    // {
    //     return TokenGame(board,i+1,0,n,m);
    // }
    //Recursive case
    // if(board[i][j]=='B')
    // {
    //     return TokenGame(board,i,j+1,n,m);
    // }
    for(int j=0;j<m;j++)
    {    if (board[i][j]!='B'&&CanPlace(board,i,j,n,m))
        {   board[i][j]='1';
            bool chotagrid = TokenGame(board,i+1,n,m);
            if(chotagrid) return true;
        }

    }
    return TokenGame(board,i+1,n,m);
    // if(j==m)
    // {
    //     TokenGame(board,i+1,0,n,m);
    // }
    // if(board[i][j]=='B')
    // {
    //     return TokenGame(board,i,j+1,n,m);
    // }
    // if (CanPlace(board,i,j,n,m))
    //     { board[i][j]='1';
    //         bool chotagrid = TokenGame(board,i+1,j,n,m);
    //         if(chotagrid) return true;
    //     }
    //     else{
    //        return TokenGame(board,i,j+1,n,m);
    //     }
    // for(int j=0;j<m;j++)
    // {
    //     if(board[i][j]=='B')
    //     {
    //         continue;
    //     }
    //     if(board[i][j]=='W')
    //     {
    //         if (CanPlace(board,i,j,n,m))
    //         { board[i][j]='1';
    //             bool chotagrid = TokenGame(board,i+1,n,m);
    //             if(chotagrid) return true;
    //         }
    //     }
    // }
    // return false;
    // // if (CanPlace(board,i,j,n,m))
    // //     { board[i][j]='1';
    // //         bool chotagrid = TokenGame(board,i+1,j,n,m);
    // //         if(chotagrid) return true;
    // //     }
    // // //If whole loop goes and cannot find a place to place 
    // // //last position placed was wrong
    // // board[i][j] = 'W';
    // // return false;
 */ 
