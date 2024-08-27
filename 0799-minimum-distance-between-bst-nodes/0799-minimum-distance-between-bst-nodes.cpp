/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   int maxleft(TreeNode* root){
    if(root->right == NULL) return root->val ;
    return maxleft(root->right);
   }

   int minright (TreeNode* root){
    if(root->left == NULL) return root->val ;
    return minright(root->left);
   }


    void solve(TreeNode* root , int &mini){
        if(root == NULL) return  ;
        solve(root->left,mini);
        solve(root->right,mini);

       //AS IN BST THE MAXIMUM IN LEFT IS THE CLOSEST VALUE TO THE ROOT VALUE 
       
        if(root->left) {
            int maximum_in_left = maxleft(root->left);
            mini= min(mini , abs(root->val - maximum_in_left));
        }

       // AS IN BST THE MINIMUM IN RIGHT IS THE CLOSEST VALUE TO THE ROOT VALUE 
        if(root->right){
        int minimum_in_right = minright(root->right);
        mini = min(mini , abs(root->val - minimum_in_right));
        }
    }


    int minDiffInBST(TreeNode* root) {
        int mini = INT_MAX ;
       solve(root , mini);
        return mini ;
    }
};


/*******************************ANOTHER PROCESS USING THE INORDER TRAVERSAL PROPERTY(STORES THE BST IN SORTED ORDER) ************************/
class Solution {
public:
    void inorder(TreeNode* root,vector<int> &v){
        if(root==NULL){
            return;
        }
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int> v;
        inorder(root,v);
        int mini=INT_MAX;
        for(int i=0;i<v.size()-1;i++){
            mini=min(mini,v[i+1]-v[i]);
        }
        return mini;
    }
};






