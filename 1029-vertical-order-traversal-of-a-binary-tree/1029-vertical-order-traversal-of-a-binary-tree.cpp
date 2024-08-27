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

        
    //declare the return type 
    vector<vector<int>>ans;

    //create a map to store the column number of every node
    map<TreeNode*,int>col ;

    //create a map to store the vector of each column
    map<int,vector<int>> m;

    //create a queue ;
    queue<TreeNode*>q ;
    q.push(root) ;

    //initially the column is at  zero when it is on root;
    col[root] = 0;

        
        
while(!q.empty()){

    //declare size to run a loop level wise ;
    int size = q.size();
    //create a temporary map that will store the values in vector columnwise for this particular level
    map<int,vector<int>>temp ;
    
    
    for(int j = 0 ; j < size ; j++){

        
        TreeNode* f; 
        f = q.front();
        q.pop();
        temp[col[f]].push_back(f->val);

        
        if(f->left){
            q.push(f->left);
            int f_col = col[f];
            //column decreases if moves left ;
            col[f->left] = f_col - 1 ;
        }


        
        if(f->right){
            q.push(f->right);
            int f_col = col[f];
            //column decreases if moves left ; 
            col[f->right] = f_col + 1 ;
        } 
    }


    
       //going through every vector in temporary map
    for(auto a : temp){
            //is there are more than 1 number in a vector of particular column it needs to be sorted
            if(a.second.size() > 1) sort(a.second.begin() , a.second.end());
            //updating to the actual map
            for(auto b : a.second){
                m[a.first].push_back(b);
            }
    }
    
}

        

        //storing in ans
        for(auto a : m){
         ans.push_back(a.second);
        }
        return ans;
    }
};
