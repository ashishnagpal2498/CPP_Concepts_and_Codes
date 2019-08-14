//STL maps
#include<iostream>
#include<unordered_map>
using namespace std;
int main(int argc, char const *argv[])
{
    unordered_map<string,int> myMap;
    myMap["Apple"] = 100;
    myMap.insert(make_pair("Mango",70));
    pair<string,int> p("Guava",21);
    myMap.insert(p);
    for(auto node:myMap)
    {
        cout<<node.first<<" , "<<node.second<<endl;
    }
    //Buckets - iteration -
    for(int i=0;i<myMap.bucket_count();i++)
    {
        cout<<"Bucket ->"<<i;
        for(auto it=myMap.begin(i);it!= myMap.end(i);it++)
        {
            cout<<it->first<<","<<it->second<<"|| ";
        }
        cout<<endl;
    }
    return 0;
}