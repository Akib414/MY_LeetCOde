class Solution {
public:
    int calculate(string s) {
        stack<string> st;
        string str = "";
        for (int i = 0 ; i<s.size() ; i++) {
            if (s[i] != ' ') {
             if(s[i] == '(' || s[i] == ')' || s[i] == '+' || s[i] == '-'  ){
                if(str != "") {
                    st.push(str);
                    str = "";
                }
                str+=s[i];
                st.push(str);
                str="";
             }
             else{
                while(s[i] != '(' && s[i] != ')' && s[i] != '+' && s[i] != '-' && s[i] != ' ' && i<s.size()){
            str+=s[i];
            i++;
                }
                i--;
             }
            }
                    if(str != "") {
                    st.push(str);
                    str = "";
                }
            if (s[i] == ')') {
                int ans = 0;
                int x = 0;
                string save;
                st.pop();
                while (st.top() != "(") {
                    if (st.top() == "+") {
                        ans = ans + x;
                    } else if (st.top() == "-") {
                        ans = ans - x;
                    } else {
                        x = stoi(st.top());
                    }
                    save = st.top();
                    st.pop();
                }
                if (save != "-" && save != "+")
                    ans = ans + x;
                st.pop();
                st.push(to_string(ans));
            }
        }
        int x = 0;
        int ans = 0;
        string save;
        while (!st.empty()) {
            if (st.top() == "+") {
                ans = ans + x;
            } else if (st.top() == "-") {
                ans = ans - x;
            } else {
                x = stoi(st.top());
            }
            save = st.top();
            st.pop();
        }
        if (save != "-" && save != "+")
            ans = ans + x;
        return ans;
    }
};