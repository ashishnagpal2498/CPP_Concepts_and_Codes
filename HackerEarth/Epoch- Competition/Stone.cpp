#include<iostream>
#include<vector>
using namespace std;
int main()
{   pair<char,int> stone;
    vector<pair<char,int>> game;
    int n,noof_stones;
    cin>>n;
    int val=0;
    int num,queries;
    bool flag =true;
    for(int i=0;i<n;i++)
    {   
        cin>>noof_stones;
       
         if(flag)
            {   for(int j=0;j<noof_stones;j++){
                 stone.first='A';
                stone.second =val;
                val++;
                game.push_back(stone);
                }
            flag=false;
            }
            else{
                for(int j=0;j<noof_stones;j++){
                stone.first = 'B';
                stone.second=val;
                val++;
                game.push_back(stone);
                    }
                    flag=true;
                }
        }
        cin>>queries;
        int index ;
        int sz =game.size();
        for(int i=0;i<queries;i++)
        {
            cin>>num;
            index = sz - (num);
           stone = game[index];
           cout<<ans.first<<endl;
        }
    //Input accordingly
    return 0;
}