//Class Assignment - HackerBlocks -
#include<iostream>
using namespace std;
int count_str(int n,int i,string s)
{
    //Base Case -
    if(i==n)
    {
        return 1;
    }
    string temp = s;
    s+= 'a';
    
    int ans = count_str(n,i+1,s);
    //BackTrack - restore the string -
    s = temp;
    int ans2 =0;
    if(i>0&&s[i-1]!='b')
    {   s+= 'b';
        ans2 = count_str(n,i+1,s);
    }
    else if(i==0)
    {
        s+='b';
        ans2 = count_str(n,i+1,s);
    }
    return ans+ans2;
}

int findNoOfTrees(int n){
    if(n==0){
        return 1;
    }

    int ans =0;
    for(int i=1;i<=n;i++){
        ans += findNoOfTrees(n-i)*findNoOfTrees(i-1);
    }
    return ans;

}

int main(int argc, char const *argv[])
{   int T;
    cin>>T;
    while(T--)
    {   int n;
        cin>>n;
        cout<<"#"<<n<<" : "<<count_str(n,0,"")<<endl;
    }

    return 0;
}