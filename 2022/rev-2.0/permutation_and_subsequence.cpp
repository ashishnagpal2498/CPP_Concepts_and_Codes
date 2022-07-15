// Permutation and Subsequence of a String

#include<iostream>
#include<string>
#include<vector>
using namespace std;

void subsequence(string str, string s,int i,vector<string>&ans){
    if(str[i] == '\0'){
        ans.push_back(s);
        return;
    }

    subsequence(str,s,i+1,ans);
    s+=str[i];
    subsequence(str,s,i+1,ans);
}

void permutation(string str,int i,vector<string>& ans){
    if(str[i] == '\0'){
        ans.push_back(str);
        return;
    }
    for(int j=i;j<str.size();j++){
        swap(str[i],str[j]);
        permutation(str,i+1,ans);
    }

}

void printVector(vector<string> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"\n";
    }
}
int main(){

    string s = "abc";
    vector<string> ans;
    cout<<"Permutations are :- \n";
    permutation(s,0,ans);
    printVector(ans);
    ans.clear();
    cout<<"Subsequence are :- \n";
    subsequence(s,"",0,ans);
    printVector(ans);
    return 0;
}