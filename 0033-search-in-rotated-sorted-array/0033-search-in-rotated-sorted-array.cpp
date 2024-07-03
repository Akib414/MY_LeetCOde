class Solution {
public:
    int peak(vector<int>& nums){
        int ans = 0;
      int s = 0, e = nums.size()-1 ;
      while(s<=e){
        int m = s+(e-s)/2 ;
        if(nums[m] >= nums[0]){
            ans = m;
            s = m+1 ;
        }
        else{
            e = m-1;
        }
      }
      return ans ;
    }
    int binsearch(vector<int>&v,int s, int e , int target){
        while(s<=e){
            int m = s+(e-s)/2 ;
            if(v[m] == target) return m;
            else if(v[m]<target) s = m+1 ;
            else e = m-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int p = peak(nums);
        int ans ;
        if(target>=nums[0] && target <= nums[p])
        ans = binsearch(nums,0,p,target);
        else
        ans = binsearch(nums,p+1,nums.size()-1,target);
        return ans;
    }
};