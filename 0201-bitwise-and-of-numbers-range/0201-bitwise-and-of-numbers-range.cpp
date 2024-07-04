class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int t = 0;
        while(left!=right){
            left = left>>1;
            right = right>>1;
            t++;
        }
        left = left<<t;
        return left;
    }
};