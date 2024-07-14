class Solution {
public:
    vector<int>nsr(vector<int>v , int n){
        stack<int>st;
        vector<int>ans(n);
        st.push(-1);
        for(int i = n-1 ; i>=0 ; i--){
            while(st.top() != -1 && v[st.top()] >= v[i]){
                st.pop();
            }
           
            if(st.top() == -1)  ans[i] = n;
            else ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }

        vector<int>nsl(vector<int>v , int n){
        stack<int>st;
        vector<int>ans(n);
        st.push(-1);
        for(int i = 0; i<n; i++){
            while(st.top() != -1 && v[st.top()] >= v[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
 

    int  maxarea(vector<int>v){
        int n = v.size();
        vector<int>next = nsr(v,n);
        vector<int>prev = nsl(v,n);
        int ans = INT_MIN;
        for(int i = 0 ; i < n ; i++){
           int l = v[i];
           int w = next[i] - prev[i] - 1;
           ans = max(ans,l*w);
        }
        return ans;
    }

    int maximalRectangle(vector<vector<char>>& vm) {
         int ans = -1;
         vector<int>v(vm[0].size(),0);
          for(int i = 0 ; i<vm.size() ; i++){
            for(int j = 0 ; j<vm[0].size() ; j++){
                if(vm[i][j] != '0')
                v[j] = (v[j]) + vm[i][j] - '0';
                else
                v[j] = 0;
            }
        ans = max(ans,maxarea(v));
            cout<<ans<<endl;
          }
       return ans;
    }
};