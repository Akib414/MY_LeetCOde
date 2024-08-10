class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int cnt = 0 ;
       int product = 1;
       vector<int>ans(nums.size()) ;
       for(auto a : nums){
        if(a != 0)
        product = product * a ;
        if(a == 0) cnt++ ;
       } 
       if(cnt>=2) {
        for(int i = 0 ; i < nums.size() ; i++)
        ans[i] = 0;
       }
       else if(cnt == 1){
         for(int i = 0 ; i < nums.size() ; i++){
          if(nums[i]==0) ans[i] = product ;
          else ans[i] = 0 ;
        }
       }
       else{
            for(int i = 0 ; i < nums.size() ; i++){
          ans[i] = product/nums[i] ;
        }
       }
       return ans;
    }
};