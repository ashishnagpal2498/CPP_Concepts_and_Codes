//sudoku Solver -
#include<iostream>
using namespace std;
bool CanPlace(int sudoku[][9],int i,int j,int no)
{
    //that num should not be present in row
    for(int col=0;col<9;col++)
    {
        if(sudoku[i][col]==no) return false;
    }
    //no should no be in column
    for(int row =0;row<9;row++)
    {
        if(sudoku[row][j]==no) return false;
    }
    //Number should not be in subGrid
    int x = (i/3) *3 , y = (j/3)*3;
    for(int a=x;a<x+3;a++)
    {
        for(int b=y;b<y+3;b++)
        {
            if(sudoku[a][b]==no)  return false;
        }
    }

    return true;

}
void printBoard(int sudoku[][9])
{
    for(int a=0 ;a<9;a++)
        {
            for(int b=0;b<9;b++)
            {
                
                cout<<sudoku[a][b]<<" ";
                if((b+1)%3==0)
                {
                    cout<<"\t";
                }
            }
            if((a+1)%3==0)
                {
                    cout<<"\n";
                }
            cout<<endl;
        }
}
bool SudokuSolver(int sudoku[][9],int i,int j)
{
    if(i==9)
    {
        // Board Solved
        cout<<endl<<"Ans "<<endl;
        printBoard(sudoku);
        return true;
    }
     if(j==9)
    {
        return SudokuSolver(sudoku,i+1,0);  
    }
    if(sudoku[i][j]!=0)
    {
        return SudokuSolver(sudoku,i,j+1);
    }
   
    for(int no=1;no<=9;no++)
    {
        if(CanPlace(sudoku,i,j,no))
        {
            //place the num -
            sudoku[i][j] = no;
            bool smallBoard =  SudokuSolver(sudoku,i,j+1);
            if(smallBoard)
            {
                return true;
            }
        }
        
    }
    //backtrack - tried all nos but cannot place anything
    sudoku[i][j] =0;
    return false;
}
int main()
{
    int sudoku[][9] ={
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
    printBoard(sudoku);
    SudokuSolver(sudoku,0,0);
    return 0;
}