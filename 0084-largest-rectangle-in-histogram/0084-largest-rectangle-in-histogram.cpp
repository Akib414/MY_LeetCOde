class Solution {
public:
     vector<int>nsr(vector<int>heights){
        stack<int>st ;
        vector<int>ans(heights.size());
        st.push(-1);
        for(int i = heights.size()-1 ; i>=0 ; i--){
            int curr = heights[i];
            while(st.top() != -1 && heights[st.top()] >= curr){
                st.pop();
            }
         if(st.top() == -1) ans[i] = heights.size();
         else ans[i] = st.top();
         st.push(i);
        }
        return ans;
     }
    

    vector<int>nsl(vector<int>heights){
               stack<int>st ;
        vector<int>ans(heights.size());
        st.push(-1);
        for(int i = 0 ; i < heights.size(); i++){
            int curr = heights[i];
            while(st.top() != -1 && heights[st.top()] >= curr){
                st.pop();
            }
         ans[i] = st.top();
         st.push(i);
        }

        return ans;
     }
     
    


    int largestRectangleArea(vector<int>& heights) {
            vector<int>next = nsr(heights);
            vector<int>prev = nsl(heights);
            int ans = INT_MIN;
       for(int i = 0 ; i < heights.size() ; i++){
           int l = heights[i];
           int b = next[i] - prev[i] - 1;
           ans = max(ans,l*b);
       } 
    //   for(auto a : next) cout<<a<<endl;
    //   for(auto a : prev) cout<<a<<" ";
       return ans;
    }
};