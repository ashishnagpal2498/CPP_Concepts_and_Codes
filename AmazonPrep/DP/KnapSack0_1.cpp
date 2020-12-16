//0-1 KnapSack
#include<iostream>
using namespace std;

int KnapSack(int wts[],int prices[],int N,int W){
    if(N==0||W==0) return 0;

    int incl = 0, excl = 0;
    if(W - wts[N-1]>=0){
        incl = prices[N-1] + KnapSack(wts,prices,N-1,W-wts[N-1]);
    }
    excl = KnapSack(wts,prices,N-1,W);

    return max(incl,excl);
}

int knapSackDp(int wts[],int prices[],int N,int W){

    int dp[100][100];

    for(int item=0;item<=N;item++){
        for(int w=0;w<=W;w++){
            if(item == 0 || w == 0) dp[item][w] = 0;
            else{
                int incl=0,excl=0;
                if(wts[item-1]<=w){
                    incl = prices[item-1] + dp[item-1][w-wts[item-1]];
                }
                dp[item][w] = max(incl,dp[item-1][w]);
            }
        }
    }
    for(int i=0;i<=N;i++){
        for(int j=0;j<=W;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[N][W];
}

int main(){
    int wts[] ={2,2,3,1}, prices[] = {5,20,20,10};
    cout<<"Max Profit -> "<<KnapSack(wts,prices,4,5)<<endl;
    cout<<"Max Profit -> "<<knapSackDp(wts,prices,4,5);

    return 0;
}