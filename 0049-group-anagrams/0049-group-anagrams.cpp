class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string> > shei;
        vector<vector<string>>ans;
        for(auto a : strs){
            string str = a ;
            sort(a.begin(),a.end());
            shei[a].push_back(str);
        }
        for(auto a : shei){
          ans.push_back(a.second);
        }
        return ans;
    }
};