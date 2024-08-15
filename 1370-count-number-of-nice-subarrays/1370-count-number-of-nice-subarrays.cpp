class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int oddcnt = 0 ;
        int cnt = 0;
        int l = 0 , r = 0 ;
        while( r < nums.size() ){
            if(nums[r]%2) oddcnt++;
            if(oddcnt == k){
                int newcnt = 1;
                while(r < nums.size()-1 && nums[r+1]%2 == 0){
                    r++;
                    newcnt++;
                }
                while(l<=r && nums[l]%2==0){
                  cnt = cnt + newcnt ;
                  l++;
                }
                if(nums[l]%2 == 1){
                    cnt = cnt+ newcnt ;
                    l++;
                    oddcnt--;
                }
            }
           r++;
        }
        return cnt ;
    }
};