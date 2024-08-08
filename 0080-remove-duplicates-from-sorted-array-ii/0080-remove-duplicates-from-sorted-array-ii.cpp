class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 1 ;
        int curr = nums[0];
        int ans = 1;
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] == curr){
                cnt++;
                if(cnt <= 2)
                ans++;
                else
                nums[i] = INT_MAX ;
            }
            else{
                cnt = 1 ;
                ans++;
                curr = nums[i];
            }
        }
        sort(nums.begin(),nums.end());
        return ans;
    }
};