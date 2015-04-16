class Solution {
public:
    int rob(vector<int> &num) {
        if(num.size()==0) return 0;
        int f1 = 0 , f2 = 0 , res = 0;
        for(int i = 0 ; i < num.size() ; ++i){
            int tmp = f2;
            f2 = max(f1+num[i],f2);
            f1 = tmp;
            res = max(res,f2);
        }
        return res;
    }
};