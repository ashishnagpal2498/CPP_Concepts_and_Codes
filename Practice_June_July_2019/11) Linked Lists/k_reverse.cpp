//K- reverse Linked List 
#include<iostream>
using namespace std;
class node{
public:
    int data;
    node*next;
    node(int d)
    {
        data =d ;
        next = NULL;
    }

};
void addAtTail(node*&head,int d)
{
    if(head==NULL)
    {
        head = new node(d);
        return;
    }
    node*temp = head;
    while(temp->next!=NULL)
    {
        temp= temp->next;
    }
    node*n = new node(d);
    temp->next = n;
    return;
}
void createLL(node*&head,int n)
{
    int d;
    //cin>>d;
    int i=0;
    while(i<n)
    {   cin>>d;
        addAtTail(head,d);
        i++;
    }
}
void printLL(node*head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head= head->next;
    }
}
int main(int argc, char const *argv[])
{
    node*head = NULL;
    int n;
    cin>>n;
    createLL(head,n);
    printLL(head);
    return 0;
}