class Solution {
public:
    bool isValid(string s) {
        stack<int>st ;
        st.push(s[0]);
      for(int i = 1 ; i < s.size() ; i++){
        if(!st.empty() && ((st.top() == '(' && s[i] == ')') || (st.top() == '{' && s[i] == '}') ||(st.top() == '[' && s[i] == ']')))
        st.pop();
        else
        st.push(s[i]);           
      }  
      if(!st.empty()) return false;
      return true ;
    }
};