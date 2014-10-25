class Solution {
public:
    int maxSubArray(int A[], int n) {
        int maxEnd=A[0] , maxSum = A[0];
        for(int i = 1 ; i < n ; i++){
            maxEnd = max(maxEnd+A[i],A[i]);
            maxSum = max(maxEnd,maxSum);
        }
        return maxSum;
    }
};
