// Leetcode LeftTree sum
#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define ArrIn(n) for(int i=0;i<n;i++)
#define ArrOut for(int i=0;i<n;i++) {cout<<arr[i]<<" "; }
#define mod 1e9+7
using namespace std;
ll t,n;
ll arr[200005];
class myPair{
  public:
    int leftLeave;
    int rightLeave;
    myPair(){
        leftLeave = rightLeave = 0;
    }
};
myPair sumLeft(TreeNode* root,char v){
        myPair ans;
         
        if(root == NULL) return ans;
        if(root->left == NULL && root->right == NULL){
            if(v == 'l') ans.leftLeave = root->val;
            return ans;
        }
        myPair leftTree = sumLeft(root->left,'l');
        myPair rightTree = sumLeft(root->right,'r');
        
        ans.leftLeave = leftTree.leftLeave + rightTree.leftLeave;
        return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
        
    return 0;
}    