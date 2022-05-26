// Permutation of a String 

#include<iostream>
using namespace std;

void permutations(string s,int i){
    if(s[i] == '\0'){
        cout<<s<<" ";
    }

    for(int j=i;s[j]!='\0';j++){
        swap(s[i],s[j]);
        permutations(s,i+1);
    }
}

// Stair case
int stairVal[100] = {0};
int staircase(int n,int k){
    if(n<0) return 0;
    if(n==0) return 1;
    
    if(stairVal[n] != 0) return stairVal[n];
    int ans =0;
    for(int i=1;i<=k;i++){
        ans += staircase(n-i,k);
    }
    stairVal[n] = ans;
    return ans;
}

int main(){
    string str = "abc";
    permutations(str,0);
    cout<<"\n"<<staircase(5,3);
}