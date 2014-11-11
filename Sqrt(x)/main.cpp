class Solution {
public:
    int sqrt(int x) {
        if(x==0) return 0;
        int low = 1 , high = x , ret = 1;
        while(low <= high){
            int mid = low + ((high-low)>>1);
            if(mid<=x/mid) low=mid+1 , ret = mid;
            else high = mid - 1;
        }
        return ret;
    }
};
