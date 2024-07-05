class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = nums[nums.size()-1];
        int j = nums.size()-1;
        for(int i = nums.size()-2 ; i>=0 ; i-- ){
            if(nums[i] >= j-i){
                reach = nums[i];
                j = i;
            }
            else if(i==0 &&  nums[i] < j )
            return false ;
        }
       return true;
    }
};