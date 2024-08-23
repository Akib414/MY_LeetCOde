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
      int findin(vector<int>& inorder , int element ,int instart , int inend){
        for(int i = instart ; i <= inend ; i++){
            if(inorder[i] == element) return i ;
        }
        return -1;
      }
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder ,int &prestart,int preend,int instart, int inend,  unordered_map<int,int> m){
        if(prestart > preend) return NULL ;
        if(instart>inend) return NULL ;
        int element = preorder[prestart++];
        TreeNode* root = new TreeNode(element);
        int index = findin(inorder , element,instart , inend);
        
        TreeNode* lft = solve(preorder , inorder , prestart , preend , instart , index-1 , m) ;
        TreeNode* rgt = solve(preorder , inorder , prestart , preend , index+1 , inend , m) ;
        root->left = lft ;
        root->right = rgt ;
        return root ;

     }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       int prestart = 0 ;
       int preend = preorder.size()-1 ;
       int instart = 0 ;
       int inend = inorder.size()-1;
       unordered_map<int,int> m ;
    //    for(int i = 0 ; i <= inend ; i++)
    //    m[inorder[i]] = i ;
       TreeNode* ans = solve(preorder , inorder , prestart , preend , instart , inend , m);
       return ans ;
    }
};