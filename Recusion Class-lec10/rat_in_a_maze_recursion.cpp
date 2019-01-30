//Rat in a maze
#include<iostream>
using namespace std;

bool Ratwin_or_lose(char maze[5][4],int sol[5][4],int i,int j,int m,int n)
{
    if(i==m&&j==n)
    {
        //Way found 
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    //Assuming ki meine i,j par place kar diya hai
    sol[i][j] = 1;
    if(j<n&& maze[i][j+1]!='X')
    {
        bool rightpath = Ratwin_or_lose(maze,sol,i,j+1,m,n);
        if(rightpath)
        {
            return true;
        }
    }
    if(i<m&&maze[i+1][j]!='X')
    {
        bool downpath = Ratwin_or_lose(maze,sol,i+1,j,m,n);
        if(downpath)
        {
            return true;
        }
    }
    // BackTracking 
    //If the position selected was wrong go back to previous position
    sol[i][j] =0;
    return false;
}

int main()
{
    int m,n;
    m=5; n=4;
    int sol[5][4]={0};
    char maze[][4]={
        {'O','X','O','O'},
        {'O','O','O','X'},
        {'O','O','X','O'},
        {'X','O','O','O'},
        {'X','X','O','O'}};
    // for(int i=0;i<m;i++)
    // {
    //     for(int j=0;j<n;j++)
    //         cin>>maze[i][j];
    // }
    Ratwin_or_lose(maze,sol,0,0,m,n);

    return 0;
}