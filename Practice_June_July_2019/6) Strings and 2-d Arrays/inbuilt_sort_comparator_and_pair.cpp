//Inbuilt sort function Comparator and Pair
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool mycompare(int a,int b)
{
    return a>b;
}
int main()
{
    int arr[] ={3,7,8,9,0,1,2,6};
    int n = sizeof(arr)/sizeof(int);
    sort(arr,arr+n,mycompare);

    for(int i=0;i<n;i++)
       { cout<<arr[i]<<" ";}
   pair<int,char*> p1;
   p1.first = 100;
   p1.second = "abc";
   cout<<p1.first<<"  "<<p1.second;
    return 0;
}