class Solution {
public:
   int bin(string s, int i , int j , char target){
   for(int k = j ; k <= i ; k++){
    if(s[k]==target) return k ;
   }
   return -1;

   }
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0 ;
        if(s.size()==1) return 1;
     int ans = INT_MIN;
     int i=1 , j=0 ;
      
     while(j<=i && i < s.size()){
        
        int det = bin(s,i-1,j,s[i]);
        if(det == -1){ 
            i++;
         
        } 
        else{
            j = det+1;
            i++;
        }
          ans = max(ans,i-j);    
     }
    return ans;
    }
};