//expedia question coins
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'arrangeCoins' function below.
 *
 * The function accepts LONG_INTEGER_ARRAY coins as parameter.
 */

void arrangeCoins(vector<long> coins) {

    int sz = coins.size();
    int n = sz;
    for(int i=0;i<sz;i++)
    {   
        long coinval = coins[i];
        int j=1; int ans=0;
        while(j<=coinval)
        {
            if(j<=coinval&&coinval>0)
            {
                //can place the no. of coins in that row
                ans++;
                coinval-=j;
            }
            j++;
            
        }
        cout<<ans<<endl;
    }

}

int main()
{
     string coins_count_temp;
    getline(cin, coins_count_temp);

    int coins_count = stoi(ltrim(rtrim(coins_count_temp)));

    vector<long> coins(coins_count);

    for (int i = 0; i < coins_count; i++) {
        string coins_item_temp;
        getline(cin, coins_item_temp);

        long coins_item = stol(ltrim(rtrim(coins_item_temp)));

        coins[i] = coins_item;
    }

    arrangeCoins(coins);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}