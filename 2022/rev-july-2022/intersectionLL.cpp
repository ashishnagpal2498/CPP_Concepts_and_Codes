// Linked List Intersection Point
#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(){
        
    }
    Node(int d){
        data = d;
        next = NULL;
    }

    Node* buildLL();
    void printTree(Node* head);
};

Node* Node::buildLL(){
    int d;
    cin>>d;
    Node* head= NULL,*temp = NULL;
    while(d != -1){
        if(head == NULL){
            head = new Node(d);
            temp = head;
        }
        else{
            temp->next = new Node(d);
            temp = temp->next;
        }
        cin>>d;
    }
    return head;
}

void Node::printTree(Node* head){
    while(head != NULL){
        cout<<head->data<<" -> ";
        head = head->next;
    }
    cout<<"\n";
}

int main(){
    Node obj;
    Node* head = obj.buildLL();
    obj.printTree(head);
    return 0;
}