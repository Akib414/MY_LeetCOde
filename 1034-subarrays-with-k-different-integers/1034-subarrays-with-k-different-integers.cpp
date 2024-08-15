class Solution {
public:
     int calc(vector<int>nums, int k){
        int cnt = 0 ;
        unordered_map<int,int>m;
        for(int i = 0 , l = 0; i<nums.size() ; i++){
         if(m.find(nums[i])==m.end())
         m[nums[i]] = 1;
         else
         m[nums[i]]++;
         while(m.size()>k){
           m[nums[l]]--;
           if(m[nums[l]]==0)
           m.erase(nums[l]);
           l++;
         }
         cnt+=i-l+1;
        }
        return cnt;
     }


    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return calc(nums,k)-calc(nums,k-1);
    }
};