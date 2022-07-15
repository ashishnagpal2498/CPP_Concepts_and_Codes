// Longest Common Prefix - Tries
#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    bool isTerminal;
    TrieNode** children;
    TrieNode(){
        isTerminal = false;
        children = new TrieNode*[26];
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
    }
};

class Trie{
    TrieNode* root;

    void insertHelper(TrieNode* root,string s){
        // base case 
        if(s.size() == 0){
            root->isTerminal = true;
            return;
        }

        int index = s[0] - 'a';
        //cout<<index<<"\t";
        if(root->children[index] == NULL){
            root->children[index] = new TrieNode();
            // cout<<"Here ->\n";
        }

        insertHelper(root->children[index],s.substr(1));
    }
    void printTreeHelper(TrieNode* root, string s){
        for(int i=0;i<26;i++){
            if(root->children[i] != NULL){
                s+=('a' + i);
                if(root->children[i]->isTerminal){
                    cout<<s<<endl;
                }
                printTreeHelper(root->children[i],s);
                s.pop_back();
            }
        }
    }
public:
    Trie(){
        root = new TrieNode();
    }
    void insert(string s){
        insertHelper(root,s);
    }

    void printTree(){
        printTreeHelper(root,"");
    }

    int isSinglePath(TrieNode* root){
        int count = 0,i=0;
        int index = -1;
        while(count<2 && i<26){
            if(root->children[i] != NULL){
                count++;
                index = i;
            }
            i++;
        }
        //cout<<"Index -> "<<index<<endl;
        return count == 1 ? index : -1; 
    }
    void lcpHelper(TrieNode* root, string&s){
        if(root == NULL) return;

        int index = isSinglePath(root);
        if(index < 0) return;
        s+= (index + 'a');
        lcpHelper(root->children[index],s);
    }

    string longestCommonPrefix(){
        string s = "";
        lcpHelper(root,s);
        return s;
    }

    void dfsUtil(TrieNode* root, string ans){

        if(root->isTerminal){
            cout<<ans<<" \t";
        }

        for(char i='a';i<='z';i++){
            if(root->children[i-'a'] != NULL)
                dfsUtil(root->children[i-'a'], ans + char(i));
        }
    }

    void phoneSearch(string s){

        TrieNode* prevNode = root;

        int index = -1;
        string prefix = "";
        for(int i=0;i<s.size();i++){

            index = s[i] - 'a';
            prefix+=s[i];
            TrieNode* child = prevNode->children[index];
            if(child == NULL){
                cout<<"No value found\n";
                i++;
                break;
            }
            else {
                dfsUtil(child,prefix);
            }
            cout<<"\n";
            prevNode = child;
        }
    }
};

int main(){
    string s[100];
    Trie obj;
    int n;
    cin>>n;
    cin.get();
    for(int i=0;i<n;i++){
        getline(cin,s[i]);
    }
    cout<<"Strings are :- \n";
    for(int i=0;i<n;i++){
    obj.insert(s[i]);
    cout<<s[i]<<"\t";
    }
    cout<<"\n";
    obj.printTree();
    // cout<<"\nCommon Prefix is : ";
    // cout<<obj.longestCommonPrefix();
    string search = "gekk";
    cout<<"\n";
    obj.phoneSearch(search);

    return 0;
}