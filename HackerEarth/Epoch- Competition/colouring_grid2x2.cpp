//Colouring the Grid
#include<iostream>
using namespace std;

bool Cancolor(char grid[][100],int i,int j,int n,int m)
{
    if(i+1==n||j+1==m)
    {
        return false;
    }
    for(int a=i;a<2;a++)
    {
        for(int b=j;b<2;b++)
        {
            if(grid[a][b]=='#')
            {
                return false;
            }
            else {
                grid[a][b]='T';
            }
        }
    }
    return true;
}

bool grid_color(char grid[][100],int i,int j,int n,int m)
{
    //Base Case
    if(i==n||i+1==n)
    {
        //checking if whole grid is colored or not
        for(int i=0;i<n;i++)
        { cout<<endl;
            for(int j=0;j<m;j++)
            { cout<<grid[i][j];
                if(grid[i][j]=='T')
                {

                }
                else if(grid[i][j]=='#')
                {

                }
                else {
                    cout<<"no";
                }
            }
        }
        cout<<"YES";
        return false;
    }

    if(j==m||j+1==m)
    {
        i++; j=0;
        return grid_color(grid,i,j,n,m);
    }
   
    //Recursive case;
    if(grid[i][j]!='#')
    {   if(Cancolor(grid,i,j,n,m))
        {bool chhotagrid = grid_color(grid,i,j+1,n,m);
            if(chhotagrid)
            {
                return true;
            }
        }
        return grid_color(grid,i,j+1,n,m);

    }
   return false;
   // else{
   //  grid_color(grid,i,j+1,n,m);
   // }
}

int main()
{
    int N,M;
    cin>>N>>M;
    char grid[100][100];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
            cin>>grid[i][j];
    }
    grid_color(grid,0,0,N,M);
    return 0;
}