class Solution {
public:
    void ansify(int i , int l,stringstream &ss , string str , string &ans){
        if(i==l) return ;
        ss>>str ;
        ansify(i+1,l,ss,str,ans);
        if(i != 0)
        ans = ans+str+" ";
        else
        ans = ans+str;

    }


    string reverseWords(string s) {
        string ans;
        string str;
        stringstream ss(s);
         int l = 0 ; 
 while(ss >> str){
     l++;
 }
    stringstream newss(s);
        ansify(0,l,newss,str,ans);
        return ans;
    }
};