class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k %= n;
        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);
    }
    void reverse(int nums[], int s , int e){
        while(s<e){
            int tmp = nums[s];
            nums[s] = nums[e];
            nums[e] = tmp ;
            s++;
            e--;
        }
    }
};