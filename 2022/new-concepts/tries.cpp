// Tries - DataStructure -

#include<bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    char data;
    TrieNode** children;
    bool isTerminal;

    TrieNode(char d){
        data = d;
        children = new TrieNode*[26];

        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
    ~TrieNode(){
        delete children;
    }
};

class Trie{
    TrieNode* root;
    void insertHelper(string s, TrieNode* root){
        if(s.size() == 0){
            root->isTerminal = true;
            return;
        }

        int index = s[0] - 'a';
        TrieNode* child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else {
            child = new TrieNode(s[0]);
            root->children[index] = child;
        }
        insertHelper(s.substr(1),child);
    }

    bool searchHelper(TrieNode* root, string word){
        if(root == NULL) return false;
        if(word.size()==0){
            return root->isTerminal; 
        }

        int index = word[0] - 'a';
        return searchHelper(root->children[index],word.substr(1));
    }

    bool isEmptyNode(TrieNode* root){
        for(int i=0;i<26;i++){
            if(root->children[i]) return false;
        }
        return true;
    }

    void removeHelper(TrieNode* root,string word){
        // Base case
        if(word.size() == 0){
            root->isTerminal = false;
            return;
        }
        int index = word[0] - 'a';
        if(root->children[index] != NULL){
            removeHelper(root->children[index],word.substr(1));
            if(!root->children[index]->isTerminal && isEmptyNode(root->children[index])){
                TrieNode* waste = root->children[index];
                root->children[index] = NULL;
                delete waste;
            }
        }
        return;
    }

    void printHelper(TrieNode* root, string s){
        for(int i=0;i<26;i++){
            TrieNode* child = root->children[i];
            // Base Case ->
            if(child != NULL ){
                s+= child->data;
                if(child->isTerminal) { cout<<s<<endl;}
                printHelper(child,s);
                s.pop_back();
            }
        }
    }
public:

    Trie(){
        root = new TrieNode('\0');
    }

    void insert(string s){
        // Base case;
        insertHelper(s,root);
    }
    bool searchWord(string word){
       return searchHelper(root,word);
    }

    void removeWord(string word){
        removeHelper(root,word);
    }

    void printTrie(){
        printHelper(root,"");
    }

};

int main(){
    Trie obj;
    obj.insert("are");
    obj.insert("as");
    obj.insert("dot");
    obj.insert("do");

    bool ans = obj.searchWord("dot");
    ans ? cout<<" Word present ": cout<<" Not present";
    obj.removeWord("dot");
    cout<<"\n";
    ans = obj.searchWord("do");
    ans ? cout<<" Word present\n": cout<<" Not present\n";
    obj.printTrie();
    return 0;
}