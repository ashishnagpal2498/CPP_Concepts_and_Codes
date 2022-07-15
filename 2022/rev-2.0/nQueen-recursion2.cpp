// N-Queen Problem
// Placing N queens in rows

#include<iostream>
using namespace std;

bool canPlace(int board[10][10],int n,int i,int j){

    for(int column=i;column>=0;column--){
        if(board[column][j] == 1 ) return false;
    }

    int x=i,y=j;

    while(x>=0&& y>=0){
        if(board[x][y] == 1) return false;
        x--; y--;
    }

    x=i; y=j;
    // Right diagonal
    while(x>=0&&y<n){
        if(board[x][y] == 1) return false;
        x--; y++;
    }
    return true;
}
bool NQueen(int board[10][10],int n, int i){
   if(i==n){
        cout<<"Reached end of Board\n";
        for(int row=0;row<n;row++){
            for(int column=0;column<n;column++){
                if(board[row][column] == 1){
                    cout<<" Q ";
                }
                else cout<<" _ ";
            }
            cout<<endl;
        }
        return false;
   }

   // Check if the queen is Placable
   // traverse row wise
   for(int j=0;j<n;j++){
    if(canPlace(board,n,i,j)){
        board[i][j] = 1;
        if(NQueen(board,n,i+1)) return true;
    }
    board[i][j] = 0;
   }
   return false;
}
// bool NQueen(int board[10][10],int n, int i, int j){
//    if(i==n && j==n){
//         cout<<"Reached end of Board";
//         for(int row=0;row<n;row++){
//             for(int column=0;column<n;column++){
//                 if(board[row][column] == 1){
//                     cout<<" Q ";
//                 }
//                 else cout<<" _ ";
//             }
//             cout<<endl;
//         }
//         return true;
//    }

//    // Check if the queen is Placable
//    // traverse row wise
//    if(i<n&& j<n && canPlace(board,n,i,j)){
//         board[i][j] = 1;
//         // Call the recursion for next row
//         if(NQueen(board,n,i+1,j+1)) return true;
//    }
    
//     board[i][j] = 0;   
//    // For Loop to traverse horizontal
//    if(j<n){
//         return NQueen(board,n,i,j+1);
//    } 
//    // Backtrack
//    return false;
// }

int main(){
    int board[10][10] = {0};
    int n;
    cin>>n;
    // cout<<endl;
    NQueen(board,n,0);

}