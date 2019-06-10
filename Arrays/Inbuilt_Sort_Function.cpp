//Inbuilt sort function - And Comparators 
#include<iostream>
#include<algorithm>
using namespace std;
bool Stringcompare(string s1,string s2)
{   //according to length
    //according to lexiographical order if length same
    if(s1.length()==s2.length())
    {
        return s1<s2;
    }
    return s1.length()<s2.length();
}
void stringsort(string s[],int n)
{
    sort(s,s+n,Stringcompare);
    for(int i=0;i<n;i++) cout<<s[i]<<endl;
}
bool myCOmapare(int a,int b)
{
    return a<b; 
    //sorting takes place according to this function
    //if condition ke andar this fuction goes
    //It depends on what condition is given here .
}
int main()
{
// { int arr[]={5,4,2,3,6,1};
//     int n=sizeof(arr)/sizeof(int);

//     sort(arr,arr+n,myCOmapare);
//     for(int i=0;i<n;i++) {cout<<arr[i]<<"  ";}
int num;
cin>>num;
string s[100];
cin.get();
for(int i=0;i<num;i++) cin>>s[i];
    stringsort(s,num);
    return 0;
}
