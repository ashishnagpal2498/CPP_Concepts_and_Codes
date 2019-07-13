//linked lists - Basics 
#include<iostream>
using namespace std;
class node{
public:
    int data;
    node*next;
    node(int d)
    {
        data = d;
        next = NULL;
    }
    
};
void printLL(node*head)
    {   //node*head = this;
        while(head!=NULL)
        {
            cout<<head->data<<" ";
            head = head ->next;
        }
    }
void addAtHead(node*&head,int d)
{
    if(head==NULL)
    {
        head = new node(d);
        return;
    }
    node* temp = head;
    head = new node(d);
    head->next = temp;
    return;

}
void createLL(node*&head)
{   int d;
    cin>>d;
    while(d!=-1)
    {
        addAtHead(head,d);
        cin>>d;
    }

}
ostream& operator<<(ostream&ob,node*head)
{
    printLL(head);
    return ob;
}
istream& operator>>(istream&in,node*&head)
{
    createLL(head);
    return in;
}
void insertAtPposition(node*&head,int data,int p)
{
    if(p==0)
    {
        addAtHead(head,data);
        return;
    }
    node* temp = head;
    int cnt = 1;
    while(cnt<=p-1)
    {
        cnt++;
        temp = temp->next;
    }
    node* n = new node(data);
    n->next = temp->next;
    temp ->next = n;
    return;
}
node* searchElement(node*head,int key)
{
    if(head==NULL)
    {
            return NULL;
    }
    if(head->data==key)
    {
        return head;
    }
    return searchElement(head->next,key);
}
node* midPoint(node*head)
{
    node* slow = head;
    node* fast = head->next;
    while(fast!=NULL&&fast->next!=NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node* mergeLL(node*a,node*b)
{
    if(a==NULL)
    {
        return b;
    }
    if(b==NULL)
    {
        return a;
    }
    node *c;
    if(a->data<b->data)
    {
        c = a;
        c->next = mergeLL(a->next,b);
    }
    else
    {
        c = b;
        c->next = mergeLL(a,b->next);
    }
    return c;
}
node* mergeSort(node*head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    //Calculate Mid -
    node* m = midPoint(head);
    node* a = head;
    node* b = m->next;
    m->next = NULL;

    a = mergeSort(a);
    b = mergeSort(b);
    return mergeLL(a,b);
}
void reverseLL_Iteration(node*&head)
{
    if(head==NULL||head->next==NULL) return;

    node *prev,*nxt,*cur;
    prev = NULL; cur = head;
    while(cur!=NULL)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    head = prev;
}
node* reverseLL_Recursion(node*head)
{
    if(head==NULL||head->next==NULL)
    {
        return head;
    }
    node* nhead = reverseLL_Recursion(head->next);
    head->next->next = head;
    head->next = NULL;
    return nhead;
}
int main()
{
    node*head = NULL;
    // createLL(head);
    // cin>>head;
    // cout<<head<<endl;
    // int n;
    // cout<<"Enter the position  ";
    // cin>>n;
    // int d;
    // cout<<"Enter Data  "; cin>>d;
    // insertAtPposition(head,d,n);

    // cout<<endl<<head;
    // int key;
    // cout<<endl<<"ENTER ELEMENT TO BE SEARCHED  ";
    // cin>>key;
    // node* search = searchElement(head,key);
    // cout<<endl<<"MID POINT of LL "<<(*midPoint(head)).data<<endl;
    // node*head2 = NULL;
    // node* ans = NULL;
    cin>>head;
    cout<<head<<endl; //<<head2<<endl;
    head = mergeSort(head);

    cout<<head<<endl;
    cout<<"REVERSE IS  ";
    reverseLL_Iteration(head);
    cout<<head<<endl;
    cout<<"RECURSIVE REVERSE "<<endl;
    head = reverseLL_Recursion(head);
    cout<<head<<endl;
    return 0;
}