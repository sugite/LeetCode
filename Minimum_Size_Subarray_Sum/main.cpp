class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0  , sum = 0 , len = nums.size()+1;
        for(int i = 0 ; i < nums.size(); ++i){
            sum += nums[i] ;
            if(sum >= s){
                while(sum - nums[left] >= s) sum -= nums[left++];
                len = min(len, i - left + 1);
            }
        }
        return len > nums.size() ? 0 : len ;
    }
};