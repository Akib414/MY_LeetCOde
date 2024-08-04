class Solution {
public:
     int fr(vector<vector<int>>& matrix, int target , int m , int n){
        int s = 0 , e = m-1;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(matrix[mid][0] <= target && matrix[mid][n-1] >= target )
            return mid ;
            else if(matrix[mid][0] < target && matrix[mid][n-1] < target)
            s = mid+1;
            else if(matrix[mid][0] > target && matrix[mid][n-1] > target)
            e = mid-1;
        }
        return 0 ;
     }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int row = fr(matrix,target,m,n);
        cout<<row<<endl;
        int s = 0 , e = n-1;
        while(s <= e){
            int mid = s+(e-s)/2;
            if(matrix[row][mid] == target) return true ;
            else if(matrix[row][mid] > target) e = mid-1;
            else s = mid+1;
        }
        return false;
    }
};