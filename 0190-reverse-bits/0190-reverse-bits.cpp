class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t i = 31 ;
        uint32_t ans = 0 ;
        while(n>0){
            if(n&1){
                ans = ans+pow(2,i);
            }
            i--;
            n=n>>1;
        }
        return ans;
    }
};