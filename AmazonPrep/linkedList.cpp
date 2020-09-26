// Linked List
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int d){
        data = d;
        next = NULL;
    }
};
void insertAtHead(Node* &head,int d){
    if(head == NULL){
        head = new Node(d);
        return;
    }
    Node* newNode = new Node(d);
    newNode->next = head;
    head = newNode;
}
void insertAtTail(Node*&head,int d){
    if(head==NULL){
        head = new Node(d);
        return;
    }
    Node* curr= head;
    while(curr->next){
        curr = curr->next;
    }
    curr-> next = new Node(d);
    return;
}
Node* createList(ll* arr, ll n){
    Node* head= NULL;
    for(int i=0;i<n;i++){
        insertAtTail(head,arr[i]);
    }
    return head;
}
void printLL(Node* head){

    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"\n";
}
Node* midPoint(Node* head){
    Node* slow = head,*fast = head->next;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast= fast->next->next;
    }
    return slow;
}
Node* merge(Node* &a, Node* &b){
    // cout<<a->data<<" -> "<<b->data<<endl;
    if(a==nullptr) return b;

    if(b== nullptr) return a;

    Node* c;
    if(a->data < b->data){
        c = a;
        c->next = merge(a->next,b);
    }
    else {
        c = b;
        c->next = merge(a,b->next);
    }
    return c;
}
Node* mergeSort(Node* head){
    // cout<<"Here -> "<<endl;
    if(head == NULL || head->next == NULL) return head;
    Node* midPt = midPoint(head);
    // cout<<midPt->data<<endl;
    Node* a = head;
    Node* b = midPt->next;
    midPt -> next = NULL;
    a = mergeSort(a);
    b = mergeSort(b);
    return merge(a,b);
}
Node* kReverse(Node* head,int k){
    if(head == NULL || head->next == NULL) return head;

    Node* nxt,*prev=NULL,*curr = head;
    int cnt=0;
    while(cnt<k && curr){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        cnt++;
    }
    if(nxt != NULL){
        head->next = kReverse(nxt,k);
    }
    return prev;
}
ostream& operator<<(ostream &ob, Node*&head){
    printLL(head);
    return ob;
}
// istream& operator>>(istream & in,Node* &head){
//     return in;
// }
void oddEven(Node* &head,int n){
    Node* temp = head;
    Node* prev = NULL;
    int i=0;
    while(temp && i<n){
        i++;
        if(temp->data&1){
            if(temp == head){
                cout<<"Odd head \n";
              prev = temp;
              temp = temp->next;  
            } 
            else{
                cout<<"Odd val"<<endl;
                Node* nxt = temp->next;
                prev->next = nxt;
                insertAtHead(head,temp->data);
                delete temp;
                temp = nxt; 
            }
        }
        else{
            if(temp == head){
                // prev will be null only;
                cout<<"Even head"<<endl;
                Node* nxt = temp->next;
                head = nxt;
                insertAtTail(head,temp->data);
                // ->
                
                delete temp;
                temp = nxt;
            }
            else{
                cout<<"Even Val"<<endl;
                Node* nxt = temp->next;
                prev->next = nxt;
                insertAtTail(head,temp->data);
                delete temp;
                temp = nxt;
            }
        }
    }
}
void oddEven2(Node* &head){
    if(head == NULL) return;
    Node* temp = head;
    // If value is odd -> skip till we find an even value
    if(temp->data&1){
        // cout<<"Here"<<endl;
        while(temp && temp->next && (temp->next->data&1)) temp= temp->next;
    }
    // If value is even -> skip till we find odd value
    else
    while(temp && temp->next && !(temp->next->data&1))    temp = temp->next;
    
    Node* nxt,*prev;
    
    if(temp && temp->next == NULL) {
    // cout<<"Return ->"<<endl;
    return; // all numbers are even or odd ->

}
    else if(!(head->data&1))
    {   nxt = temp->next;
        temp->next = nxt->next;
        nxt->next = head;
    // New head will now be odd value ->
        head = nxt;
    }
    Node* oddHead = head;
    // Previous value ->
    // Temp will stop on even value -> 
    // Even head -> temp 

    prev = temp;
    temp= temp->next;
    while(temp){
        if(temp->data&1){
            prev->next = temp->next;
            nxt = oddHead->next;
            // 1 1 
            oddHead->next = temp;
            temp->next = nxt;
            temp = prev->next;
        }
        else{
            prev = temp;
            temp = temp->next;
        }
    }
}
// Delete Node from Linked List Not given header
void DeleteNode(Node* node){
    node->data =node->next->data;
    Node* waste = node;
    node->next = node->next->next;
    delete waste;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    ll n, arr[100005];
    // cin>>n;
    // ArrIn(n) cin>>arr[i];  
    // Node* head = createList(arr,n);
    // printLL(head);
    // cin>>n;
    // ArrIn(n) cin>>arr[i];
    // Node* head2 = createList(arr,n);
    // printLL(head2);
    // Node* m = merge(head,head2);
    // printLL(m);
    // m = mergeSort(m);
    // cout<<endl;
    // printLL(m);
    // int k = 4;
    // Node* reverse = kReverse(m,k);
    // cout<<reverse;
    cin>>n;
    ArrIn(n) cin>>arr[i];
    Node* head = createList(arr,n);
    // cout<<head<<endl;
    // oddEven(head,n);
    // cout<<head<<endl;
    // 1 2 5 6 8 3 -> 3,5,1,2,6,8
    oddEven2(head);
    cout<<head;
    // 1->3->5->2->6->8
    return 0;
}    