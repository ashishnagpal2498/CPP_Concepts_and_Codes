//Try , Token Game 
#include<iostream>
using namespace std;
bool CanPlace(int sol[305][305],int i,int j,int n,int m)
{   
    
    for(int row=0;row<n;row++)
        {   if(sol[row][j]==1)
            {
                return false;
            }

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

bool tokenGame(char board[][305],int sol[305][305],int i,int moves,int n,int m,int count)
{   
    //Base Case when reach end of board
    if(i==n||moves==n)
    // {   int count=0;
    //     //Here , Count the no. of iterations and find max out of it
    //     for(int a=0;a<n;a++)
    //         {for(int l=0;l<m;l++)
    //             {if(sol[a][l]==1)count++;}
    //             }
    {
                cout<<count<<endl;
    return true;
    }

    //Recursive Case
    int jval= 0;
    for(int j=0;j<m;j++)
    {
        //Check if it is a blackspot or not
        //And Also If we can place the Token Or Not
        if(board[i][j]!='B'&&CanPlace(sol,i,j,n,m))
        {
            sol[i][j]= 1;
            moves=moves+1;
            count++;
            bool nextboard = tokenGame(board,sol,i+1,moves,n,m,count);
            if(nextboard)
            {
                return true;
            }
        }

         if(board[i][j]=='B'){jval++;}
        sol[i][j]=0;
    }
    //What if Uss Row mein placement hai hi nahi then what
    //This case arises , when all the plac
    if(jval==m)
    {
    // { bool flag= false;
    //     for(int a=0;a<m;a++)
    //     {   if(board[i][a]=='B')
    //         {
    //         //no position to be placed at that row
    //         }
    //         else{
    //             flag=true;
    //             break;
    //         }
    //     }
    //     if(flag==true)
    //     {

    //     }
    //     else{
            return tokenGame(board,sol,i+1,moves,n,m,count);
        
    }
    return false;
}
int main()
{   int testcase;
    cin>>testcase;

    
    int n=3,m=3;
    while(testcase>0)
    { char arr[][305] ={""};
    int sol[305][305]={0};
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)cin>>arr[i][j];
    }
    tokenGame(arr,sol,0,0,n,m,0);
    
    testcase--;
    }
    return 0;
}