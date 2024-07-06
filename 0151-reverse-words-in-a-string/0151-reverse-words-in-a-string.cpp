class Solution {
public:
      void rev(string &ns,stringstream &str ,string w , int i , int l ){
       if(i==l) return ;
       str>>w;
       rev(ns,str,w,i+1,l);
       if(i==0)
       ns+=w;
       else
       ns+=w+" ";
      }
    string reverseWords(string s) {
      stringstream ss(s);
      string word ;
      int l = 0;
     while(ss>>word){
        l++;
     }
    string ns ;
    stringstream str(s);
    int i = 0;
    string w;
    rev(ns,str,w,i,l);
    return ns;
    }
};