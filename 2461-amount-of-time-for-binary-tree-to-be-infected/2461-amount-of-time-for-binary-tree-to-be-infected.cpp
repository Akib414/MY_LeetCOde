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
     TreeNode* map_parent_and_find_target(TreeNode* root, int start , unordered_map<TreeNode*,TreeNode*>&parent_access ){
        queue<TreeNode*>q ;
        q.push(root);
        
        //LEVEL ORDER ;
        parent_access[root] = NULL ; //root has no parent
        TreeNode* temp ;
        while(!q.empty()){
            int size = q.size();
            
            for(int i = 1 ; i <= size ; i++){
                TreeNode* f = q.front();
                q.pop();
                if(f->val == start) temp = f ;
                if(f->left){
                   parent_access[f->left] = f ;
                   q.push(f->left); 
                }
                if(f->right){
                      parent_access[f->right] = f ;
                   q.push(f->right); 
                }
            }
        }
        return temp ;

     }
 
    void solve( TreeNode* start_node , int &time ,  unordered_map<TreeNode*,TreeNode*>parent_access){
         unordered_map<TreeNode*,bool>visited ;
         queue<TreeNode*>q ;
         q.push(start_node);
         visited[start_node] = true ;

         while(!q.empty()){
            int size = q.size();
            bool flag = false;
            for(int i = 1 ; i <= size ; i++){
            
                TreeNode* f = q.front();
                q.pop();
                //if a Node is inserted in queue then time will increase
                if(f->left && visited[f->left] != true){
                    visited[f->left] = true ;
                    flag = true ;
                    q.push(f->left);
                }
                if(f->right && visited[f->right] != true){
                    visited[f->right] = true ;
                    flag = true ;
                    q.push(f->right);
                }
                if(parent_access[f] && visited[parent_access[f]] != true){
                    visited[parent_access[f]] = true ;
                    flag = true ;
                    q.push(parent_access[f]);
                }
               
            }
             if(flag) time++;

         }
    }

     

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>parent_access ;//create a map of parent with child ;
        
        TreeNode* start_node = map_parent_and_find_target(root , start ,parent_access );

        int time = 0 ;

        solve(start_node , time , parent_access);
        return time ;

    }
};