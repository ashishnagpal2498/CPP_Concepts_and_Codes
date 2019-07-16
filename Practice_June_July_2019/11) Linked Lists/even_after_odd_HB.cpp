//Even after Odd -
#include<iostream>
#include<list>
using namespace std;
int main(int argc, char const *argv[])
{
    list<int> head;
    int n;
    int data;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>data;
        if(data&1)
        head.push_front(data);
        else
        {
            head.push_back(data);
        }
    }
    // head.push_front(2);
    // head.push_front(3);
    // head.begin();
    while(!head.empty())
    {
        cout<<head.front()<<" ";
        head.pop_front();
    }

    return 0;
}