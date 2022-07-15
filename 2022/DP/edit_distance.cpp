// Edit Distance -

#include<iostream>
#include<string>
using namespace std;

int editDistanceRecursion(string s1,string s2){
    if(s1.size() == 0 && s2.size() == 0)
        return 0;
    
    else if(s1.size() == 0)
        return s2.size();

    else if(s2.size() == 0)
        return s1.size();

    // Characters are matching at the position ;
    if(s1[0] == s2[0]){
        return editDistanceRecursion(s1.substr(1),s2.substr(1));
    }

    else{
        int x,y,z;
        // Insert
        x = editDistanceRecursion(s1.substr(1),s2);

        // Delete Character
        y = editDistanceRecursion(s1,s2.substr(1));

        // Update character

        z = editDistanceRecursion(s1.substr(1),s2.substr(1));

        return 1+ min(x,min(y,z));
    }
}

int editDistanceMemoization(string s1,string s2,int**dp){
    if(s1.size() == 0 && s2.size() == 0)
        return 0;
    
    else if(s1.size() == 0)
        return s2.size();

    else if(s2.size() == 0)
        return s1.size();
    int n = s1.size();
    int m = s2.size();
    if(dp[n][m] != -1) return dp[n][m];
    // Characters are matching at the position ;

    if(s1[0] == s2[0]){
        dp[n-1][m-1] = editDistanceMemoization(s1.substr(1),s2.substr(1),dp);
        dp[n][m] = dp[n-1][m-1];
    }

    else{
        // Insert
        dp[n-1][m] = editDistanceMemoization(s1.substr(1),s2,dp);

        // Delete Character
        dp[n][m-1] = editDistanceMemoization(s1,s2.substr(1),dp);

        // Update character

        dp[n-1][m-1] = editDistanceMemoization(s1.substr(1),s2.substr(1),dp);

        dp[n][m] = 1+ min(dp[n-1][m],min(dp[n][m-1],dp[n-1][m-1]));
    }   
    return dp[n][m];
}

int main(int argc, char const *argv[])
{
    string s1 = "abcdf";
    string s2 = "abf";

    cout<<"Recursion - Edit Distance -> Make strings Equal -> "<<editDistanceRecursion(s1,s2)<<"\n";
    int n = s1.size(); 
    int m = s2.size();
    int ** dp = new int*[n+1];

    for(int i=0;i<=n;i++){
        dp[i] = new int[m+1];
        for(int j=0;j<=m;j++) dp[i][j] = -1;
    } 

    cout<<"Memoization - Edit Distance -> Make strings Equal -> "<<editDistanceMemoization(s1,s2,dp)<<"\n";
    return 0;
}
