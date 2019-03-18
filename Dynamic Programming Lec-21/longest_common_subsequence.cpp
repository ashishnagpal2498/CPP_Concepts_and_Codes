//lcs using recursion
#include<iostream>
using namespace std;
int lcs(string s1,string s2, int i,int j)
{
    if(i==0||j==0)
    {
        return 0;
    }
    if(s1[i-1]==s2[j-1])
    {
        return 1 + lcs(s1,s2,i-1,j-1);
    }
    int ans1 = lcs(s1,s2,i-1,j);
    int ans2 = lcs(s1,s2,i,j-1);
    return max(ans1,ans2);
}

//2-D dynamic programming -s
int lcs_BU_DP(string s1,string s2)
{
    int dp[100][100];
    int len1 = s1.length();
    int len2 = s2.length();
    for(int i=0;i<=len1;i++)
    {
        for(int j=0;j<=len2;j++)
        {
            if(i==0||j==0)
            {
                dp[i][j] = 0;
            }
            else if(s1[i-1]==s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else 
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    //Print the sequence -
    cout<<endl; 
    int x = len1 , y = len2;
    while(x>0&&y>0)
    {
        if(dp[x][y]==dp[x-1][y-1]+1)
        {
            cout<<s1[x-1];
            x--; y--;
        }
        else if(dp[x][y]==dp[x-1][y])
        {
            x--;
        }
        else
        {
            y--;
        }
    }
    return dp[len1][len2];
} 

int main()
{
    string str1,str2;
    str1 = "apple";
    str2= "mapen";
    cout<<lcs(str1,str2,5,5);
    cout<<lcs_BU_DP(str1,str2);
    return 0;
}