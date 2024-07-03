class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s = 0 , e = nums.size()-1;
        int ans = 0;
        while(s<=e){
            int m = s+(e-s)/2;
            if(nums[m]==target) return m;
            else if(nums[m]>target){
                ans = m ;
                e = m-1;
            }
            else{
                ans = m+1;
                s = m+1 ;
            }
        }
        return ans;

    }
};