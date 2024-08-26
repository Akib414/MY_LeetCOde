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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans ;
        if(root == NULL) return ans ;
        queue<TreeNode*>q ;
        q.push(root);
        int flag = 0 ;
        while( !q.empty()){
            int size = q.size();
            flag++;
            vector<int>temp ;
            for(int i = 0 ; i < size ; i++){
                TreeNode* f = q.front();
                q.pop();
                temp.push_back(f->val);
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);     
            }
            if(flag%2 == 0){
             reverse(temp.begin() , temp.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};