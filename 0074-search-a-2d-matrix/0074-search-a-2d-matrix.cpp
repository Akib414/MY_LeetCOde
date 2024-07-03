class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int target) {
        int m = v.size();
        int n = v[0].size();
        int s = 0, e = m-1;
        int ans = 0;
        while(s<=e){
            int mid = s+(e-s)/2;
           if(v[mid][0] <= target && v[mid][n-1]>= target){
            ans = mid;
            break ; 
           }
           else if(v[mid][0]>target) e = mid-1;
           else if(v[mid][n-1]<target) s= mid+1;
        }
        int lo = 0, hi = n-1;
        while(lo<=hi){
            int mid = hi+(lo-hi)/2;
            if(v[ans][mid] == target ) return true;
            else if(v[ans][mid] < target ) lo = mid+1;
            else hi = mid - 1;
        }
        return false;
    }
};