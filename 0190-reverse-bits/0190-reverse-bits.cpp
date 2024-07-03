class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0 ;
        for(int i = 1; i<=32 ;i++){
            result = (result) + (n&1);
            if(i != 32){
            n=n>>1;
            result = result<<1;
            }
   
        }
        return result ;
    }
};
