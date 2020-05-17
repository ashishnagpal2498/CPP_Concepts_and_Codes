//codeChef lift
#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n,q,a,b;
        cin>>n>>q;
        int sum=0;
        int currPos = 0;
        while(q--)
        {
            cin>>a>>b;
            // diff a and b
            int diff = a-b;
            if(diff>0){
                currPos+=a;
                currPos+= (a-b);
                sum+=a;
                sum+=(a-b);
            }
            else{
                currPos-=a;
                currPos+=(a-b);
                sum+=a;
                sum+=(a-b);
            }
        }
        cout<<sum<<endl;
    }
}