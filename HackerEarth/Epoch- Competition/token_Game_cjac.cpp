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
bool tokenGame(char board[][100],int i,int j ,int n,int m)
{
    if(i==n)
    {
        cout<<count;
        count=0;
        return false;
    }
    if(j==m)
    {   i++;
        j=0;
        return tokenGame(board,i,j,n,m);
    }
    if(board[i][j]=='B'||!CanPlace(board,i,j,n,m))
    {   cout<<"Inside B if"<<endl;
        return tokenGame(board,i,j+1,n,m);
    }
    
    if(board[i][j]=='W')
    {   if(CanPlace(board,i,j,n,m))
        {   cout<<"indise W"<<endl;
            board[i][j]='1';
            ++count; 
       
            bool chotaboard = tokenGame(board,i+1,j,n,m);
         if(chotaboard){
                return true;
        }
    
        }
    }
    //backtrack
    board[i][j]='W';
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
    tokenGame(board,0,0,n,m);
    return 0;
}