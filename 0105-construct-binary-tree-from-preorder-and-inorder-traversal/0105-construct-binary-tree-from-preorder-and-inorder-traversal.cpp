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
 
   int findval(vector<int>& inorder , int value , int st , int end){
      for(int i = st ; i <= end ; i++){
        if(inorder[i] == value) return i ;
      }
      return -1;
   }

   TreeNode*  solve(vector<int>& preorder, vector<int>& inorder , int &i , int st , int end , int n){
    if(st>end || i>n) return NULL ;
    int value = preorder[i++] ;
    int pos = findval(inorder , value , st,end); 
    cout<<pos<<" ";
    TreeNode* root = new TreeNode(value);
    root->left = solve(preorder , inorder ,i , st , pos-1 , n);
    root->right = solve(preorder , inorder ,i , pos+1 , end  , n);
    return root ;
   }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i = 0 ;
        TreeNode* ans = solve(preorder , inorder ,i, 0 , inorder.size()-1 ,inorder.size()-1);
        return ans ;
    }
};