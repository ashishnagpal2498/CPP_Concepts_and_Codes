// Sum of two pairs using hash maps - 0
//Remove cycle in linked list - saari nodes ka address put into hashmap-
//If the node is visited | then cycle exist
#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    unordered_map<int,int> myMap;
    myMap[1] = -1;
    myMap[3] = 0;
    myMap[8] = 16;
    myMap[20] = -20;

    for(auto node:myMap)
    {
        if(node.first+node.second==0)
        {
            cout<<node.first<<"  "<<node.second<<endl;
        }
    }
    return 0;
}