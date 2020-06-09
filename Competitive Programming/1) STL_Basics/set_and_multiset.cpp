#include<iostream>
#include<set>
using namespace std;
void printSet(set<int> s)
{
    for(auto val: s)
    {
        cout<<val<<" ";
    }
    cout<<endl;
}
void printMultiSet(multiset<int> mt)
{
    for(auto val: mt)
    {
        cout<<val<<" ";
    }
    cout<<"\n";
}
int main()
{
    set<int> st;
    multiset<int> mt;
    for(int i=0;i<10;i++)
    {
        st.insert(i); st.insert(i);
        mt.insert(i); mt.insert(i);
    }
    printSet(st);
    printMultiSet(mt);
    cout<<"\nDoes 4 exist in set if yes then how many times in multiSet"
    <<st.count(4)<<" Times "<<mt.count(4);
    cout<<"\nDoes 20 exist in set "
    <<st.count(20)<<" Times "<<mt.count(20);
    // Erase Function -
    cout<<"Erase";
    //
    st.erase(1);
    printSet(st);
}