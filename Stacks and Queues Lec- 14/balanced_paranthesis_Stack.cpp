//Balanced Paranthesis
#include<iostream>
#include<stack>
using namespace std;
bool isbalanced(char*ptr)
{   stack<char> s;
    for(int i=0;ptr[i]!='\0';i++)
    {
        //We'll use stack , if the opening paranthesis 
        //Push to stack
        
        char ch = ptr[i];
        switch(ch)
        {
            case '{':
            case '[' :
            case '(' : s.push(ch);
                        break;
            case '}' : if(!s.empty()&& s.top()=='{')
                        {
                            s.pop(); break;
                            }
                            else return false;
            case ']' : if(!s.empty()&& s.top()=='[')
                        {
                            s.pop(); break;
                            }
                            else return false;
            case ')' : if(!s.empty()&& s.top()=='(')
                        {
                            s.pop(); break;
                            }
                            else return false;
        }
    }
    return s.empty();
    //In this line we are returning the actual stack - condition
    //If the stack is not empty , that means opening brackets are more than closing

}
int main()
{
    char a[] = "{a+(b-c)*d+f/[g-r]}+h}";
    bool ans =isbalanced(a);
    if(ans)
    {
        cout<<"Yes , Balanced";
    }
    else{
        cout<<"Not Balanced"<<endl;
    }
    return 0; 
}