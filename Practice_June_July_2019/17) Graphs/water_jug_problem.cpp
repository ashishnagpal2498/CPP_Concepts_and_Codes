//Water - JUG Problem
#include<iostream>
#define pii pair<int,int>
#include<map>
#include<queue>
#include<vector>
using namespace std;
void bfs(int a,int b,int target)
{
    map<pii,int> m;
    queue<pii> q1;
    bool isSolvable = false;
    vector<pii> path;
    q1.push({0,0});
    while(!q1.empty())
    {
        //Take out the front element -
        pii u = q1.front();
        q1.pop();

        //If the node is already being visited- 
        if(m[{u.first,u.second}]==1) continue;

        //If the value becomes greater or lesser 
        if(u.first>a||u.second>b||u.first<0||u.second<0) continue;

        m[{u.first,u.second}] = 1;

        if(u.first==target||u.second==target)
        {   isSolvable = true;
            //target node is achieved-
            if(u.first==target)
            {
                if(u.second!=0)
                path.push_back({u.first,0});
            }
            else
            {
                if(u.first!=0)
                 path.push_back({0,u.second});   
            }

              int sz = path.size(); 
            for (int i = 0; i < sz; i++) 
                cout << "(" << path[i].first 
                    << ", " << path[i].second << ")\n"; 
            break; 
        }
        //If target is not achieved-
        //processing need to be done-
        path.push_back({u.first,u.second});

        q1.push({u.first,b});
        q1.push({a,u.second});

        for(int ap=0;ap<=max(a,b);ap++)
        {
            int c = u.first+ap;
            int d = u.second -ap;

            if(c==a||(d==0&&d>=0))
                q1.push({c,d});
            c = u.first - ap;
            d = u.second + ap;
            if((c==0&&c>=0)||d==b)
            {
                q1.push({c,d});
            }
        }
        q1.push({a,0}); //empty jug 2
        q1.push({0,b}); //empty jug 1

    }
    //End of while loop
    if(!isSolvable)
    {
        cout<<"No Solution "<<endl;
    }
}

int main(int argc, char const *argv[])
{
    /* code */
     int Jug1 = 3, Jug2 = 5, target = 2; 
    cout << "Path from initial state "
            "to solution state :\n"; 
    bfs(Jug1, Jug2, target); 
    return 0;
}