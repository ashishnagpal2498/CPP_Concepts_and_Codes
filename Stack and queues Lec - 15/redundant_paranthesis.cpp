//redundant Paranthesis
//implementation using stack
#include<iostream>
#include<stack>
using namespace std;

bool redundant_exp(char *exp)
{
        stack<char> s1;
    for(int i=0; exp[i]!='\0';i++)
        {
           char ch = exp[i];
            switch(ch)
            {   case '(' : s1.push(ch); break;
                case ')' : if(s1.top()!='(')
                                {
                                    while(s1.top()!='(')
                                    {
                                            s1.pop();                             
                                    }
                                    //popping the ( bracket
                                    s1.pop();
                                    break;

                                }
                                else{
                                    return false;
                                }
                                default : s1.push(ch);
                }
    }
    return true;
}
int main()
{
    char exp[] ="(a+b)+(c*d)";
   bool ans = redundant_exp(exp);
   if(ans){
    cout<<"No redundancy in exp";
   }
   else{
    cout<<"redundancy there";
   }
    return 0;

}