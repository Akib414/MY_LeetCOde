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
    
    int findin(vector<int>& inorder , int s , int e , int key){
        for(int j = s ; j <= e ; j++)
        if(inorder[j] == key) return j ;
        return -1;
    }

   TreeNode* solve(vector<int>& inorder, vector<int>& postorder ,int &i , int start , int end){
    if(i < 0 || start >end) return NULL ;
    int key = postorder[i--];
    int pos = findin(inorder,start,end,key);
    TreeNode* root = new TreeNode(key);
    root->right = solve(inorder , postorder , i , pos+1 ,end );
    root->left = solve(inorder , postorder , i , start , pos-1);
    return root ;
   }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int i = inorder.size()-1;
        TreeNode* root = solve(inorder , postorder , i , 0 , i);
        return root ;
    }
};