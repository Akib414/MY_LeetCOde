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
       void create_column(int column ,  TreeNode* root, unordered_map<TreeNode*,int>&p ) {
        if(root == NULL){
            return ;
        }
        p[root] = column ;
        create_column(column-1 , root->left , p);
        create_column(column+1 , root->right , p);
    }
    void create_vectors(TreeNode* root , map<int,vector<int>>&m , unordered_map<TreeNode*,int> p){
        if(root == NULL) return ;
        queue<TreeNode*>q ;
        q.push(root) ;
        while(!q.empty()){
            int size = q.size();
            map<int,vector<int>> pm ;
            for(int i = 0 ; i < size ; i++){
            TreeNode* f = q.front();
            pm[p[f]].push_back(f->val);  
            q.pop();
            if(f->left) q.push(f->left);
            if(f->right) q.push(f->right);
            }
            for(auto a : pm){
                if(a.second.size() > 1){
                    sort(a.second.begin(),a.second.end());
                }
                for(auto b : a.second){
                    m[a.first].push_back(b);
                }
            }
        }
    }
    

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<TreeNode*,int> p ;
        //firstly map column number with respect to node on overy node ;
        create_column(0 , root , p);
        //then create a map according to column number's vector 
        map<int,vector<int>>m ;
        create_vectors(root, m , p) ;
        vector<vector<int>>ans ;
        for(auto a : m){
            vector<int>temp ;
            for(auto b : a.second){
                temp.push_back(b);
            }
            ans.push_back(temp);
        }
        return ans ;
    }
};