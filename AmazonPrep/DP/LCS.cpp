// LCS
#include<iostream>
#include<cstring>
using namespace std;

int LCSRecursion(char* X, char*Y, int m, int n) {
    // Base Case ->
    if (m == 0 || n == 0 ) {
        return 0;
    }

    if (X[m - 1] == Y[n - 1]) {
        return 1 + LCSRecursion(X, Y, m - 1, n - 1);
    }

    return max(LCSRecursion(X, Y, m - 1, n), LCSRecursion(X, Y, m, n - 1));
}

int LCSDP(char* X, char* Y, int m, int n) {

    int dp[100][100] = {0};

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {

            // BASE CASE->
            if (i == 0 || j == 0) dp[i][j] = 0;

            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    int index = dp[m][n];

    // Create a character array to store the lcs string
    char lcs[index + 1];
    lcs[index] = '\0'; // Set the terminating character

    // Start from the right-most-bottom-most corner and
    // one by one store characters in lcs[]
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        // If current character in X[] and Y are same, then
        // current character is part of LCS
        if (X[i - 1] == Y[j - 1])
        {
            lcs[index - 1] = X[i - 1]; // Put current character in result
            i--; j--; index--;     // reduce values of i, j and index
        }

        // If not same, then find the larger of two and
        // go in the direction of larger value
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    // Print the lcs
    cout << "LCS of " << X << " and " << Y << " is " << lcs;
    return dp[m][n];
}

int main() {

    char X[] = "ACDBH";
    char Y[] = "MCADBH";
    int m = strlen(X);
    int n = strlen(Y);
    cout << " LCS -> recursion " << LCSRecursion(X, Y, m, n) << endl;
    cout << LCSDP(X, Y, m, n);
    return 0;
}