#include<iostream>
using namespace std;
bool CanPlace(char board[][100],int i,int j,int n,int m)
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
int count=0;
bool Ratwin_or_lose(char maze[100][100],int i,int j,int m,int n)
{
    if(i==m&&j==n)
    {
        //Way found 
        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         cout<<sol[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        cout<<count;
        return true;
    }
    //Assuming ki meine i,j par place kar diya hai
    maze[i][j]='1';
    if(j<n&& maze[i][j+1]!='W'&&CanPlace(maze,i,j,n,m))
    {   count++;
        bool rightpath = Ratwin_or_lose(maze,i,j+1,m,n);
        if(rightpath)
        {
            return true;
        }
    }
    if(i<m&&maze[i+1][j]!='X')
    {   count++;
        bool downpath = Ratwin_or_lose(maze,i+1,j,m,n);
        if(downpath)
        { 
            return true;
        }
    }
   
    count--;
    return false;
}

int main()
{
     int n , m;
    char board[100][100];
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>board[i][j];
        }
    }
    Ratwin_or_lose(board,0,0,n,m);
    // for(int i=0;i<m;i++)
    // {
    //     for(int j=0;j<n;j++)
    //         cin>>maze[i][j];
    // }
    // Ratwin_or_lose(maze,sol,0,0,m,n);

    return 0;
}