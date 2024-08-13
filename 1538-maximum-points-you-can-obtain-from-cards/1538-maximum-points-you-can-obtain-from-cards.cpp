class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int ans = INT_MIN;
        int sum = 0;
        int i ;
        for(i = 0 ; i<k ; i++)
        sum+=cp[i];
        ans = max(ans,sum);
        i--;
        int j = cp.size()-1;
        while(i>=0){
          sum = sum - cp[i] + cp[j];
          ans = max(ans,sum);
          i--;
          j--;
        }
        return ans;
    }
};