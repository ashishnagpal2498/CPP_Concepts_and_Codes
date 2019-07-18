//Game of Two stacks -
#include<iostream>
using namespace std;
int game_of_stacks(int*arr1,int*arr2,int n,int m,int x)
{
    if(n==0)
    {
        return 1;
    }
    if(m==0)
    {
        return 1;
    }
    if(x==0)
    {
        return 1;
    }
    int opt1 =0;
    int opt2 =0;
    if(x>=arr1[0])
    {   //pick the element from the stack-
        //recusion
        opt1++;
        x -=arr1[0];
        opt1 += game_of_stacks(arr1+1,arr2,n-1,m,x);  
     }
     // Restore X
    // x+=arr1[0];
     if(x>=arr2[0])
     {
        opt2++;
        x-=arr2[0];
        opt2 += game_of_stacks(arr1,arr2+1,n,m-1,x);
     }
     return max(opt1,opt2);
}
int twoStacks(int x,int*a,int*b,int n,int m)
{
    int sum =0,count=0,i=0,j=0;
    while(i<n&&sum+a[i]<=x)
    {   sum+=a[i];
        i++;

    }
    count = i;
    while(j<m&&i>=0)
    {
        sum+=b[j];
        j++;
        while(sum>x&&i>0)
        {
            i--;
            sum-=a[i];
        }
        if(sum<=x&&i+j>count)
        {
            count = i+j;
        }
    }
    return count;
}
int main(int argc, char const *argv[])
{
    int T;
    cin>>T;
    int arr1[100005],arr2[100005],n,m;
    while(T--)
    {
    cin>>n>>m;
    int x;
    cin>>x;
    for(int i=0;i<n;i++) cin>>arr1[i];
    for(int i=0;i<m;i++) cin>>arr2[i];
    cout<<twoStacks(x,arr1,arr2,n,m)<<endl;    
    
    }
    return 0;
}