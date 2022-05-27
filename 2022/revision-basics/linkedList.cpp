// Linked List 
#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(){
        data = 0;
        next = NULL;
    }
    Node(int d){
        data = d;
        next = NULL;
    }
};

Node* createLL(int* arr,int n){
    Node* temp = NULL, *head = NULL;
    for(int i=0;i<n;i++){
        Node* newNode = new Node(arr[i]);
        if(temp == NULL){
            head = newNode;
            temp = newNode;
        }
        else{
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

void insertAtPosition(int pos,int d,Node*&head){
    // insert at head;
    Node* newNode = new Node(d);
    
    if(pos == 1){
        newNode -> next = head;
        head = newNode;
        return;
    }
    Node* curr = head, *prev = NULL;
    int count = 0;
    while(count+1<pos && curr){
        count++;
        prev = curr;
        curr = curr->next;
    }

    newNode -> next = curr;
    prev -> next = newNode;
}

void printLL(Node* head){
    while(head->next){
        cout<<head->data<<" -> ";
        head = head -> next;
    }
    cout<<head->data<<endl;
}

Node* mergeTwoSortedLL(Node* A, Node* B){
    if( A == NULL && B == NULL ) return NULL;
    else if( A == NULL) return B;
    else if( B == NULL) return A;

    if(A->data <= B -> data ){
        A->next = mergeTwoSortedLL(A->next,B);
        return A;
    } 
    else {
        B->next = mergeTwoSortedLL(A,B->next);
        return B;
    }
}

// Merge Sort 

Node* midpointLL(Node* head){
    if(head == NULL || head->next == NULL) return head;
    Node* fast = head->next, *slow = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* mergeSort(Node* A){
    // Base case -
    if( A == NULL || A->next == NULL) return A;

    Node* midpoint = midpointLL(A);

    // Break the linkedLL from midPoint;
    Node* nextNode = midpoint->next;
    midpoint->next = NULL;

    Node* sortedListLeft = mergeSort(A);
    Node* sortedListRight = mergeSort(nextNode);

    return mergeTwoSortedLL(sortedListLeft,sortedListRight);

}

// Reverse a Linked List -
Node* reverseIterative(Node* head){
    if( head == NULL || head ->next == NULL) return head;

    Node* prev = NULL ,*curr= head, *nextNode = head->next;

    while(curr){
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        if(!curr) break;
        nextNode = nextNode->next;
    }
    return prev;
}

// Recursion 
Node* reverseRecursion(Node* head){
    if( head == NULL || head->next == NULL) return head;

    Node* smallHead = reverseRecursion(head->next);
    head -> next ->next = head;
    head -> next = NULL;
    return smallHead;
}

// K - Reverse 

Node* kReverse(Node* head, int k)
{
    if( head == NULL || head ->next == NULL) return head;
        Node* curr = head;
        Node* prev = NULL;
        Node* nextNode = head->next;
        int count =0;
    while(curr && count<k){
        nextNode = curr -> next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        count++;
    }

    if(nextNode != NULL){
        head->next = kReverse(nextNode,k);
    }
    return prev;
}

int main(){
    Node* head = NULL;
    int n,arr[100];
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>arr[i];
    }
    head = createLL(arr,n);
    printLL(head);
    // int pos,key;
    // cout<<"Insert node at position and value ";
    // cin>>pos>>key;
    // insertAtPosition(pos,key,head);
    // printLL(head);
    // cout<<"Insert list 2 \n";
    // Node* head2 = NULL;
    // cin>>n;
    // for (int i = 0; i < n; ++i)
    // {
    //     cin>>arr[i];
    // }
    // head2 = createLL(arr,n);
    // printLL(head2);
    // Node* head3 = mergeTwoSortedLL(head,head2);
    // printLL(head3);
    Node* head4 = mergeSort(head);
    printLL(head4);
    Node* reverseHead = reverseIterative(head4);
    printLL(reverseHead);
    Node* reverseHead2 = reverseRecursion(reverseHead);
    printLL(reverseHead2);
    Node* kRev = kReverse(head4,3);
    printLL(kRev);
    return 0;
}