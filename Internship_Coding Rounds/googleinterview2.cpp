#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> A;
    int n;
    int a;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        A.push_back(a);
    }
    //Distance from parent node
    vector<int> distance;
    for(int i=0;i<n;i++)
    {
        if(A[i]==-1)
        {
            distance.push_back(-1);
        }
        else
        {   if(A[i]<D)
            distance.push_back(-1);
            else
            {
                distance.push_back(A[i]-D);
            }
        }
    }
    return distance;
}