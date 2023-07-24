class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t k = 0;
        for(int i=31;i>=0;i--){
            int bit = n&1;
            n = n>>1;
            k += bit<<(i);
        }
        return k;
    }
};