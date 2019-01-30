//Rat in a maze
#include<iostream>
using namespace std;

bool Mazeclear(char maze[][10],int sol[][10],int i,int j,int n,int m)
{
    //Base Case
    if(i==n&&j==m)
    { sol[n][m]=1;
        //Reached the destination ,Print config
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    // if(j==m){return false;}

//Place the rat 
    sol[i][j]=1;
    if(j+1<=m && maze[i][j+1]!='X')
    {
        //Rat is going right
        bool rightmaze = Mazeclear(maze,sol,i,j+1,n,m);
        if(rightmaze)
        {
            return true;
        }
    }

    if(i+1<=n && maze[i+1][j]!='X')
    {
        bool downmaze = Mazeclear(maze,sol,i+1,j,n,m);
        if(downmaze)
        {
        return true;
        }
    }
//Backtracking step
    sol[i][j]=0;
    return false;
}

int main()
{
    char maze[][10]= {
       "00XXX",
        "00000",
        "0XX00",
        "000X0",
        "0X000"
    };
    int sol[10][10]={0};
    Mazeclear(maze,sol,0,0,4,4);
    return 0;
}
