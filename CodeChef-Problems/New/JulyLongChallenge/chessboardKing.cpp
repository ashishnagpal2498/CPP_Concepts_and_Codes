// chessboard and king 
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++) cin>>arr[i]
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
ll arr[200005];
int eucleadDistance(int x,int y,int n,int m){
   return (sqrt((x - n)*(x - n) + (y-m)*(y-m))); 
}
void markNeighbours(char board[][8],int i,int j){
    if(i+1<8&&j+1<8){
        board[i+1][j+1] = 'X';
    }
    if(i+1<8&&j-1>=0){
        board[i+1][j-1] = 'X';
    }
    if(j+1<8){
        board[i][j+1] = 'X';
    }
    if(i+1<8){
        board[i+1][j] = 'X';
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t;
    while(t--){
        char board[8][8];
        cin>>n;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++) board[i][j] = '.';
        }
        int count = 0;
        int lastI=0,lastJ=0;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(i==0&&j==0){
                    board[i][j] = 'O';
                    count++;
                    markNeighbours(board,i,j);
                }
                else if(count<n){
                    board[i][j] = '.';
                    count++;
                    markNeighbours(board,i,j);
                }
                else break;
            }
        }    
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cout<<board[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}    