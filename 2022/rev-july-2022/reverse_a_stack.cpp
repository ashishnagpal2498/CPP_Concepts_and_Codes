// Stacks
#include<iostream>
#include<stack>
using namespace std;

void printStack(stack<int> s){
    while(!s.empty()){
       cout<<s.top()<<" -> ";
        s.pop();
    }

    cout<<endl;
}

void reverseStack(stack<int>&s){
    if(s.size() == 1) return;

    int topElement = s.top();
    s.pop();
    reverseStack(s);

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
    int n;
    cout<<"Enter no. of Elements -> "<<endl;
    cin>>n;
    int a;
    for(int i=0;i<n;i++){
        cin>>a;
        s.push(a);
    }
    printStack(s);
    reverseStack(s);
    printStack(s);
    return 0;
}