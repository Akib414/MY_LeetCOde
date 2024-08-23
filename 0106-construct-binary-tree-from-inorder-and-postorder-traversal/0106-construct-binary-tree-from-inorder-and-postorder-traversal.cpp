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
        
     TreeNode* solve(vector<int>& inorder, vector<int>& postorder ,int start ,int end , int &index , unordered_map<int,int>&m){
        if((index < 0 && index < inorder.size()) || start > end) return NULL ;
        int element = postorder[index--];
        int pos = m[element];
        TreeNode* root = new TreeNode(element);
        root->right = solve(inorder,postorder,pos+1,end,index,m);
        root->left = solve(inorder,postorder,start,pos-1,index,m);

        return root;
     }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //in postorder the last one is the parent , so its left right parent ;
        //in inorder left parent right 
        //find the parent in inordered . use map for this 
        unordered_map<int,int>m;
        for(int i = inorder.size()-1 ; i>=0 ; i--){
            m[inorder[i]] = i ;
        }
        int index = inorder.size()-1;
       return solve(inorder,postorder,0,inorder.size()-1,index,m);
    }
};  