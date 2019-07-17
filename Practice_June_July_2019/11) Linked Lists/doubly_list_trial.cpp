//Doubly_list
#include<iostream>
using namespace std;
class node{
public:
    int data;
    node*next;
    node*prev;
    node(int d)
    {
        next = NULL;
        prev = NULL;
        data = d;
    }
};
void addTail(node*&head,int d)
{
    if(head==NULL)
    {
        head = new node(d);
        return;
    }
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    node* n = new node(d);
    temp ->next = n;
    n->prev = temp;
    return;
}
void createLL(node*&head,int n)
{
    int i=0;
    int d;
    while(i<n)
    {
        cin>>d;
        addTail(head,d);
        i++;
    }
}
void printLL(node* head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
void insertAtPosition(node*&head,int data,int pos)
{
    if(pos==0)
    {
        //head par insert karna hai;
        node* temp =head;
        node* n = new node(data);
        temp ->prev = n;
        n->next = temp;
        head = n;
        return;
    }
    //1 pichhe position wait -
    int l=0;
    node* temp = head;
    while(l<pos-1)
    {
        temp = temp->next;
        l++;
    }
    node* n = new node(data);
    node* nextNode = temp->next;
    nextNode->prev = n;
    temp->next = n;
    n->prev = temp;
    n->next = nextNode;
    return;
}
void printPrev(node* head)
{
    while(head->next!=NULL)
    {
        head=head->next;
    }
    cout<<endl;
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head= head->prev;
    }
}
void insertion_sort(node*&head,int n)
{
    if(head==NULL||head->next==NULL)
        return ;

    for(int i=2;i<=n;i++)
    {
        int j=i;
        node*temp = head;
        //first go to that node;
        //node*head2 = head;
        int pos=0;
        while(j>1)
        {
            temp=temp->next;
            j--;
            pos++;
        }
        //cout<<"Element to be placed "<<temp->data<<endl;
        //make place for correct position
        node* temp2=temp->prev;
        int actual_pos =pos;
        while(temp2!=NULL&&temp->data<temp2->data)
        {
            pos--;
            temp2=temp2 ->prev;    
        }
        //cout<<"Correct Position "<<pos<<endl;
        //printLL(head);
        if(actual_pos!=pos)
        {   //cout<<"Inerting at Correct position - NODE  "<<temp->data<<endl;
            //printPrev(head);
            node* prevNode = temp->prev;
            node*nextNode;
        //    cout<<i<<endl;
            if(i==n)
            {
                nextNode = NULL;
            }
            else
            {
                nextNode = temp->next;
                 nextNode->prev = prevNode;
            }
            prevNode->next = nextNode;
           
            node* waste = temp;
            // cout<<"PREV TEMP AND NEXT "<<prevNode->data<<"  "<<temp->data<<"  "<<nextNode->data;
            // cout<<"Printing inside ------ "<<endl;
            //printLL(head);
            insertAtPosition(head,temp->data,pos);
            delete waste;
        }
        
    }
}
int main()
{
    node* head = NULL;
    int n;
    cin>>n;
    createLL(head,n);
    // printLL(head);
     insertion_sort(head,n);
    //printPrev(head);
    printLL(head);
    return 0;
}