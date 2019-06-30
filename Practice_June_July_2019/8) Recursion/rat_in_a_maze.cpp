//Rat in a Maze
#include<iostream>
using namespace std;

bool findPath(char maze[10][10],int sol[10][10],int i,int j,int m,int n)
{
    // Base case -
    if(i==m&&j==n)
    {   sol[m][n]=1;
        //Print the path
        for(int a=0;a<=m;a++)
        {
            for(int b=0;b<=n;b++)
            {
                cout<<sol[a][b]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    //assume that the position path exist
    sol[i][j]=1;
    if(maze[i][j+1]!='X'&&j+1<=n)
    {
        //path exist
        bool rightAns = findPath(maze,sol,i,j+1,m,n);
        if(rightAns)
        {
            return true;
        }
    }
    if(maze[i+1][j]!='X'&&i+1<=m)
    {
        bool downAns = findPath(maze,sol,i+1,j,m,n);
        if(downAns)
        {
            return downAns;
        }
    }
    //Backtrack
    sol[i][j]=0;
    return false;
}
int main()
{
    char maze[10][10] = {
        "OOXXX",
        "OOOOO",
        "OXXOO",
        "OOOXO",
        "OXOOO"
    };
    int sol[10][10] ={0};
    findPath(maze,sol,0,0,4,4);

    return 0;
}