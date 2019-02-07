//revision continued 29th Jan 
#include<iostream>
using namespace std;
class abc{
    int a;
public:
    void change_a(int n)
    {
        a = n;
    }
    int access_a()
    {   cout<<this<<endl;
        return this->a;
    }

};

//Linked List - Data Structure - Value and pointer to next node;
// Head se saara access hota hai data -
// 1) Length of linked list 
// 2) Delete the node - Free the memory from heap as dynamic memory allocation
// 3) Mid - point - Length nikalo and divide it by 2 || - Other way is to take two pointers
// 1 ko twice speed se run kiya , Abiguity remove - fast ptr next to head 
// 4) Merge 2 sorted LL Node * head - if data < a toh a wala chipka do and call from a->next
// 5) Sort the linked list using merge sort - //Preferable , linear search 
//6) Reverse a linked list - recursion ka kaam baad mein hota hai, 
//  7) Check , if there is a cycle in linked list or not - FAST SLOW CONCEPT
// 8) Floyd Warshal Cycle detection method - 
//  

//Generic Classes - using - template <typname> - 
//Stacks - 
// LIFO - technique - last in first out , 
// Top element - push , pop , isempty , top , 
// Reverse a stack - using two stacks or using a call stack ;
//Balanced Paranthesis - saare jo opening bracket hai , put those onto stack
//closing bracket - pop if stack top uska opening hai - 
//return the emptyness of stack 
//Redundant paranthesis

//Randomised quick sort - srand function
// 

// Queues - FIFO technique 
//Stack using two queues - active stack - push aata hai to karte jao 
//when the pop comes - doosre stack mein transfer - pop the last element
//

template <typename T>

T concatnate(T a , T b)
{
        return a+b;

}

//Trees -
//1) Generic
//2) Binary Tree 
//3) BST
// if the data input is -1 then , that child doesn't exist 
// PreOrder Traversal - root , call the left subtree and then right subtree
//Level order printing - using Queue - 
//Count the number of nodes in a binary tree - 
// Level - order input - 
//Diameter - 3 cases - either left subtree ke andar ho diamter or / passing through
//root node or right subtree
// O(n^2) - Height , option 2 = left tree or option 3 = right tree
// O(n) - Post order traversal - left tree height and diameter , 

//Generic trees - nchild and array - N utne size ka array children 
// Generic tree always uses loop - we dont know kitne child hai kisi node ke

//Important - NOTE - To include all header files - bits/stdc++.h 


//BST - Binary search tree -
//We create tree using our logic - if the node is greater than root node - right
//else - left
//if null create the node and return that node;
// Searching - in BST - if the node is greater than root node- 
//Go to right - , varna left par - search kr -
// O(height) - Time complexity of the searching

//Balanced tree - A tree is said to be a balanced tree , if - Node se 
//left tree and right tree ki height is - | <=1 | 
//Post order approach - 
//If a tree is balanced tree - HEIGHT - log 2(n) HOGI - 

//CATALAN NUMBER - NO. OF BSTs

//Deletion in BST - either a tree can have
//0 children - leave node
//1 child - Replace that node with the previous node , free the memory
//2 child - find the min element in right tree or , max element in left tree
// Replace that with root and delete that node recursively

//Create a balanced BST using a sorted array 
//Mid point - nikala - left part m-1;
// right part will be mid+1;

//Check if the tree is BST or not -
// To check that - Use the upper bound and lower bound of the node
//if the root node is < upper bound , root node > lower bound 
//SET - left UB - root , right LB - root 
//recursively check and return true

//Flattening the BST- Converting a BST into a linked list

class Linkedlist {
    public:
    node * head;
    node* tail;
    Linkedlist()
    {
        head = tail = NULL;
    }
};

Linkedlist tree_2_LL(node* root)
{
    Linkedlist p;
    if(root ==NULL)
    {  
        return p;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        p.head = root;
        p.tail = root;
        return p;
    }
    else if(root->left!=NULL&&root->right==NULL)
    {
        Linkedlist left_tree_lekr_aa = tree_2_LL(root->left);

        p.head = left_tree_lekr_aa.head;
        left_tree_lekr_aa.tail->right = root;
        p.tail = root;
        return p;
    }
    else if(root->left==NULL&&root->right!=NULL)
    {
        Linkedlist right_tree_laa = tree_2_LL(root->right);

        p.head = root;
        root->right = right_tree_laa.head;
        p.tail = right_tree_laa.tail;
        return p;
    }
    else{
        Linkedlist left_tree = tree_2_LL(root->left);
        Linkedlist right_tree = tree_2_LL(root->right);

        p.head = left_tree.head;
        left_tree.tail->right = root;
        root->right = right_tree.head;
        p.tail = right_tree.tail;
        return p;
    }
}


int main()
{
    int n;
    cin>>n;
    abc obj1;
    obj1.change_a(n);
    cout<<obj1.access_a()<<endl;
    abc obj2;
    obj2.change_a(8);
    cout<<obj2.access_a()<<endl;
    string ab = "abc",de = "def";
    cout<<concatnate(ab,de);
    return 0;
}