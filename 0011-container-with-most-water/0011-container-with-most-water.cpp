class Solution {
public:
    int maxArea(vector<int>& heights) {
        int i = 0 ;
        int j = heights.size()-1;
        int ans = -1 ;
        while(i<j){
           ans = max(ans,min(heights[i],heights[j])*(j-i));
           if(heights[i] < heights[j]) i++;
           else if(heights[i] > heights[j]) j--;
           else {
            i++;
            j--;
           }
        }
        return ans;
    }
};