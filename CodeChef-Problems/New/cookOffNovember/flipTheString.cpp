// Flip the String
#include<bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;
ll t, n, k, m;
ll arr[200005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {

        ll count = 0;
        string a, b;
        cin >> a >> b;
        n = a.size();
        bool flagOdd = false, flagEven = false;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0) {
                if (flagOdd == false && a[i] != b[i])
                    // odd position for substring
                {
                    flagOdd = true;
                    count++;
                }
                else if (flagOdd == true && a[i] == b[i]) {
                    flagOdd = false;
                }

            }
            else {
                if (flagEven == false && a[i] != b[i]) {
                    flagEven = true;
                    count++;
                }
                else if (flagEven == true && a[i] == b[i]) {
                    flagEven = false;
                }
            }

        }
        cout << count << endl;
    }
    return 0;
}