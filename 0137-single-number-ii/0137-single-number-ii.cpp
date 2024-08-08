class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        sort(nums.begin(),nums.end());
        int i = 0;
        while( i < nums.size()){
            if(nums[i]==nums[i+1] && nums[i+1] == nums[i+2]){
                i+=3 ;
            }
            else{
                return nums[i];
            }
            if(i==nums.size()-1) {
                return nums[i];
            }
        }
        return -1;
    }
};