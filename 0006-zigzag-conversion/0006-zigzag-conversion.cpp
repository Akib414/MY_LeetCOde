class Solution {
public:
    string convert(string s, int numrows) {
        string ans(s.size(),'a');
          int j = 0;
          for(int i = 1 ; i<=numrows ; i++){
           if(numrows==1){
                   for(int k = i-1 ; k<s.size() && j<s.size();k++)
                ans[j++] = s[k];
            }
           
            else if(i==1 || i==numrows ){
                for(int k = i-1 ; k<s.size() && j<s.size();k= k+2*(numrows-1))
                ans[j++] = s[k];
            }
            else{
             int a = 1;
             int b = i-1;
             while(b<s.size() && j<s.size()){
                if(a%2==1) {
                    ans[j++] = s[b];
                    b = b + (2*(numrows-1)-2*(i-1));
                  a++;  
                }
                else{
                    ans[j++] = s[b];
                    b = b+ (2*(numrows-1)-2*(numrows-i));
                    a++;
                }
                
             }

          } 
          }
          return ans;

    }
};