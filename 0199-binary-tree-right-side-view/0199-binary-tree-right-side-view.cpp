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
   
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans ;
        if(root == NULL) return ans ;
        queue<TreeNode*>q ;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0 ; i < sz ; i++){
                TreeNode* f ;
                f = q.front() ;
                q.pop();
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
                if( i == sz-1) ans.push_back(f->val);
            }        
        }
        return ans ;
    }
};