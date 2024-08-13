class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0 , r = 0 ,cnt = 0;
        int ans = INT_MIN ;
        while(r < nums.size()){
            if(nums[r]==0 && ++cnt >k){
               while(cnt > k){
                if(nums[l] == 0)
                cnt--;
                l++;  
               }
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};