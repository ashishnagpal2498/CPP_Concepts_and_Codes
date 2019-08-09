//K-sorted arrays merge - using heap -
//Heap Sort - if the size of arrays is n , kn log(kn)
#include<iostream>
#include <queue>
#include<functional>
#include<vector>
using namespace std;
class myCompare{
public:
    bool operator()(pair<int,int> A ,pair<int,int> B)
    {
        return A.first>B.first;
    }
};
int main(int argc, char const *argv[])
{
    priority_queue<pair<int,int> , vector<pair<int,int> > , myCompare > pq;
    vector<int> arr[10];
    int ele;
    for(int i=0;i<3;i++)
    {   int n;
        cin>>n;
        for(int j=0;j<n;j++)
        {
            cin>>ele;
            arr[i].push_back(ele);
        }
    }
    // int a[] = {1,3,4,7};
    // int b[] = {2,5,10,12};
    // int c[] = {0,5,15};
    // int m = sizeof(a)/sizeof(int);
    // int n = 4 , p =3;
    int k = 11;
    int *result_arr = new int[k];
    int j=0;
    for(int i=0;i<3;i++) pq.push(make_pair(arr[i][0],i));
    //0th element of all the arrays is put into Pq;
        //Pair stored inside Priority Queue - where first is the element and second is 
        //Array Number
    while(j<k)
    {
        auto element = pq.top(); //This return a pair -
        int val = element.first;
        int index = element.second;
        pq.pop();
        result_arr[j++] = val;
        // Remove the element from ith array
        arr[index].erase(arr[index].begin());
        if(arr[index].size()!=0)
        {
            //push the element -
            pq.push(make_pair(arr[index][0],index));
        }
        else
        {   //Array is Empty -----> 
            pq.push(make_pair(INT_MAX,index));
        }
    }
    for(int i=0;i<k;i++){cout<<result_arr[i]<<"  ";}
    return 0;
}