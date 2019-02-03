//maximum element stack
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<stack>
#include <algorithm>
using namespace std;

// int maxval(stack<int> s)
// {
//     int max_v = -10000;
//     while(!s.empty())
//     {
//         if(max_v<s.top())
//         {
//             max_v=s.top();
//         }
//         s.pop();
//     }
//     return max_v;
// }
// int main() {
//     /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
//    stack<int> s;
//     int testcase;
//     cin>>testcase;
//     while(testcase--)
//     {
//         int type,val;
//         cin>>type;
//         if(type==1)
//         {
//             cin>>val;
//             s.push(val);
//         }
//         if(type==2)
//         {
//             s.pop();
//         }
//         if(type==3)
//         {
//             cout<<maxval(s)<<endl;
//         }
//     }
//     return 0;
// }

int main() {
         long long int stack[100000],max[100000],x;
         long int N,top=-1,topm=0;
         int q;
         scanf("%ld",&N);
         for(long int i=0;i<N;i++)
         max[i]=0;
    
         for( long int i=0;i<N;i++ )
         {    
              
             
             scanf("%d",&q);
             
             switch(q)
             {
                 case 1: scanf(" %lli",&x);
                         if(max[topm]<=x)
                         {
                         max[++topm]=x;
                         }
                         stack[++top]=x;
                         break;
                 case 2: if(max[topm]==stack[top])
                          --topm;
                         --top;
                         break;
                 case 3: 
                         printf("%lld\n",max[topm]);
                         break;
             }
         }
    
    
    
     
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}

// 
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<stack>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    stack<int> s1,maxstack;
    int testcase;
    cin>>testcase;
    while(testcase--)
    {
        int type,val;
        cin>>type;
        switch(type)
        {
            case 1 : cin>>val;
                        if(maxstack.empty()||val>=maxstack.top())
                        {
                            maxstack.push(val);
                        }
                        s1.push(val);
                        break;
            case 2: if(maxstack.top()==s1.top()) maxstack.pop();
                    s1.pop();
                    break;
            case 3: cout<<maxstack.top()<<endl;
        }
    }
    return 0;
}