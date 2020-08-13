//Min Max String
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
class Trie{
public:
    Trie *arr[26];
    int isEndOfWord;
    Trie(){
        for(int i=0;i<26;i++) arr[i] = nullptr;
        isEndOfWord = 0;
    }
    void insert(string s,char c='9'){
        Trie* curr = this;
        // int i=0;
        for(auto m: s)
        {
            if(curr->arr[m - 'a'] == nullptr){
                curr->arr[m - 'a'] = new Trie;
                // cout<<"Here"<<endl;
            }
            curr = curr->arr[m - 'a'];
            // i++;
        }
        curr->isEndOfWord = 1;
        if(c != '9'){
            curr->arr[c - 'a'] = new Trie();
            curr = curr->arr[c - 'a'];
            curr->isEndOfWord = 1;
        }
    }
    string query2(Trie* c = nullptr){
        Trie* curr =  c == nullptr ? this : c;
        int i=0;
        string ans="";
        while(i<26){
            if(curr->arr[i] != nullptr){
                string s = query2(curr->arr[i]);
                // if(s != "") return s;
                ans+=('a'+i);
                ans+=s;
                // cout<<m<<endl;
                if(curr->isEndOfWord){
                    bool f = false;
                    for(int j=0;j<26;j++){
                        if(curr->arr[i]->arr[j] != nullptr){
                            f = true;
                            break;
                        }
                    }
                    if(f) {i++;continue;}
                    return ans;
                }
                // return m;
            }
            i++;
        }
        return ans;
    }
};
using namespace std;
ll t,n,q;
ll arr[200005];
int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cin>>t;
    t = 1;
    while(t--){
        cin>>n;
        // cin.get();
        string s;
        map<int,string> indexString;
        Trie g;
        ArrIn(n) { 
            cin>>s;
            indexString[i+1] = s;
            // cout<<"Insert called -> "<<endl;
            g.insert(s);
        }
        cin>>q;
        ll v;
        ArrIn(q){
            string p;
            cin>>v;
            int index;
            char c;
            switch(v){
                case 1:  cin>>index; cin>>c;
                            g.insert(indexString[index],c);
                            break;
                case 2:     p = g.query2();
                            cout<<p<<endl;
                            break;
                case 3:     cout<<"Query out of reach \n";
                            break;
            }
        }
    }    
    return 0;
}    