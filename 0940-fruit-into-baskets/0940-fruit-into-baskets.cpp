class Solution {
public:
    int totalFruit(vector<int>& f) {
        int l = 0 , r = 0 , k;
        int ans = INT_MIN ;
        vector<int>v;
        while( r < f.size()){
 
           if(v.size()==0)
           v.push_back(f[r]);
           if(v.size()==1 && v[0] != f[r]){
           v.push_back(f[r]);  
           }
           if(v.size() == 2){
               if(f[r] != v[0] && f[r] != v[1]){
                l=k;
                v[0] = f[l];
                v[1] = f[r];
               }            
           }
           ans = max(ans , r-l+1);
          if(r != 0 && f[r] != f[r-1]) k = r ;
         r++;

        }
        return ans;
    }
};