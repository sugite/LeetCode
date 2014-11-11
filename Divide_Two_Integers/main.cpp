class Solution {
public:
    int divide(int dividend, int divisor) {
        long long end = dividend , sor = divisor;
        end = abs(end) , sor = abs(sor);
        if(end<sor) return 0;
        long long base = sor ;
        long long res = 1 ;
        int ret = 0 ;
        while(base<=end){
            if((base<<1) <= end){
                base <<= 1;
                res <<= 1;
            }else{
                ret += res ;
                res = 1 ;
                end = end - base ;
                base = sor ;
            }
        }
        if((dividend>0&&divisor>0) || (dividend<0&&divisor<0))
            return ret ;
        else
            return -ret;
    }
};
