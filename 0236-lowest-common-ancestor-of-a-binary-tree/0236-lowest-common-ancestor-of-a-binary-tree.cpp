/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       
       //here lowest means the first common ancestor ;

       if(root == NULL ) return NULL ;

       //check if it is p or q 
       //if it is p or q then there is no need to traverse further ;
       if(root == p || root == q){
        return root ;
       }
      TreeNode* lans = lowestCommonAncestor(root->left , p , q);
      TreeNode* rans = lowestCommonAncestor(root->right, p, q);
      //if for this current root both lans and rans not equal to NULL that means it is a ancestor root
    if(lans != NULL && rans != NULL) return root ;
    //if for the current root   rans is NULL then pass lans to the previous one 
    if(lans!= NULL && rans == NULL) return lans ;
    if(rans != NULL && lans == NULL) return rans ;
    else
    return NULL ;   
    }
};