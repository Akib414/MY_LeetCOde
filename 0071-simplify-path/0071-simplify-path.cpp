class Solution {
public:
    void ansify(stack<string>&st , string &ans){
        if(st.size() == 0) return ;
        string x = st.top();
        st.pop();
        ansify(st,ans);
        ans = ans + "/" + x;
    }

    



    string simplifyPath(string s) {
        stack<string>st;
    for(int i = 0 ; i < s.size() ; i++){
        if(s[i]=='/') continue;
        else{
        string temp="";
        while(s[i]!='/' && i<s.size()){
         temp+=s[i];
         i++;
        }
        i--;
        if( temp == ".."){
            if(!st.empty())
            st.pop();
        }
        else if(temp==".") continue;
        else{
            st.push(temp);
        }
        }
    }

    if(st.size() == 0) return "/";
     string ans = "";
     ansify(st,ans);
    
return ans;
    }
};