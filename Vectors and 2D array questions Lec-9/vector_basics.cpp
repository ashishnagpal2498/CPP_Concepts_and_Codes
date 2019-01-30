#include<iostream>
#include<vector>
using namespace std;
int main()
{ //vector can expand itself - double
    //1) push_back()
    vector <int> vec;
    cout<<vec.capacity()<<endl;
    vec.reserve(10);
    for(int i=0;i<4;i++)
    {
        vec.push_back(i);

    }  
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<"  ";
        //either we can use this or 'at' function
    }
    cout<<endl;
    cout<<vec.capacity()<<endl;
    vec.shrink_to_fit();
    vec.pop_back();
    vec.resize(2);
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec.at(i)<<"  ";
        //either we can use this or 'at' function
    }
    cout<<vec.capacity()<<endl;
    vec.insert(vec.begin()+1,77);
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec.at(i)<<"  ";
        //either we can use this or 'at' function
    }
    return 0;
}