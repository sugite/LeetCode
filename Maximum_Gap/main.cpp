class Solution {
public:
    int maximumGap(vector<int> &num) {
        if(num.size()<2) return 0;
        sort(num.begin(),num.end());
        int ret = 0;
        for(int i = 0 ; i < num.size()-1 ; i++)
        {
            if(num[i+1]-num[i]>ret) ret = num[i+1]-num[i] ;
        }
        return ret ;
    }
};