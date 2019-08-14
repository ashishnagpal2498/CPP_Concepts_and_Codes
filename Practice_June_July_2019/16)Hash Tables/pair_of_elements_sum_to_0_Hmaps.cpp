//Pair of Elements Sum to 0;
#include <iostream>
#include<unordered_map>
using namespace std;
int main(int argc, char const *argv[])
{
    unordered_map<int,int> myMap;
    int arr[] = {-1,-3,-2,9,2,3,4,7,1};
    int n = sizeof(arr)/sizeof(int);
    for(int i=0;i<n;i++)
    {
        myMap[arr[i]] = arr[i];
    }

    // for(auto it= myMap.begin();it!=myMap.end();it++)
    // { //cout<<it->first<<endl;
    //     int val = it->first;
    //     if(myMap.count(-1*val))
    //     {
    //         cout<<val<<" "<<-1*val<<endl;
    //         myMap.erase(val);
    //         myMap.erase(-1*val);
    //     }
    // }
    for(int i=0;i<myMap.bucket_count();i++)
    {   cout<<"BUCKET "<<i<<"-> ";
        for(auto it = myMap.begin(i);it!=myMap.end(i);it++)
        {
            cout<<it->first<<" "<<it->second<<"|| ";
        }
        cout<<endl;
    }
    for(int i=0;i<myMap.bucket_count();i++)
    {
        for(auto it= myMap.begin(i);it!=myMap.end(i);it++)
        {
            int val = it->first;
            if(myMap.count(-1*val))
            {
                //print- both
                cout<<val<<" "<<-1*val<<endl;
                myMap.erase(val);
                myMap.erase(-1*val);
            }

        }
    }
    return 0;
}