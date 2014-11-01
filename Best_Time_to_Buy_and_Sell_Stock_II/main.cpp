class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()==0) return 0;
        int ret = 0 ; 
        for(vector<int>::iterator it = prices.begin() ; it != prices.end()-1 ; it++)
            if(*(it+1)>*it) ret += (*(it+1)-*it);
        return ret ;
    }
};
