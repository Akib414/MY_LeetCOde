class Solution {
public:
   void ansify(string digits,string* arr , string &output , vector<string>&ans , int j) {
    if(j>=digits.size()){
       
        ans.push_back(output);
        return ;
    }
    int k = digits[j] -'0';
    string s = arr[k];
    for(int i = 0 ; i < s.size(); i++){
        output.push_back(s[i]);
        ansify(digits,arr,output , ans , j+1);
        output.pop_back();
    }
   }


    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        string arr[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans={};
        string output ;
        int j = 0;
        ansify(digits,arr,output , ans , j);
        return ans;
    }
};