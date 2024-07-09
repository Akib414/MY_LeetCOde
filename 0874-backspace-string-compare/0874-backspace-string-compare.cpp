class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a ="" ;
        string b = "";
        int as = s.size();
        int bs = t.size();
        for(int i = 0 ; i < as ; i++){
            if(s[i]=='#'){
                if(!a.empty())
            a.pop_back();
            }
            else
            a.push_back(s[i]);
        }
            for(int i = 0 ; i< bs ; i++){
            if(t[i]=='#'){
                 if(!b.empty())
            b.pop_back();
            }
            else
            b.push_back(t[i]);
        }
        if(a==b) return true ;
        else return false;
    }
};