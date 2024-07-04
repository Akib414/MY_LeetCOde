class Solution {
    void process(string* arr, int n, string digits , string &output, vector<string>&ans){
        if(n>=digits.size()){
            ans.push_back(output);
            return ;
        }
        int abcd = digits[n]-'0';
        string s = arr[abcd];
        for(int i = 0; i<s.size();i++){
            output.push_back(s[i]);
            process(arr,n+1,digits,output,ans);
             output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        string arr[10] ={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string output;
        vector<string>ans={};
        if(digits.size()==0) return ans;
        process(arr,0,digits,output,ans);
        return ans ;

    }
};