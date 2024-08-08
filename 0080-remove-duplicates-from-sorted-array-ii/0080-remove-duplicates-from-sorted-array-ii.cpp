class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 1 ;
        int curr = nums[0];
        int ans = 1;
        int j = 1;
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] == curr){
                cnt++;
                if(cnt <= 2){
                ans++;
                nums[j++] = nums[i];
                }
            }
            else{
                cnt = 1 ;
                ans++;
                nums[j++] = nums[i];
                curr = nums[i];
            }
        }
   
        return ans;
    }
};