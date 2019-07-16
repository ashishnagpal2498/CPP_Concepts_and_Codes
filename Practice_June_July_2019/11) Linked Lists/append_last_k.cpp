//Append Last K elements-
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
void addAtTail(node*&head,int d)
{
    if(head==NULL)
    {
        head = new node(d);
        return;
    }
    node*temp=head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    node* n = new node(d);
    temp->next = n;
    return;
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
void createLL(node*&head,int n)
{   int d;
    for(int i=0;i<n;i++)
    {
        cin>>d;
        addAtTail(head,d);
    }

}
node* k_append(node*head,int n,int k)
{   if(k==0)
    {
        return head;
    }
    int op = n-k -1;
    int i=0;
    node* temp = head;
    while(i<op)
    {
        temp=temp->next;
        i++;
    }
    node* last = temp->next;
    node* copy_last = last;
    temp->next=NULL;
    //Now traverse the last to end
    while(last->next!=NULL)
    {
        last=last->next;
    }
    last->next = head;
    return copy_last;
}

int main(int argc, char const *argv[])
{
    node* head =NULL;
    int n;
    cin>>n;
    int k;
    createLL(head,n);
    cin>>k;
    printLL(head);
    k =k%n;
    head = k_append(head,n,k);
    cout<<endl;
    printLL(head);
    return 0;
}