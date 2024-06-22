class Solution {
private:
    void subset(vector<vector<int> >&ans, vector<int> nums, vector<int> output, int index) {
        if (index >= nums.size()) {
            ans.push_back(output);
            return ;
        }
        subset(ans,nums,output,index+1);
        output.push_back(nums[index]);
        subset(ans,nums,output,index+1);

    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int index = 0;
        subset(ans, nums,output, index);
        return ans;
    }
};