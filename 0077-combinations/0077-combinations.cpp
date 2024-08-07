class Solution {
public:
  void ansify(int c,int n, int k , vector<int>&output, vector<vector<int>>&ans){
    if(output.size() >= k){
        ans.push_back(output);
        return;
    }
    for(int i = c ; i <= n ; i++){
        output.push_back(i);
        ansify(i+1 ,n , k , output , ans );
        output.pop_back();
    }
        
  }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans ;
        vector<int>output ;
        ansify(1,n,k,output,ans);
        return ans;
    }
};