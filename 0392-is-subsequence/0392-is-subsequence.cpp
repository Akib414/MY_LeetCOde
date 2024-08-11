class Solution {
public:
    bool isSubsequence(string t, string s) {
        int i = 0;
        int j = s.size()-1;
        int k = 0 ;
        int l = t.size()-1;
        string ans(t.size(),'A');
        while(i<=j && k<=l){
            if(s[i] == t[k]){
                ans[k] = t[k];
                i++;
                k++;
            }
            else if(s[i] != t[k]){
                i++;
            }
           else if(s[j] == t[l]){
                ans[l] = t[l];
                j--;
                l--;
            } 
            else{
                j--;
            }
        }
        if(ans == t) return true ;
        return false;
    }
};