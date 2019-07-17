//Redundant Paranthesis
#include <iostream>
#include <stack>
using namespace std;
int main()
{
    char str[] = "((a+b)+c)";
    bool flag;
    stack<char> s ;
    for(int i=0;str[i]!='\0';i++)
    { flag = false;
        char ch = str[i];
        switch(ch)
        {
            case ')' : if(s.top()=='(')
                        {
                            cout<<"Redundant"<<endl;
                             flag = true;
                            break;
                           
                        }
                        else{
                            while(s.top()!='(')
                        {
                            s.pop();
                        }
                        }
                        s.pop(); break;
            default : s.push(ch);            
        }
        if(flag)
        {
            break;
        }
    }
    if(!flag)
    {
        cout<<"Not Redundant"<<endl;
    }
    return 0;
}