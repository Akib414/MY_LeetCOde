class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
            int l = 0;
            for(int i=0 ; i<nums.size();){
                 int now = nums[i];
                 int j = 0;
                 while(i<nums.size() && nums[i]==now ){
                    if(j>=2) nums[i]=99999;
                    else l++;
                    j++;
                    i++;
                 }
            }     
            sort(nums.begin(),nums.end());
            return l;                                       
    }
};