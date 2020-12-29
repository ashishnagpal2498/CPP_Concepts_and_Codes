//Longest Palindromic Subsequence

#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int lps(char * arr,int i,int n){
    if(i>n) return 0;
    if(i==n) return 1;

    if(arr[i] == arr[n]){
        return 2 + lps(arr,i+1,n-1);
    }
    else{
        return max(lps(arr,i+1,n),lps(arr,i,n-1));
    }
}
void print(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(j>=i){
                cout<<j;
            }
            else cout<<" ";
        }
        cout<<endl;
    }
}
void subsequence(){
    char str[] = "abc";
    int n=3;
    for(int i=0;i<(1<<n);i++){
        int j=0;
        while(j<n){
            if((1<<j)&i){
                cout<<str[j];
            }
            j++;
        }
        cout<<endl;
    }
}
int uniqueSubsequence(){
    char str[] = "gfg";
    int n = strlen(str);
    vector<int> lastIndex(256,-1);

    int* dp = new int[n+1];
    dp[0] = 1;

    for(int i=1;i<=n;i++){

        dp[i] = 2*dp[i-1];

        if(lastIndex[str[i-1]] != -1 ){
            dp[i] -= dp[lastIndex[str[i-1]]];
        }

        lastIndex[str[i-1]] = i-1;
    }
    return dp[n];
}
int main(){

    char arr[] = "BBABCBCAB";
    int size = 9;
    cout<<"Length of Palindromic Subsequence ->"<<lps(arr,0,size-1);
    cout<<endl;
    print();
    subsequence();
    cout<<"Unique subsequence"<<uniqueSubsequence();
}