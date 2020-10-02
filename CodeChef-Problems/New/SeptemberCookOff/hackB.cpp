#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int one_one, one_two, two_one, two_two;
    int first_diagonal = 0, second_diagonal = 0, both = 0;
    for (int i = 0; i < n; i++) {
        cin >> one_one >> one_two >> two_one >> two_two;
        if (one_one == two_two && one_two == two_one) both++;
        if (one_one == two_two) first_diagonal++;
        if (one_two == two_one) second_diagonal++;
    }
    if (m % 2 != 0) {
        cout << "NO\n";
        return;
    }
    if (m == 2) {
        if (both > 0 || second_diagonal > 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
    }
    if (both < 1 && second_diagonal < 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}