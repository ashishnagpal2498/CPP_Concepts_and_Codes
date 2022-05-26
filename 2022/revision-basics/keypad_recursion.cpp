// Keypad recursion
#include<iostream>
using namespace std;

static string keys[] = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
void keypad(string str,string ans,int i){
    if(str[i] == '\0'){
        cout<<ans<<" ";
        return;
    }

    for(int j=0;j<keys[str[i]-'0'].size();j++){
        ans+= keys[str[i]-'0'][j];
        //cout<<ans<<endl;
        keypad(str,ans,i+1);
        ans.pop_back();
    }

}

int main(){
    
    string str;
    getline(cin,str);
    keypad(str,"",0);
    return 0;
}