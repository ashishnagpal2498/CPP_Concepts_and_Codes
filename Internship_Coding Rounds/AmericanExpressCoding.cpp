#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


#include<algorithm>

bool mysort(int a,int b)
{
    return a>b;
}
bool findSoln(vector<int> coins, int money ,vector<int>soln)
{
    //Base case will be if money becomes 0
    if(money<=0)
    {   if(soln.size()==0)
        {
            soln.push_back(0)
        }
        // This is the soln 
        for(int i=0 ;i<soln.size();i++)
        {
            cout<<soln[i]<<"  ";
        }
        return true;
    }
    int coinused;
    for(int i=0;i<coins.size();i++)
    {  //Coin is picked from the array
        if(coins[i]<=money)
        {
            //this can be taken
            money = money - coins[i];
             coinused = coins[i];
            soln.push_back(coins[i]);
            //call the next 
            bool chotavalue = findSoln(coins,money,soln);
            if(chotavalue)
            {
                return true;
            }
        }
        //soln[i]=0;
    }
    //If the whole loop runs and we cant find a denotion
    
    return false;

}
// Complete the count_coins function below.
vector<int> count_coins(vector<int> coinDenominations, int monetaryValue) {
//need to return a vector 
    //copy of monetaryValue
    // int money = monetaryValue;
    // int n = coinDenominations.size();
     sort(coinDenominations.begin(),coinDenominations.end(),mysort);
    // //sorted - 
    // for(int i=0;i<n;i++)
    // {
    //     if(coinDenominations[i])
    // }
    vector<int> soln;
    // soln.reserve(1);
    findSoln(coinDenominations,monetaryValue,soln);
    return soln;

}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string coinDenominations_count_temp;
    getline(cin, coinDenominations_count_temp);

    int coinDenominations_count = stoi(ltrim(rtrim(coinDenominations_count_temp)));

    vector<int> coinDenominations(coinDenominations_count);

    for (int i = 0; i < coinDenominations_count; i++) {
        string coinDenominations_item_temp;
        getline(cin, coinDenominations_item_temp);

        int coinDenominations_item = stoi(ltrim(rtrim(coinDenominations_item_temp)));

        coinDenominations[i] = coinDenominations_item;
    }

    string monetaryValue_temp;
    getline(cin, monetaryValue_temp);

    int monetaryValue = stoi(ltrim(rtrim(monetaryValue_temp)));

    vector<int> res = count_coins(coinDenominations, monetaryValue);

    for (int i = 0; i < res.size(); i++) {
        fout << res[i];

        if (i != res.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

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