class Solution {
public:
    vector<int>nsr(vector<int>& heights,int n){
        vector<int>ans(n);
        stack<pair<int,int>>st;
        st.push({-1,-1});
        for(int i = n-1 ; i>= 0 ; i--){
           while(st.top().first >= heights[i]){
            st.pop();
           }
           if(st.top().first == -1) ans[i] = n ;
           else{
            ans[i] = st.top().second;
           }
             st.push({heights[i],i});
        }
        return ans;
    }


      vector<int>nsl(vector<int>& heights,int n){
     vector<int>ans(n);
      stack<pair<int,int>>st;
     st.push({-1,-1});
     for(int i = 0 ; i <n ; i++){
        while(st.top().first >= heights[i])
        st.pop();
        ans[i] = st.top().second ;
        st.push({heights[i],i});
     }

return ans ;
      }
    



    int largestRectangleArea(vector<int>& heights) {
        vector<int>left = nsl( heights,heights.size()) ;
        vector<int>right = nsr(heights,heights.size());
     int ans = INT_MIN ;
     for(int i = 0 ; i<heights.size() ; i++){
        int l = heights[i];
        int w = right[i] - left[i] -1 ;
        ans = max(ans,l*w);
     }
    return ans ;
    }
};