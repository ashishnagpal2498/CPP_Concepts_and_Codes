//stack 
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<stack>
using namespace std;
int maxvalofstack(stack<int> s)
{   //returns the max 
   int maxval= -10000 ;
   while(!s.empty())
   {    int topval = s.top();
        maxval = maxval < topval ? topval : maxval;
        s.pop();
   }
   return maxval;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    stack<int> s1;
    int query, val;
    int maxval = -100000;
    cin>>n;
    while(n>0)
    {   cin>>query;
        switch(query)
        {
            case 1 : cin>>val;
                        
                        s1.push(val);
                        break;
            case 2 : s1.pop(); break;
            case 3 :    maxval = maxvalofstack(s1); 
                        cout<<maxval<<endl;
                        break;
        }
        n--;
    }
    return 0;
}