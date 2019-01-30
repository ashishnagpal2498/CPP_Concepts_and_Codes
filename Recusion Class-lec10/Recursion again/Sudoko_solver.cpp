//Sudoko Solver
#include<iostream>
using namespace std;
bool CanPlace(int board[][9],int i,int j,int n,int num)
{
    for(int a=0;a<n;a++)
    {
        if(board[a][j]==num||board[i][a]==num)
        {
            return false;
        }
    }
    int x = (i/3)*3;
    int y = (j/3)*3;
    for(int sx=x;sx<x+3;sx++)
    {
        for(int sy=y;sy<y+3;sy++)
        {
            if(board[sx][sy]==num) return false;
        }
    }
return true;
}
void printMatrix(int board[][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cout<<board[i][j]<<"  ";
            if((j+1)%3==0)
            {
                cout<<"\t";
            }
        }
        if((i+1)%3==0)
            {cout<<endl;}
        cout<<endl;
    }
}
bool sudokoSolver(int sudoko[][9],int i,int j,int n)
{
    if(i==n)
    {
        //Base case hit .
        //End of board reached
        //Print the configration
        cout<<endl<<"Solution"<<endl;
        printMatrix(sudoko);

        return true;

    }

    if(j==n)
    {
        i=i+1;
        j=0;
        return sudokoSolver(sudoko,i,j,n);
    }
    if(sudoko[i][j]!=0)
    {
        return sudokoSolver(sudoko,i,j+1,n);
    }
    for(int num=1;num<=9;num++)
    {
        //Check if we can place that no. or not
        if(CanPlace(sudoko,i,j,n,num))
        {   sudoko[i][j]=num;
            bool chotaboard = sudokoSolver(sudoko,i,j+1,n);
            if(chotaboard)
            {
                return true;
            }
        }
        //Every num tried by for loop
       
    }
    //
     sudoko[i][j]=0;
    return false;
}
int main()
{
    int n=9;
    int board[][9] ={
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    printMatrix(board);
    sudokoSolver(board,0,0,9);
    return 0;
}