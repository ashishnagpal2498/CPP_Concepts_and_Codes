//Weighted maze problem -
#include<iostream>
using namespace std;

bool maze_solve(int arr[501][501],int sol[501][501],int n,int currow,int curcol)
{   //Base Case
    if(currow==n&&curcol==n)
    {
        //print the board
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cout<<sol[i][j]<<"  ";
            }
            cout<<endl;
        }
        cout<<endl;
        return false;
    }
    // if(curcol>n||currow>n)
    // {
    //     return false;
    // }
    //Self work
    sol[currow][curcol] =1;
    //Recursive case -

    if(arr[currow][curcol+1]!=1 && curcol<=n)
    {
        bool right = maze_solve(arr,sol,n,currow,curcol+1);
        if(right)
        {
            return true;
        }
    }
    if(arr[currow+1][curcol]!=1 && currow<=n)
    {
        bool down = maze_solve(arr,sol,n,currow+1,curcol);
        if(down)
        {
            return true;
        }
    }
    sol[currow][curcol] =0;
    return false;
}
int main()
{
    int n;
    cin>>n;
    int maze[501][501],sol[501][501]={0};
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>maze[i][j];
        }
    }
    cout<<"Input complete"<<endl;
    maze_solve(maze,sol,n,1,1);
    return 0;
}