//Wine Bottles and Days
#include<iostream>
using namespace std;
int maxProfit(int wines[],int i,int j,int day)
{
    if(i>j) return 0;

    int opt1 = wines[i]*day+maxProfit(wines,i+1,j,day+1);
    int opt2 = wines[j]*day+maxProfit(wines,i,j-1,day+1);

    return max(opt2,opt1);
} 
int dp[100][100];
int winesProb(int*wines,int n)
{
    for
}
int main(int argc, char const *argv[])
{
    int wines[] = {2,3,5,1,4};
    cout<<"Max Profit "<<maxProfit(wines,0,4,1);
    return 0;
}