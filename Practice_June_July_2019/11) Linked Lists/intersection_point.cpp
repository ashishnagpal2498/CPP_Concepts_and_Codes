//intersection point of two LINKED LIST
#include<iostream>
#include<list>
using namespace std;
bool isPoint(list<int> head,int val)
{   //cout<<val<<endl;
    while(!head.empty())
    {
        if(head.front()==val)
        {
            return true;
        }
        head.pop_front();
    }
    return false;
}
int main(int argc, char const *argv[])
{
    int n,m,data;
    cin>>n;
    list<int> head1,head2;
    for(int i=0;i<n;i++)
    {
        cin>>data;
        head1.push_back(data);
    }
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>data;
        head2.push_back(data);
    }
    //cout<<"INPUT DONE ";
    bool flag = false;
    for(int i=0;i<n;i++)
    {
        int curval = head1.front();
        bool ans = isPoint(head2,curval);
        if(ans)
        {   flag = true;
            break;
        }
        head1.pop_front();
    }
    if(flag)
    {
        cout<<head1.front()<<endl;
    }
    else
    {
        cout<<-1;
    }
    return 0;
}