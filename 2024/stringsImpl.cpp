
#include <bits/stdc++.h>
using namespace std;



int main() {
    
    // String
    string str = "my name is khan";
    string pattern = "is";
    cout<<str.find('a',14)<<endl;
    
    // Erase -->
    
    str.erase(str.begin(),str.begin()+2);
    cout<<str<<endl;
    
     // string --> iterator 
    // cout<<str;
    
    // Remove all spaces
    while(str.length() != 0 && str.find(' ') < str.size()){
        str.erase(str.find(' '),1);
    }
    
    cout<<str<<endl;
    
    return 0;

}