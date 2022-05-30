// Stacks 

#include<bits/stdc++.h>
using namespace std;

void print(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

bool balancedParanthesis(string s){
    if(s.size() == 0) return true;

    stack<char> st;

    int i=0;
    while(s[i] != '\0'){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') st.push(s[i]);

        else if(!st.empty() && (s[i] == ')') && st.top() != '(') return false;
    

        else if(!st.empty() && (s[i] == ']') && st.top() != '[') return false;


        else if(!st.empty() && (s[i] == '}') && st.top() != '{') return false;

        else{
            st.pop();
        }
        i++;
    }
    return st.empty();
}

void maxElement(){
    stack<int> normal,maxElement;
    int q,ele;
    cin>>q;
    while(q != -1){
        if(q == 1){
            cin>>ele;
            normal.push(ele);
            if(!maxElement.empty() && ele >= maxElement.top()) maxElement.push(ele);
            else if ( maxElement.empty()) maxElement.push(ele);
        }
        else {
            // find maximum element;
            if(maxElement.empty()){
                cout<<"Add more elements \n";
            }
            else {
                int mEle = maxElement.top();
                cout<<"Max Element so far "<<mEle<<endl;
                maxElement.pop();
                if(!normal.empty() && mEle == normal.top()){
                    normal.pop();
                }
                else{
                    while(!normal.empty() && mEle != normal.top() ){
                        maxElement.push(normal.top());
                        normal.pop();
                    }
                    if(!normal.empty()) normal.pop();
                }
            }
        }
        cin>>q;
    }
}

void reverse(stack<int> &s){
    if(s.empty()) return;

    int topElement = s.top();
    s.pop();
    // Take the top element ->
    
    reverse(s);
    stack<int> temp;
    while(!s.empty()){
        temp.push(s.top());
        s.pop();
    }
    s.push(topElement);
    while(!temp.empty()){
        s.push(temp.top());
        temp.pop();
    }
}

int main(){
    stack<int> s;
    s.push(5);
    s.push(9);
    s.push(7);
    print(s);
    reverse(s);
    print(s);

    string str;
    //cin.get();
    getline(cin,str);
    balancedParanthesis(str) ? cout<<" Balanced \n" : cout<<"Not balanced \n";
    maxElement();
    return 0;
}
