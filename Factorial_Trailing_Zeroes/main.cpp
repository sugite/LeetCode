class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        for(long long i = 5 ; n >= i ; i *= 5 )
            res += n/i;
        return res;
    }
};