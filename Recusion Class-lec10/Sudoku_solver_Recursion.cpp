//Sudoku Solver Recursion
#include<iostream>
using namespace std;
bool CanSolve(int Sudoku[][9],int i,int j,int ele)
{
    //Check The row
    // for(int col=j;j<9;j++)
    // {
    //     if(Sudoku[i][col]==ele)
    //         return false;
    // }
    // //Check Column;
    // for(int row=i;row<9;row++)
    // {
    //     if(Sudoku[row][j]==ele)
    //         return false;
    // }
        for(int x=0;x<9;x++)
        {
            if(Sudoku[x][j]==ele||Sudoku[i][x]==ele)
            {
                return false;
            }

        }
    //Check The Grid
    int x = (i/3) *3;
   int y = (j/3) * 3;
    for(int xs=x;xs<x+3;xs++)
    {
        for(int ys=y;ys<y+3;ys++)
        {
            if(Sudoku[x][y]==ele)
            {
                return false;
            }
        }
    }
    return true;

}
bool SudokuSolver(int Sudoko[][9],int i,int j)
{
    if(i==9)
    { //Reach End of Sudoko 
        //print the sudoko
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
               { cout<<Sudoko[i][j]<<" ";
           if((j+1)%3==0){
            cout<<"\t";
           }
       }
            if((i+1)%3==0) cout<<"\n";
            cout<<endl;

        }
        return true;

    }
    if(j==9)
    {
        j=0;
        i++;
        return SudokuSolver(Sudoko,i,j); 
    }
    if(Sudoko[i][j]!=0)
    {
        return SudokuSolver(Sudoko,i,j+1); //Moving 1 cell ahead If blue cell reached
    }
    for(int a=1;a<=9;a++)
    {
        if(CanSolve(Sudoko,i,j,a))
        { Sudoko[i][j]=a;
            bool nextSudoko = SudokuSolver(Sudoko,i,j+1);
            if(nextSudoko)
            {
                    return true;
            }
        }
        //Loop will continue to check all the numbers 
    }
    //Loop ends , Agar koi bhi number nhi place kar pa rahe 
    Sudoko[i][j]=0;
    return false;
}
int main()
{   int matrix[][9]={
    {8,0,0,0,4,0,9,0,3},
    {0,0,0,0,0,0,8,1,0},
    {5,0,3,0,6,8,0,0,0},
    {3,0,0,0,0,7,0,2,0},
    {1,0,0,0,9,0,0,0,5},
    {0,2,0,1,0,0,0,0,7},
    {0,0,0,4,1,9,0,0,5},
    {0,0,0,0,8,0,0,7,9},
    {8,0,0,0,6,0,0,0,3}};
SudokuSolver(matrix,0,0);
    return 0;

}