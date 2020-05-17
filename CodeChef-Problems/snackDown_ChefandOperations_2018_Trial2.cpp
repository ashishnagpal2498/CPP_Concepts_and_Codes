//Chef and Operations
#include<iostream>
using namespace std;
bool isIterable(int *a,int *b,int &n)
{   int difference,position;
    for(int i=n;i>0;i--)
    {   
        if(a[i]==b[i]){continue;}
       // Chance of Iteration Exist
       else if(a[i]<b[i])
        {   int val=1;
            difference=b[i]-a[i];
            position = i-difference +1;
            if(position<1||position>n-2) return false;
            while(position<=i)
            {
                a[position]=a[position]+val;
                val++;
                position++;
            }

        }
        else 
        {
            return false;
        }

    }
    return true;
}
int main()
{
    int A[100005],B[100005],count=0,n,testcase;
    bool ans[10005];
    cin>>testcase;
    if(testcase<1||testcase>1000) return 0;
    while(testcase>0)
   { cin>>n;
        if(n>0&&n<100000)
        {for(int i=1;i<=n;i++) cin>>A[i];
            for(int j=1;j<=n;j++) cin>>B[j];
            ans[count++] = isIterable(A,B,n);
        }
        testcase--;
    }
    for(int i=0;i<count;i++)
    {
        if(ans[i]){cout<<"TAK"<<endl;}
        else {cout<<"NIE"<<endl;}
    }
    return 0;

}