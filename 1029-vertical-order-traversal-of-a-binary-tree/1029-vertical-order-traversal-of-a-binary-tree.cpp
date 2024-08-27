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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        map<TreeNode*,int>col ;
        map<int,vector<int>> m;
        queue<TreeNode*>q ;
        q.push(root);
        col[root] = 0;
        
        while(!q.empty()){
          int size = q.size();
          map<int,vector<int>>temp ;
          for(int j = 0 ; j < size ; j++){
          TreeNode* f; 
          f = q.front();
            q.pop();
            temp[col[f]].push_back(f->val);
            if(f->left){
                q.push(f->left);
                int f_col = col[f];
                col[f->left] = f_col - 1 ;
            }
            if(f->right){
                q.push(f->right);
                int f_col = col[f];
                col[f->right] = f_col + 1 ;
            }  
        }
        for(auto a : temp){
            if(a.second.size() > 1) sort(a.second.begin() , a.second.end());
            for(auto b : a.second){
                m[a.first].push_back(b);
            }
        }
        }
        for(auto a : m){
         ans.push_back(a.second);
        }
        return ans;
    }
};