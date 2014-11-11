class Solution {
public:
    vector<int> grayCode(int n) {
        int N(1 << n), tmp;
        vector<int> result;
        for(int i = 0 ; i < N; i++){
            tmp = i << 1;
            result.push_back((tmp^i) >> 1);
        }
        return result;
    }
};
