class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>m;
        int cnt = 0 ;
        for(int i = 0 ; i < s.size() ; i++){
            m[s[i]] = i ;
            if(m.find('a') != m.end() && m.find('b') != m.end() && m.find('c') != m.end()){
             cnt = cnt + ( 1 + min(min(m['a'],m['b']),m['c']));
            }
        }
        return cnt ;
    }
};