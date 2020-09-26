// GCD operations
#include<bits/stdc++.h>
#define endl "\n"
#define ll long long int
using namespace std;
ll t, n;
ll a[200005];
ll b[200005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--)
    {   cin >> n;
        map<ll, ll> gcds;
        for (int i = 1; i <= n; i++) a[i] = i;
        for (int i = 1; i <= n; i++) cin >> b[i];
        // sort(b,b+n);
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            flag = false;
            if (a[i] == b[i]) {
                flag = true;
                continue;
            }
            if (b[i] > i)
            {   for (int j = i + 1; j <= n; j++) {
                    ll v =  __gcd(a[i], a[j]);
                    if (v == b[i]) {
                        a[i] = b[i];
                        a[j] = b[i];
                        flag = true;
                        break;
                    }
                }
                if (!flag) {
                    break;
                }
            }
            else {
                for (int j = i - 1; j > 0; j--) {
                    // cout<<"Here\n";
                    ll v =  __gcd(a[i], a[j]);
                    if (v == b[i]) {
                        // cout<<"Same\n";
                        a[i] = b[i];
                        flag = true;
                        break;
                    }
                }
                if (!flag) {
                    break;
                }
            }
        }
        if (flag) {cout << "YES\n";}
        else {cout << "NO\n";}
    }
    return 0;

}