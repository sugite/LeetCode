class Solution {
private:
    static bool sortFunction(long long lhs, long long  rhs) {
        //比较a和b的大小,即是比较 ab和ba,比如30和9,就是309和930
        int zero1 = 1, zero2 = 1;
        while(zero1 <= lhs) zero1 *= 10;
        while(zero2 <= rhs) zero2 *= 10;
        return  (lhs * zero2 + rhs) < (rhs * zero1 + lhs);
    }
public:
    string largestNumber(vector<int> &num) {
        int n = num.size();
        sort(num.begin(), num.end());
        if(n < 1 || num.at(n-1)==0) return "0";
        int index ;
        for(int i = 0; i < n; i++){
            if(0 != num[i]) {index = i ; break;}
        }
        sort(num.begin()+index, num.end(), sortFunction);
        string ret;
        for(int i = num.size()-1 ; i >= 0; --i){
            ret += to_string(num[i]);
        }
        return ret;
    }
};