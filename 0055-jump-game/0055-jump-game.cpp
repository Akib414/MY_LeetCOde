class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1) return true;
        int j = nums.size()-1;
        int a = 0;
        for(int i = nums.size()-2 ; i >= 0 ; i--){
             if(nums[i] >= j-i){
                if(i==0) a = 1;
                j = i;
             }
        }
        if(a==1) return true;
        return false;
    }
};