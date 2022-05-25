// Anagram+ String Matching -
// #include<iostream>
#include<bits/stdc++.h>
using namespace std;
void calFre(string a,string pattern,int freq[],int freqPattern[]){
    int n= pattern.size();

    for(int i=0;i<n;i++){
        freq[a[i]]++;
        freqPattern[pattern[i]]++;
    }
}
bool isMatching(int freq[],int freqPattern[]){
    for(int i=0;i<256;i++){
        if(freq[i] != freqPattern[i]) {
            //cout<<i<<endl;
            return false;

        }
    }
    return true;
}
bool isAnagram(string a,string pattern){
    int freq[256]={0},freqPattern[256]={0};
    // Pre-Calculate
    calFre(a,pattern,freq,freqPattern); 
    int m = pattern.size(), n = a.size();
    for(int i=m;i<n;i++){
        if(isMatching(freq,freqPattern)) {
            
            return true;

        }
        //cout<<"Here - character "<<a[i];
        freq[a[i-m]]--;
        //cout<<"  Char to remove "<<a[i-m]<<" char to add "<<a[i]<<endl;
        freq[a[i]]++;
    }
    return false;
}
int main(){
    string a = "abcdnewacbsigodook";
    string pattern = "cabisgood";
    bool ans = isAnagram(a,pattern);
    ans ? cout<<"It is an Anagram" : cout<<" Not an Anagram";
    return 0;
}