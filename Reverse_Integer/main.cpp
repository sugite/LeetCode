class Solution {
public:
    int reverse(int x) {
        long long out = 0;
        while(x)
        {
            out = out * 10 + x % 10;
            assert(out < INT_MAX && out > INT_MIN);
            x = x / 10;
        }
        return int(x<0? -out : out); 
    }
};
