//Token game Iterative method
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

    return true;
}

int main()
{
    int n,m;
    char board[][300]={"WWB","BWW","WWW"};
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    // }
    for(int i=0;i<n;i++)
    {   int token=0;
        int sol[300][300]={0};
        for(int j=0;j<n;j++)
        {   
            for(int k=i;k<m;k++)
            {
                if(CanPlace(board,sol,i,j,n,m))
                {   sol[j][k] = 1;
                    //Token is placed
                    token++;
                    break;
                }
            }
            if(max_token<token) max_token = token;
        }
    }
    return 0;
}