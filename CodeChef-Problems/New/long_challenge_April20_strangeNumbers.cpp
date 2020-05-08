//Long challenge -
#include<iostream>
#include<vector>
using namespace std;
void primesGenerate(bool *primes)
{   primes[0] = false;
    primes[1] = false;
    for (int i = 2; i < 10005; i++)
    {   primes[i] = true;
        for (int j = 2; j * j <= i; j++)
        {
            if (i % j == 0) {
                primes[i] = false;
                break;
            }
        }
    }
}
bool isPrime(bool* prime, int n)
{
    return prime[n];
}
int main()
{
    vector<pair<int, int> > values;
    values.push_back(make_pair(0, 0));
    values.push_back(make_pair(1, 0));
    bool primes[10005];
    primesGenerate(primes);
    for (int i = 2; i < 10005; i++)
    {
        int factors = 0;
        int factor_primes = 0;
        for (int j = 1; j <= i; j++)
        {
            if (i % j == 0) {
                factors++;
                if (isPrime(primes, j)) factor_primes++;
            }
        }
        values.push_back(make_pair(factors, factor_primes));
    }
    for (int i = 1000; i < values.size(); i++)
    {
        cout << "Number " << i << " Factors " << values[i].first
             << " Primes " << values[i].second << endl;
    }
    int T;
    cin >> T;
    while (T--)
    {   int X, K;
        bool flag = false;
        cin >> X >> K;
        if (K < X && K < 7 && X < 50 )
        {   for (int i = 0; i < values.size(); i++)
            {   pair<int, int> v = values[i];
                if (v.first == X && v.second == K)
                {
                    flag = true;
                    break;
                }
            }
        }
        flag ? cout << 1 << endl : cout << 0 << endl;
    }
    return 0;
}