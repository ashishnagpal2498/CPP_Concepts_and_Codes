//HackerRank Trees Questions
/* class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
}; */

 void preOrder(Node *root) {
        if(root==NULL) return;
        cout<<root->data;<<" ";
        preOrder(root->left);
        preOrder(root->right);   
    }

    // Inorder Traversal
     void inOrder(Node *root) {
        if(root==NULL) return;

        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
    // Post order Traversal
     void postOrder(Node *root) {
        if(root==NULL) return;

        postOrder(root->left);
        postOrder(root->right);
        cout<<root->data<<" ";
    }

    // Height of binary Tree
     int height(Node* root) {
        // Write your code here.
        //single node - with no child
        if(root==NULL||(root->left==NULL&&root->right==NULL)) return 0;

    
        int right_tree_height = height(root->right);
        int left_tree_height = height(root->left);

        return 1 + max(right_tree_height,left_tree_height);
    }

    // Level - order print
     void levelOrder(Node * root) {

        if(root==NULL) return;
        queue<node*> q1;
        q1.push(root);
        while(!q1.empty())
        {
            node* front_val = q1.front();
            q1.pop();
            if(front_val->left!=NULL)
            {
                q1.push(front_val->left);
            }
            if(front_val->right!=NULL)
            {
                q1.push(front_val->right);
            }
            cout<<front_val->data<<" ";
        }

    }

    // Top view
     void topView(Node * root) {
        static bool flag = false;
        static int r_data = root->data;
        if(root==NULL) return;

        if(!flag)
        {   cout<<root->data<<" ";
            topView(root->left);
        //reached till leftmost node,
        
            if(root->data!=r_data)
            {
                return;
            }
            else{
                flag = true;
               // cout<<root->data<<" ";
                topView(root->right);
            }
        }
        else{
            cout<<root->data<<" ";
        topView(root->right);
        
        }
    }