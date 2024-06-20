class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int>ans;
       unordered_map<int,int>index;
       for(int i=0;i<nums.size();i++){
        index[nums[i]]=i;
       }
       for(int i=0;i<nums.size();i++){
        int other_num = target - nums[i];
        if(index.count(other_num) && index[other_num] != i)
        return {i,index[other_num]};
       }

       return {};
        
    }
};