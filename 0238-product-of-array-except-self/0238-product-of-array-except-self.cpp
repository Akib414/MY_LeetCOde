class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans;
        int count = 0;
        int product = 1;
        for(auto a : nums){
            if(a==0) count++;
            else product*=a;
        }
        for(auto a : nums){
        if(count>=2 || (count==1 && a!=0)) ans.push_back(0);
        else if(count==1 && a==0) ans.push_back(product);
        else ans.push_back(product/a);
        }
       return ans;
    }
};