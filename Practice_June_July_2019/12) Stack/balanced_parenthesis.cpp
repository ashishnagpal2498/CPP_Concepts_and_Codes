//Balanced Paranthesis
#include<iostream>
#include<stack>
using namespace std;
bool b_parenthesis(char arr[])
{   stack<char> s;
    int i=0;
    while(arr[i]!='\0')
    {   cout<<arr[i]<<endl;
        char ch = arr[i];
        switch(ch)
        {
            case '(' : 
            case '{' :
            case '[' : s.push(ch); break;
            case ')' : if(s.top()!='('||s.empty()) return false;
                        else
                        {
                            s.pop();
                        }
                        break;
            case '}' : if(s.top()!='{'||s.empty()) return false;
                        else
                        {
                            s.pop();
                        }
                        break;
             case ']' : if(s.top()!='['||s.empty()) return false;
                        else
                        {
                            s.pop();
                        }
                        break;
        }
        i++;
    }
    return s.empty();
}
int main(int argc, char const *argv[])
{
    char arr[] = "{a+(b+c)+d*[e-f]]";
    cout<<b_parenthesis(arr);
    return 0;
}