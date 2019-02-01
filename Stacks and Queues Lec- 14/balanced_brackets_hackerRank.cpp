#include <bits/stdc++.h>
#include<stack>
using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    stack<char> Stack1;
    for(int i=0;s[i]!='\0';i++)
    {
        int ch = s[i];
        switch(ch)
        {
            case '{' :
            case '[' :
            case '(' : Stack1.push(ch);
                        break;
            case '}' : if(!Stack1.empty()&&Stack1.top()=='{')
                        {
                            Stack1.pop();
                         }
                         else
                         {
                            return "NO";
                         }
            case ']' :       if(!Stack1.empty()&&Stack1.top()=='[')
                        {
                            Stack1.pop();
                         }
                         else
                         {
                            return "NO";
                         }     
             case ')' : if(!Stack1.empty()&&Stack1.top()=='(')
                        {
                            Stack1.pop();
                         }
                         else
                         {
                            return "NO";
                         }            
        }
    }
    if(Stack1.empty())
    {
        return "YES";
    }
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
