//Appy and Chef
#include<iostream>
#include<math.h>
using namespace std;
int main()
{   //B
    int testcase;
    cin>>testcase;
    while(testcase--)
    {   int N,A,B,K;
        int count=0,count_B=0;
    cin>>N;
    int counter_A=0,counter_B=0,c=0;
    cin>>A>>B>>K;
    counter_A = A-1; counter_B=B-1;
    for(int i=1;i<=N;i++)
    {   
        if(counter_A==0)
        {
            count++;
            counter_A=A;
        }
        if(counter_B==0)
        {   if(counter_A==A-1)
            count--;
            else{count++;}
            counter_B=B;
        }
        counter_A--;
        counter_B--;
            //problem solved by any one
    }
   // cout<<count<<endl;
    if(count>=K) {cout<<"Win"<<endl; }
    else {cout<<"Lose"<<endl;}
    }
    return 0;
}