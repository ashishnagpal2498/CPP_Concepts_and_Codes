#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'minMoves' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY avg as parameter.
 */
int totalmoves(int ele,vector<int>avg,int index)
{   int sz= avg.size();
    int indextomoved =0;
    //index from where we have to start
    bool flag = false;
    for(int i=index+1;i<sz;i++)
    {
        if(avg[i]==ele&&flag==true)
        {
            // Do nothing;
            break;
        }
        if(avg[i]!=ele&&flag==false)
        {

            flag=true;
            indextomoved++;
            break;
        }
        if(avg[i]!=ele&&flag==true)
        {
            indextomoved++;
        }
    
    }
    return indextomoved;
}

int minMoves(vector<int> avg) {
    int moves=0;
    int sz= avg.size();
    cout<<sz<<endl;
    for(int i=1;i<sz;i++)
    {
        if(avg[i]!=avg[i-1])
        {   //this calls a function which returns the value ,
            //how much places need to be moved
            int index = totalmoves(avg[i],avg,i);
            //swapping takes place

            moves = moves + (index-i);
            swap(avg[i],avg[index]);
            // cout<<"value of i"<<i<<endl<<"  Val of index "<<index<<endl;
            // cout<<"Swapped values are "<<avg[i]<<"  "<<avg[i+index];
        }
    }
    for(int i=0;i<sz;i++)
    {
        cout<<avg[i]<<"  ";
    }
    cout<<moves<<endl;
    return moves;
    // int sz = avg.size()
    // int moves = tellmoves(avg,0,sz,0);

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string avg_count_temp;
    getline(cin, avg_count_temp);

    int avg_count = stoi(ltrim(rtrim(avg_count_temp)));

    vector<int> avg(avg_count);

    for (int i = 0; i < avg_count; i++) {
        string avg_item_temp;
        getline(cin, avg_item_temp);

        int avg_item = stoi(ltrim(rtrim(avg_item_temp)));

        avg[i] = avg_item;
    }

    int result = minMoves(avg);

    fout << result << "\n";

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
