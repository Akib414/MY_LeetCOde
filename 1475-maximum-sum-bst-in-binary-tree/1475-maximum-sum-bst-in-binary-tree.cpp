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
    class info{
        //these are the four things we need to keep track of
     public:
     //if val is less than left side maximum then it is not bst  
     int maximum ;
     //if val is more than right side minimum then it is not bst ;
     int minimum ;
     int sum ;
     //if both side is note true than it is not bst 
     bool flag ;
    };

   
   info solve(TreeNode* root ,int &max_sum_bst ){
    if(root == NULL){
        //first time maximum is INTMIN , minimum is INT_MAX , sum is 0 , and flag is true 
        return {INT_MIN , INT_MAX , 0 , true};
    }
    info lft = solve(root->left , max_sum_bst);
    info rgt = solve(root->right , max_sum_bst);
    info to_return;
    //new maximum will be maximum from right 
    to_return.maximum = max(root->val ,rgt.maximum);

    //new minimum will be minimum from left ;
    to_return.minimum = min(root->val , lft.minimum);

    //sum will be left + right + main
    to_return.sum = lft.sum + rgt.sum + root->val ;

    // is both left and right is true and main is less than the minimum from right && main is greater than the maximum from left it is bst .
    if(lft.flag && rgt.flag && (root->val < rgt.minimum && root->val > lft.maximum))
    to_return.flag = true ;
    else
    to_return.flag = false ; 


    //if only main is possible bst then it will upgrade max_sum_bst 
    //if it is false and sum is being increased dosent matter
    //as it is false in the down side , no matter how up we go on the tree , it will be false
    //and if it is false then the sum keep being increased will not bother as it will not be upgraded if if its false
    if(to_return.flag)
    max_sum_bst = max(max_sum_bst , to_return.sum);


    return to_return ;
   }

    int maxSumBST(TreeNode* root) {
        int max_sum_bst = 0;
        info ans = solve(root , max_sum_bst);
        return max_sum_bst ;
  
    }
};