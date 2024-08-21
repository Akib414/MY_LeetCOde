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
         queue<TreeNode*>q;
         q.push(root);
         bool flag = true ;
         while(!q.empty()){
             int size = q.size();
              vector<int>arr(size);
            for(int i = 0 ; i < size ; i++){       
               int index = flag ? i : size-i-1;
                     
               TreeNode* temp = q.front();
                q.pop();
                arr[index]= temp->val; 
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ans.push_back(arr);
            if(flag)
            flag = false;
            else
            flag = true ;
         }
         return ans ;
    }
};