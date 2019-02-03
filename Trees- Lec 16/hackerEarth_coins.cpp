#include<iostream>
using namespace std;
int main()
{
    int testcase;
    cin>>testcase;
    int coins;
    int k;
    while(testcase)
    {
        bool alan= true;

        cin>>coins;
        cin>>k;
        int move = 0;
        int val = k;
        // int i=2;
        while(coins>=0)
        {
            if(val<=coins&&move==0)
            {
                alan=true;
                coins = coins - val;
                move++;
            }

            if(val<=coins&&move==1)
            {
                alan=false;
                coins = coins - val;
                move++;
            }
           else if(move==2){
            move=0;
            val = val*k;
            
           }
           else{
            break;
           }
        }
        if(alan)
        {
            cout<<"Alice"<<endl;
        }
        else{
           cout<<"Bob"<<endl;
        }
        testcase--;
    }
    return 0;
}