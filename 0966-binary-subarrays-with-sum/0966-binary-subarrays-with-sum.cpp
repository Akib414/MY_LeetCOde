class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int target) {
        int l = 0 ;
        int r = 0 ;
        int sum = 0 ;
        int cnt = 0;
        while(r < nums.size()){
              sum += nums[r]; 
              if(sum == target){
                   int newcnt = 1;
                   while(r < nums.size()-1 && sum+ nums[r+1] == sum){
                    newcnt++;
                    r++;
                   }
                  while(l <= r && sum == target){
                    cnt = cnt + newcnt ;
                    sum-=nums[l];
                    l++;
                    if(target == 0)
                    newcnt--;
                  }
              }
              if(sum > target){
                sum-=nums[l];
                l++;
              }
              r++;
        }
        return cnt ;
    }
};