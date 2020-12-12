// String methods
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
ll arr[200005];
class myComp{
    bool operator()(int a,int b){
        return a>b;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s ="abcde";

    //1. Insert -> 
    s.insert(3,"zo");
    cout<<"Insert Operation -> "<<s<<endl;
    char c[] = "lmno";  
    // position and character array ->
    s.insert(1,c);
    // position , size (no. of copies -> ) , char value
    s.insert(5,1,'q');
    // Iterator and char value
    s.insert(s.begin()+9,'p');
    cout<<"Insert Character -> "<<s<<endl; 

    //2. Erase 
    // Position and no. of positions ->
    s.erase(1,4);
    cout<<"Erase value  -> "<<s<<endl;

    //3. Substr
    cout<<"Substr -> "<<s.substr(1,5)<<endl;
    
    //4. find 
    // If no Match , then -> npos
    cout<<"Find  -> "<<s.find("pode",0)<<endl;

    // 5. Contructor ->
    string s2("lm");
    string s3(5,'c');
    cout<<s2<<endl<<s3<<endl;

    // find - contructor  1) string , 2) pos/ no 
    // insert erase, substr - 1) param - position -> 2) noOf/string
    
    vector<int> a;
    a.push_back(9);
    a.push_back(5);
    a.insert(a.begin()+2,6);
    // erases a single value provided ->
    a.erase(a.begin());
    string s99 = to_string(837);
    cout<<s99<<endl;
    cout<<"Vector -> "<<a[0]<<" "<<a[1]<<endl;
    return 0;
}    