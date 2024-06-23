class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char,string>corr = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
              vector<string>ans = {""};
          for(int i = 0 ; i < digits.size() ; i++){
            string s = corr[digits[i]];
            int n = ans.size() ;
                    for(int j = 0 ; j < n ; j++){
                        for(auto a : s){
                            ans.push_back(ans[0]+a);
                        }
                        ans.erase(ans.begin());
                    }
          }
          if(digits.size() == 0) ans.erase(ans.begin());
        return ans ;
    }
};