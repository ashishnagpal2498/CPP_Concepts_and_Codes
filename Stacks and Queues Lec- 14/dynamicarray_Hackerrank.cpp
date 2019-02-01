//Dynamic Array question HackerRank
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Complete the dynamicArray function below.
int xorval(int x,int l_ans,int n)
{ //cout<<"At Xor val"<<endl;  
 int bn = x^l_ans;
    return bn % n;
}
vector<int> dynamicArray(int n, vector<vector<int>> queries) {

    int sz = queries.size();
   // cout<<sz;
    vector<vector<int>> seqs(n);
    vector<int> ans;
    // for(int i=0;i<n;i++)
    // {
    //     seqs[i].resize(n);
    // }
    int LastAnswer =0;
    for(int i=0;i<sz;i++)
    {   int x = queries[i][1];
        int y = queries[i][2];
        int  val_of_seq= xorval(x,LastAnswer,n);
        //This gives the ith sequence
        // cout<<"Value of ith seqs "<<val_of_seq<<endl;
        int qry = queries[i][0];
        if(qry==1)
        {
            //push the value of y integer;
            // cout<<"Pushing "<<y<<endl;
            seqs[val_of_seq].push_back(y);
        }
        else
        {
           int seqssizevalue =  seqs[val_of_seq].size();
           // cout<<"Val of sq size "<<seqssizevalue<<endl;
            int temp_ans = y % seqssizevalue ;
            LastAnswer = seqs[val_of_seq][temp_ans];
            ans.push_back(LastAnswer);
        }
    }
return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nq_temp;
    getline(cin, nq_temp);

    vector<string> nq = split(rtrim(nq_temp));

    int n = stoi(nq[0]);

    int q = stoi(nq[1]);

    vector<vector<int>> queries(q);

    for (int i = 0; i < q; i++) {
        queries[i].resize(3);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    vector<int> result = dynamicArray(n, queries);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
