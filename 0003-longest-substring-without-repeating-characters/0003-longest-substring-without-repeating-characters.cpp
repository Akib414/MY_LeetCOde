class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        unordered_map<char,int>m;
        int l = 0 , r = 0 , ans = INT_MIN;
        while(r<s.size()){
              if(m.find(s[r]) != m.end() && m[s[r]]>=l){
                l = m[s[r]]+ 1; 
              }
        ans = max(ans,r-l+1); 
        m[s[r]] = r ;
             r++;  
        }
        return ans;
        
    }
};