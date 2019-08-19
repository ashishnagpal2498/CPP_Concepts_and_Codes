//
#include<bits/stdc++.h>
using namespace std;
int cur=0;
int matrix[12][12];
bool visited[12];
deque <int> queuez;

void funct(int n)
{
    cout<<cur<<" ";
    visited[cur]=true;
    queuez.push_back(cur);

    do
    {
        for(int j=0;j<n;j++)
        {
            if(matrix[cur][j]==1 && !visited[j])
            {
                queuez.push_back(j);
                cout<<j<<" ";
                visited[j] = true;
            }
        }

        queuez.pop_front();
        if(!queuez.empty())
            cur = queuez.front();
    }while(!queuez.empty());
}
int main()
{
    int num=0;
    int n;
    cin>>n;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>matrix[i][j];

    for(int i=0;i<n;i++)
        visited[i]=false;

        funct(n);
    return 0;
}

