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

    void solve(TreeNode* root, int targetsum , vector<int>&store, int &count){
        if(root == NULL) return ;
        store.push_back(root->val) ;
        solve(root->left ,targetsum , store , count);
        solve(root->right ,targetsum , store , count);
        long long int sum = 0 ;
        for(int i = store.size()-1 ; i >= 0 ; i--){
            sum+= store[i];
            if(sum == targetsum) count++ ;
        } 
        store.pop_back();       
    }

    int pathSum(TreeNode* root, int targetsum) {
        vector<int>store ;
        int count = 0 ;
        solve(root , targetsum , store , count);
        return count ;
    }
};