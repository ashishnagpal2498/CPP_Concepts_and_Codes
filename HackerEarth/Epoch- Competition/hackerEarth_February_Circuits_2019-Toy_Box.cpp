//HackerEarth - Challenge
//Toy Box -
// Solved  
#include<iostream>
using namespace std;
int main()
{   //Seive Computation - Constraints 

    int arr[105]={0};
    int max_sum = 0;
    int n,m,toy,box;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>toy>>box;
        if(arr[box]!=0)
        {
            int max_of_both = max(toy,arr[box]);
            if(max_of_both==toy)
            {
                max_sum-=arr[box];
                max_sum+=toy;
                arr[box] = toy;
            }
        }
        else
        {
            max_sum+=toy;
            arr[box] = toy;
        }
    }
    cout<<max_sum<<endl;
    return 0;
}