// N Queen Problem -

#include<iostream>
using namespace std;
bool CanPlace(int board[10][10],int i,int j,int n){
    int x = i,y=j;

    // check column
    for(int row = i;row>=0;row --){
        if(board[row][j] == 1) return false;
    }
    // left diagonal
    while(x >=0 && y>=0){
        if(board[x][y] == 1) return false;
        x--; y--;
    }

    x = i, y = j;

    while (x>=0 && y<n){
        if(board[x][y] == 1 ) return false;
        x--; y++;
    }

    return true;
}
bool nQueen(int board[10][10],int i,int n){

    if(i == n ){
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++){
                if(board[j][k] == 1) cout<<" Q ";
                else cout<<" _ ";
            }
            cout<<endl;
        }
        return true;
    }

    for(int j=0;j<n;j++){
        if(CanPlace(board,i,j,n)){
            board[i][j] = 1;

            bool nextQueen = nQueen(board,i+1,n);
            if(nextQueen) return true;
        }
        board[i][j] = 0;
    }
    return false;
}

int main(){

    int n;
    cin>>n;
    int i=0;
    int board[10][10] = {0};
    nQueen(board,i,n);
    return 0;
}