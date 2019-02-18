#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


#include<algorithm>

bool mysort(int a,int b)
{
    return a>b;
}
bool Soln_coins_pick(vector<int> coins, int &money,int j ,vector<int>&soln)
{
    if(money<=0||j==coins.size())
    {   
     if(soln.size()==0)
        {
            soln.push_back(0);
        }
       
   
        return true;
    }
    int coinused;
    for(int i=j;i<coins.size();i++)
    {  //Coin is picked from the array
        if(coins[i]<=money&&coins[i]!=0)
        {
            //this can be taken
            money = money - coins[i];
             coinused = coins[i];
            soln.push_back(coins[i]);
            //call the next 
            bool smaller_array = Soln_coins_pick(coins,money,0,soln);
            if(smaller_array)
            {
                return true;
            }
            else{   
                //Backtracking
                soln.pop_back();
                    money = money+coinused;     
               return  Soln_coins_pick(coins,money,j+1,soln);
            }
        }
    }
    return false;

}
// Complete the count_coins function below.
vector<int> count_coins(vector<int> coinDenominations, int monetaryValue) {

     sort(coinDenominations.begin(),coinDenominations.end(),mysort);
    vector<int> coins_selected;
   bool ans = Soln_coins_pick(coinDenominations,monetaryValue,0,coins_selected);
    if(!ans) coins_selected.push_back(0);
    // cout<<soln.size()<<endl;

    // Print of Coins_selected
    // for(int i=0;i<soln.size();i++)
    // {   
    //     cout<<soln[i]<<" ";
    // }
    return coins_selected;

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