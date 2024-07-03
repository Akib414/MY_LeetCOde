class Solution {
public:
    int findMin(vector<int>& v) {
        int s=0 , e = v.size();
        int ans = 0;
        while(s<=e && s<v.size()){
            int m = s+(e-s)/2;
            if(v[m]<v[0]){
               ans = m;
               e = m-1;
            }
            else{
                s = m+1 ;
            }
        }
        return v[ans];
    }
};