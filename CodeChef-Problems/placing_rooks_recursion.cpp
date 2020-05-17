//Place rooks - Recursion
#include<iostream>
using namespace std;
bool Canplace(char board[][1002],int n,int r,int c)
{   //cout<<"inside Canplace";
    for(int i=1;i<=n;i++)
    {   
        if(board[i][c]!='\0'||board[r][i]!='\0')
        {
            return false;
        }
    }
    return true;
}

bool n_rooks(char board[][1002],int n,int i,int p)
{
    //base case -
    if(i>n)
    {
        //reached the limit of board;
        //print the board;
        cout<<p<<" ";
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
               if(board[i][j]=='M')
               {
                cout<<i<<" "<<j<<" ";
               }
            }
            //cout<<endl;
        }
        cout<<endl;
        return true;
    }
    for(int j=1;j<=n;j++)
    {   char initialval = board[i][j];
        if(Canplace(board,n,i,j))
        { p++;
            board[i][j] = 'M';
            bool smallboard = n_rooks(board,n,i+1,p);
            if(smallboard)
            {
                return true;
            }
            else
            {
                p--;
            }
        }
        else if(board[i][j]=='A'){
           
            n_rooks(board,n,i+1,p);
        }
        //Backtracking
        //p--;
        board[i][j] = initialval;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int testcase;
    cin>>testcase;
    while(testcase--)
    {char board[1002][1002]={'0'};
    int n;
    cin>>n;
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {   int r,c;
        cin>>r>>c;
        board[r][c] = 'A'; //arya placed
    }

    // for(int i=1;i<=n;i++)
    //     {
    //         for(int j=1;j<=n;j++)
    //         {
    //             cout<<board[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
        n_rooks(board,n,1,0);
//    cout<<board[3][4]<<endl<<board[4][2];
    }
    return 0;
}