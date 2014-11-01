class Solution {
public:
    int climbStairs(int n) {
        if(n<3) return n;
        int a = 1 , b = 2 , c;
        while(n-->2){
            c = a+b ;
            a = b ;
            b = c ;
        }
        return c ;
    }
};
