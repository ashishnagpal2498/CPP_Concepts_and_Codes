//Chef and Gloves
#include<iostream>
using namespace std;
bool front(int *finger,int *sheath,int n)
{
    for(int i=0;i<n;i++)
    {
        if(finger[i]>sheath[i])
        {
            return false;
        }
    }
    return true;
}
bool back(int *finger ,int *sheath,int n)
{
    for(int i=0,j=n-1;i<n;i++,j--)
    {
        if(finger[i]>sheath[j])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int testcase;
    cin>>testcase;
    int n;
    int fingerlength[100005],sheathlen[100005];
    while(testcase>0)
    {   cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>fingerlength[i];
        }
         for(int i=0;i<n;i++)
        {
            cin>>sheathlen[i];
        }

        bool frontfacing = front(fingerlength,sheathlen,n);
        bool backfacing = back(fingerlength,sheathlen,n);
        if(frontfacing && backfacing)
        {
            cout<<"both"<<endl;
        }
        else if(frontfacing)
        {
            cout<<"front"<<endl;
        }
        else if(backfacing)
        {
            cout<<"back"<<endl;
        }
        else{
            cout<<"none"<<endl;
        }

        testcase--;
    }
    return 0;
}