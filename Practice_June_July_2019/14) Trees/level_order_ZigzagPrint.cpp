//Level Order Zig Zag 
#include<iostream>
#include "binary_trees_header.h"
#include<queue>
#include<stack>
using namespace std;
void printQueue(queue<node*> q1)
{   cout<<"QUEUE PRINT"<<endl;
    while(!q1.empty()&&q1.front()!=NULL)
    {
        cout<<q1.front()->data<<" ";
        q1.pop();
    }
    cout<<endl;
}
void level_orderZigZag(node*root)
{
    stack<node*> s1;
    queue<node*> q1;
    q1.push(root);
    q1.push(NULL);
    bool flag = false;
    while(!q1.empty())
    {   node*f;
         f = q1.front();
        q1.pop();
        if(f==NULL)
        {
            //flag value -
            //cout<<"NULL ENCOUNTERED "<<flag<<endl;
           flag = !flag;
            if(!q1.empty()) q1.push(NULL);
            //continue;
        }
        else if(flag)
        {    //printQueue(q1);
            s1.push(f);
            if(f->left!=NULL)
            {   
                q1.push(f->left);
            }
            if(f->right!=NULL)
            {
                q1.push(f->right);
            }
            //reverse print- next null
            while(q1.front()!=NULL)
            {
                node* val = q1.front();
                if(val->left!=NULL)
                {
                q1.push(val->left);
                }
                if(val->right!=NULL)
                {
                q1.push(val->right);
                }
                q1.pop();
            s1.push(val);
            }
            //printQueue(q1);
            //Empty the stack by printing
            while(!s1.empty())
            {
                cout<<s1.top()->data<<" ";
                s1.pop();
            }
        }

        //Else
        else
        {
            cout<<f->data<<" ";
            if(f->left!=NULL)
            {
                q1.push(f->left);
            }
            if(f->right!=NULL)
            {
                q1.push(f->right);
            }
            // printQueue(q1);
            // cout<<"L TO R "<<endl;
        }

    }
}
int main(int argc, char const *argv[])
{
    node*root =NULL;
    createTree(root,"true");
    level_orderZigZag(root);
    return 0;
}