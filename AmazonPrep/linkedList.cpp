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
        next = nullptr;
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
        insertAtHead(head,arr[i]);
    }
    return head;
}
void printLL(Node* head){

    while(head){
        cout<<head->data<<" -> ";
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, arr[100005];
    cin>>n;
    ArrIn(n) cin>>arr[i];  
    Node* head = createList(arr,n);
    printLL(head);
    cin>>n;
    ArrIn(n) cin>>arr[i];
    Node* head2 = createList(arr,n);
    printLL(head2);
    Node* m = merge(head,head2);
    printLL(m);
    m = mergeSort(m);
    cout<<endl;
    printLL(m);
    int k = 4;
    Node* reverse = kReverse(m,k);
    cout<<reverse;
    return 0;
}    