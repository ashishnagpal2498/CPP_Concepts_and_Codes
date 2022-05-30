// Queue using 2 stacks 

#include<bits/stdc++.h>
using namespace std;

template< typename T>
class Queue{
    stack<T> frontStack;
    stack<T> rearStack;
public:
    void pop(){
        if(!rearStack.empty()){
            rearStack.pop();
        }
        else if(!frontStack.empty()){
            // pushing all the elements to rear -
            while(!frontStack.empty()){
                rearStack.push(frontStack.top());
                frontStack.pop();
            }

            rearStack.pop();
        }
        else {
            cout<<"Stack already empty -\n";
        }
    }
    void push(T e){
        frontStack.push(e);
    }
    T front(){
        if(!rearStack.empty()){
            cout<<"Here \n";
            return rearStack.top();
        }
        else if(!frontStack.empty()){
            cout<<"Front stack \n";
            // pushing all the elements to rear -
            while(!frontStack.empty()){
                rearStack.push(frontStack.top());
                frontStack.pop();
            }
            return rearStack.top();
        }
        else{
            cout<<"Null \n";
            return -1;
        }
    }
    void print(){
        // print all the elements present in rear stack
        while(!this->rearStack.empty()){
            cout<<this->rearStack.top()<<" ";
            this->rearStack.pop();
        }

        while(! this->frontStack.empty()){
            this->rearStack.push(this->frontStack.top());
            this->frontStack.pop();
        }
        // Print opposite from front stack
        while(!this->rearStack.empty()){
            cout<<this->rearStack.top()<<" ";
            this->rearStack.pop();
        }
        cout<<"\n";
    }
};

int main(){
    Queue<int> A;
    A.push(8);
    A.push(9);
    A.push(15);
    A.print();
    cout<<"Front is -> ";
    cout<<A.front();
    return 0;
}