class Solution {
public:
    set<int> loop_num = {4,16,37,58,89,145,42,20};
    bool isHappy(int n) {
        if(n<=0 || loop_num.find(n)!=loop_num.end()) return false;
        if(n==1) return true;
        int sum = 0;
        while(n){
            sum += ((n%10)*(n%10));
            n /= 10;
        }
        return isHappy(sum);
    }
};