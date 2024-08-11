class Solution {
public:
    int evalRPN(vector<string>& token) {
        stack<string>st ;
        int ans = stoi(token[0]);
        for(auto a : token){
            st.push(a);
            if(a=="+" || a=="-" || a=="*" || a=="/" ){
                st.pop();
                int y = stoi(st.top());
                st.pop();
                int x = stoi(st.top());
                st.pop();
                if(a=="+") ans = x+y ;
                else if(a=="-") ans = x-y;
                else if(a=="*") ans = x*y;
                else ans = x/y ;
                st.push(to_string(ans));
            }
        }
        return ans;
    }
};