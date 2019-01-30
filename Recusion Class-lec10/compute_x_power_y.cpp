//Computee x to power y using recursion
#include<iostream>
using namespace std;
int powerx(int x,int y)
{ 
    //base case
    if(y==0)
    {
        return 1;
    }

    //recursive call
 int  ans = x * powerx(x,y-1);
 return ans;
}
int FastSearch(int x,int y)
{
    if(y==0)
    {
        return 1;
            }
            int halfpower = FastSearch(x,y/2);
            halfpower *= halfpower;

            if(y&1)
            {
               return halfpower*=x;
            }
            else{
                return halfpower;
            }
}
int main()
{
    int x,y;
    cin>>x>>y;
    cout<<powerx(x,y)<<endl;
    cout<<"By fast search  "<<FastSearch(x,y);
}