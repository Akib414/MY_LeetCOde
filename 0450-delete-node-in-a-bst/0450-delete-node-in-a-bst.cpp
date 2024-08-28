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
    int findmin(TreeNode* root){
        if(root->left == NULL) return root->val ;
        return findmin(root->left);
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL ;
        if(key > root->val){
            root->right = deleteNode(root->right , key);
            return root ;
        }
        else if(key < root->val){
            root->left = deleteNode(root->left , key);
            return root ;
        }
        else{
        //if both sides dosent exist ;
            if(root->left == NULL && root->right == NULL){
            delete root ;
            return NULL ;
            }
        //if one side exist then store that side and delete parent and return child ;
            else if(root ->left != NULL && root->right == NULL){
                TreeNode* temp = root->left ;
                delete root ;
                return temp ;
            }
            else if(root ->right != NULL && root->left == NULL){
                TreeNode* temp = root->right ;
                delete root ;
                return temp ;
            }
            //if both side exists 
            //either find max in the left side 
            //or min in the right side 
            //here max in the right side 
            else{
              int min_from_right = findmin(root->right) ;
              root->val = min_from_right ;
              root->right = deleteNode(root->right , min_from_right );
              return root ;
            }
        }
        
    }
};


/*********************************************************************************************************************************************************************/
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL ;

        if(key > root->val){
            root->right = deleteNode(root->right , key) ;
            return root ;
        }

        else if(key < root->val){
            root->left =deleteNode(root->left , key);
            return root ;
        }
        else{

           if(root->left == NULL && root->right == NULL){
            delete root ;
            return NULL ;
           }

           else if(root->left && root->right == NULL ){
            TreeNode* temp = root->left ;
            delete root ;
            return temp ;
           }

           else if(root->right && root->left == NULL){
            TreeNode* temp = root->right ;
            delete root ;
            return temp ;
           }

           else{
             TreeNode* max_in_left = root->left;
             while(max_in_left->right != NULL)
                max_in_left = max_in_left->right ;
        
             int temp = root->val ;
             root->val = max_in_left->val ;
             max_in_left->val = temp ;
             root->left = deleteNode(root->left , key);
             return root ;  
           }
        }
        
         return root ;  
    }
};
