//Unordered_Map - 
//STL - Hash Maps- 
#include<iostream>
#include<unordered_map>
using namespace std;
int main()
{
    // Declare an object of map
    unordered_map<string,int> myMap;
    // Ways to insert into hash map;
    myMap["Mango"] = 100;
    myMap.insert(make_pair("Apple",70));

    // Print the contents of map
    for(auto node:myMap)
    {
        cout<<node.first<<" , "<<node.second<<endl;
    }

    // Iterate over Bucket-
    for(int i=0;i<myMap.bucket_count();i++)
    {
        // Printing bucket wise
        cout<<"Bucket "<<i<<" -> ";
        for(auto it = myMap.begin(i);it!=myMap.end(i);it++)
        {
            cout<<it->first<<" , "<<it->second;
        }
        cout<<endl;
    }
    return 0;
}