class Solution {
    private:
    void comb(int index , string &digits ,map<char,string>key, string &output , vector<string>&ans){
        if(index >= digits.size()){
             ans.push_back(output);
            return ;
        }
        string now_at = key[digits[index]];
        for(auto a : now_at){
              output.push_back(a);
              comb(index+1,digits,key,output,ans);
              output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        map<char,string>key ={{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    vector<string>ans ;
    if(digits.size() == 0) return ans;
    string output;
    int index = 0;
    comb(index , digits , key, output , ans);
    return ans;
    }
};