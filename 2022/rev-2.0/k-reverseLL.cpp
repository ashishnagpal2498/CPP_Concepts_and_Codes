// Linked List 
// K-reverse ->

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        data = d;
        next =NULL;
    }
};
Node* createLL(){
        cout<<"Enter node Val \n";
        int d;
        cin>>d;
        Node* head = NULL;
        Node* temp = head;
        
        while(d!=-1){
            if(head == NULL) {
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
void printLL(Node* head){
    cout<<"Print LinkedList\n";
    while(head !=NULL){
        cout<<head->data<<" -> ";
        head = head->next;
    }
    cout<<endl;
}

int lengthLL(Node* head){
    int count =0;
    while(head,count++,head=head->next);
    return count;
}

Node* kreverse(Node* head, int k){
    if(head == NULL || head->next == NULL) return head;
    static int len = lengthLL(head);
    k = k%len;

    Node* prev = NULL, *curr = head, *nextNode = NULL;
    int count = 0;
    while(curr && count<k){
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        count++;
    }
    if(nextNode){
        head->next = kreverse(curr,k);
    }
    return prev;
}

int main(){
    Node* head = createLL();
    printLL(head);
    cout<<"Length of LL -> "<<lengthLL(head);
    cout<<"K - reverse enter k value";
    int k;
    cin>>k;
    head = kreverse(head,k);
    printLL(head);

}