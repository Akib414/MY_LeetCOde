class Solution {
public:
    vector<int> searchRange(vector<int>& v, int target) {
        int s = 0, e = v.size()-1;
        int f = -1;
        while(s<=e){
            int m = s+(e-s)/2;
         if(v[m]==target){
            f = m;
            e = m-1;
         }
         else if(v[m]>target) e = m-1;
         else
           s = m+1 ;
        }
        int l = -1;
        s = 0,e= v.size()-1;
           while(s<=e){
            int m = s+(e-s)/2;
         if(v[m]==target){
             l= m;
            s = m+1;
         }
         else if(v[m] < target) s=m+1;
         else
           e = m-1 ;
        }

        return {f,l};
    }
};