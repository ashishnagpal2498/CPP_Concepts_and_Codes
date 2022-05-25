#include<iostream>
using namespace std;
int main(){
    int T;
    int val;
    cin>>T;
    while(T--){
        int team1=0,team2=0;
        for(int i=0;i<10;i++){
            cin>>val;
            if(i%2==0 && val&1){
                team1++;
            }
            else if(i%2 !=0 && val&1){
                team2++;
            }
        }
        if(team1 == team2){
            cout<<0<<endl;
        }
        else if(team1 > team2){
            cout<<1<<endl;
        }
        else{
            cout<<2<<endl;
        }
    }
    return 0;
}