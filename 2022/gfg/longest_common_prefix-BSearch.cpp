// Longest Common Prefix 

#include<bits/stdc++.h>
using namespace std;

int smallestString(string* s,int n){
    int minVal = INT_MAX;
    int index = -1;
    for(int i=0;i<n;i++){
        int sz = s[i].size();
        minVal = min(minVal,sz);
        minVal == s[i].size() ? index = i : index;
    }
    return index;
}

bool allContainsPrefix(string* s,int n,int start,int end, int index){

    for(int i=0;i<n;i++){
        for(int j=start;j<=end;j++){
            if(s[i][j] != s[index][j]) return false;
        }
    }
    return true;
}

string longestCommonPrefix(string* s,int n){

    // Calculate smallest String Length -
    int index = smallestString(s,n);

    string prefix = "";

    int start=0,end = s[index].size()-1;

    while(start<=end){

        int mid = (start+end)/2;

        if(allContainsPrefix(s,n,start,mid,index)){
            prefix+= s[index].substr(start,mid+1);
            start = mid+1; 
        }
        else {
            end = mid-1;
        }
    }
    return prefix;
}

int main(){
    string s[100];
    int n;
    cin>>n;
    cin.get();
    for(int i=0;i<n;i++){
        getline(cin,s[i]);
    }
    cout<<"Strings are :- \n";
    for(int i=0;i<n;i++){
    cout<<s[i]<<"\t";
    }
    cout<<"\nCommon Prefix is : ";
    cout<<longestCommonPrefix(s,n);
    return 0;
}