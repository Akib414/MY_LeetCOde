class Solution {
public:   
    // void process(int n, int k,vector<int>&output,vector<vector<int> >&ans);
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> >ans={{}};
         for(int i=1 ; i<=n ; i++){
            int s = ans.size();
            for(int j=0;j<s;j++){
                ans.push_back(ans[j]);
               ans.back().push_back(i); 
            }      
         }
         vector<vector<int> >final;
         for(int i = 0 ; i<ans.size();i++){
            if(ans[i].size() == k) final.push_back(ans[i]);
         }
        return final;
    }
};