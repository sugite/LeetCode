class Solution {
public:
    int maxProfit(vector<int> &prices) {
        return maxP(prices,0,prices.size()-1);
    }
    
    int maxP(vector<int> &prices, int low ,int high){
        if(low>=high) return 0;
        if(low==high-1&&prices[low]<=prices[high])
            return prices[high]-prices[low];
        if(low==high-1) return 0;
        int mid = low + ((high-low)>>1);
        int temp = max(maxP(prices,low,mid),maxP(prices,mid+1,high));
        int di =prices[mid], gao = prices[high];
        for(int i = low; i <mid ; i++){
            if(prices[i]<di)
                di = prices[i];
        }
        for(int i = mid+1;i<high ; i++){
            if(prices[i]>gao)
                gao = prices[i];
        }
        return max(gao-di,temp);
    }
};
