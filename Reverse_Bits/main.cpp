class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> b1(n) ; 
        bitset<32> b2 ; 
        for(int i = 0 ; i < 32 ; i++) { 
            if(b1.test(i)) b2.set(31-i) ; 
        } 
        return b2.to_ulong() ;
    }
};