class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int subs;
        int i = 0 ;
        int j = 0 ;
        int ans = INT_MAX ;
        int sum = 0 ;
         while(i<nums.size() || j<nums.size()){
            if(i<nums.size() && sum < target){
                sum+=nums[i];
                if(sum>=target)
                ans = min(ans,i-j+1);
                i++;
                
            }
            else{
                sum = sum - nums[j];
                j++;
                if(sum>=target)
                ans = min(ans,i-j);
            }


         }
                 if(ans == INT_MAX) return 0;
         return ans;
    }
};