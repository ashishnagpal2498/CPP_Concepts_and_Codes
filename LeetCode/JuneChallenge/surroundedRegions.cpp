// Board - game 
#include<iostream>
#include<vector>
using namespace std;
bool isValid(vector<vector<char> > board,int i,int j,int n,int m)
{   char val = 'X';
    bool flag1 = board[i-1][j] == val || (i-1!=0);
    bool flag2 = board[i][j+1] == val || (j+1!=m-1); 
    bool flag3 = board[i+1][j] == val || (i+1!=n-1);
    bool flag4 = board[i][j-1] == val || (j-1!=0);
    bool flag5 = board[i-1][j-1] == val || ((i!=0 && j-1!=0) || ((board[i][j-1] != 'O') && (board[i-1][j] != 'O')));
    bool flag6 = board[i-1][j+1] == val || ((i!=0 && j+1!= m-1) || ((board[i][j+1] != 'O')&& (board[i-1][j] != 'O')));
    bool flag7 = board[i+1][j-1] ==  val || ((i!=n-1 && j-1!= 0) || ((board[i][j-1] != 'O')&& (board[i+1][j] != 'O')));
    bool flag8 = board[i+1][j+1] == val || ((i!=n-1 && j+1!=m-1) || ((board[i][j+1] != 'O')&& (board[i+1][j] != 'O')));
    return (flag1 && flag2 && flag3 && flag4 && flag5 && flag6 && flag7 && flag8);
}
void solve(vector<vector<char> > & board)
{   int n = board.size();
    for(int i=1;i<n-1;i++)
    {
        for(int j=1;j<board[i].size()-1;j++)
        {
            if(board[i][j] == 'O' && isValid(board,i,j,n,board[i].size()))
            {
                board[i][j] = 'X';
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<board[i].size();j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    char c;
    cin>>n;
    vector<vector<char> > board(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {   cin>>c;
            board[i].push_back(c);
        }
    }
    solve(board);
    return 0;
}