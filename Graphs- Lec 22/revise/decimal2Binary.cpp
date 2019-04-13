//Decimal to binary -
#include<iostream>
using namespace std;
void dec2Binary(int n)
{
    int temp = n;
    int arr[100005]={0};
    int sz=0;
    while(temp)
    {
        
        int rem = temp%2;
        arr[sz++] = rem;
        temp=temp>>1;

    }
   // cout<<"Cl";
    for(int i=sz-1;i>=0;i--)
    {
        cout<<arr[i];
    }

}
void BinarytoDec(int n)
{
    int temp = n;
    int arr[100005]={0};
    int sz=0;
    long long int p=1;
   long long int ans = 0;
    while(temp>0)
    {
        
        int rem = temp%10;
        //arr[sz++] = rem;
        temp=temp/10;
        ans=ans + rem*p;
        p=p<<1;
    }
   // cout<<"Cl";
    // for(int i=sz-1;i>=0;i--)
    // {
    //     cout<<arr[i];
    // }
    cout<<endl<<ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<"Binar conversion "<<endl;
    dec2Binary(n); cout<<endl;
    int A,B;

    cout<<"A & B ";
    cin>>A>>B;
    dec2Binary(A); cout<<endl;
    dec2Binary(B);cout<<endl;
    cin>>n;
    cout<<"Binary To decimal"<<endl;
    BinarytoDec(n);
   return 0;
}