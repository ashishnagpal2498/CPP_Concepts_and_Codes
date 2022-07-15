// Longest commong Subsequence 
#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;


// Longest Common Subsequence ->

int lcsRecursion(string s1, string s2){
    if(s1.size() == 0 || s2.size() == 0) {
        return 0;
    }
    int x1 = INT_MIN,x2 = INT_MIN;
    if(s1[0] == s2[0]){
        return 1 + lcsRecursion(s1.substr(1),s2.substr(1));
    }
    else{
        x1 = lcsRecursion(s1.substr(1),s2);
        x2 = lcsRecursion(s1,s2.substr(1));
        // Can be avoided, because internally Handled ->
        // x3 = lcsRecursion(s1.substr(1),s2.substr(1));
    }

    return max(x1,x2);

}

int ansArray[100][100];
int lcsMemoization(string s1, string s2){
    if(s1.size() == 0 || s2.size() == 0) {
        return 0;
    }

    int n = s1.size();
    int m = s2.size();
    if(ansArray[n][m] != -1) return ansArray[n][m];

    if(s1[n-1] == s2[m-1]){
        ansArray[n-1][m-1] = lcsRecursion(s1.substr(1),s2.substr(1));
        ansArray[n][m] = 1 + ansArray[n-1][m-1];
    }
    else{
        ansArray[n-1][m] = lcsRecursion(s1.substr(1),s2);
        ansArray[n][m-1] = lcsRecursion(s1,s2.substr(1));
        
        ansArray[n][m] = max(ansArray[n-1][m],ansArray[n][m-1]);
    }
    return ansArray[n][m];
}

int lcsBottomUp(string s1,string s2){
    int n = s1.size();
    int m = s2.size();
    int** dp = new int*[n+1];

    for(int i=0;i<=n;i++){
        dp[i] = new int[m+1];
    }

    // Filling 1st Column ->
    for(int i=0;i<=n;i++){
        dp[i][0] = 0;
    }

    // Filling 1st Row
    for(int i=0;i<=m;i++){
        dp[0][i] = 0;
    }

    for(int i=1;i<=n;i++){
        // String s1 is present in Row

        // String s2 present in Column Wise
        for(int j=1;j<=m;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}

//Subsequence of a string
void subsequence(string s, string output){
    if(s.size() == 0){
        cout<<output<<"\t";
        return;
    }

    subsequence(s.substr(1),output);

    // Include
    subsequence(s.substr(1),output + s[0]);
} 

void setArray(int n,int m){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            ansArray[i][j] = -1;
        }
    }
}

int main(){
    string s = "abc";
    cout<<"Subsequence of "<<s<<" are ->\n";
    subsequence(s,"");
    cout<<"\n";
    string s1 = "abad";
    string s2 = "badecb";
    int ans = lcsRecursion(s1,s2);
    setArray(s1.size(),s2.size());
    cout<<"Length of Longest Common Subsequence -> Memoization - "<<lcsMemoization(s1,s2)<<"\n";
    cout<<"Length of LCS -> "<<lcsBottomUp(s1,s2);
    return 0;
}