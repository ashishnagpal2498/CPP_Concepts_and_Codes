//Minimum Coin Change Problem
#include<iostream>
using namespace std;
int minCoins(int coins[],int amount,int n)
{
    if(amount==0) return 0;

    int coinsNeeded = INT_MAX;

    for(int i=0;i<n;i++)
    {
        if(amount-coins[i]>=0)
        {
            int smallAns = minCoins(coins,amount-coins[i],n);
            if(smallAns!=INT_MAX)
            {
                coinsNeeded = min(coinsNeeded,smallAns+1);
            }
        }
    }
    return coinsNeeded;
}
int main(int argc, char const *argv[])
{
    int coins[] = {1,7,10};
    int n = sizeof(coins)/sizeof(int);
    int amount = 15;
    cout<<"MIN COINS "<<minCoins(coins,amount,n);
    return 0;
}