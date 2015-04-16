class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int i = 0 ;
        while(n!=m){
            m >>= 1;
            n >>= 1;
            ++i;
        }
        return m<<i;
    }
};