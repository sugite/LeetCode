class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int low = 0 , high = n-1 ;
        while(low<high){
            int mid = low + ((high-low)>>1);
            if(A[mid]==target) return mid;
            if(A[mid]<target) low = mid + 1;
            else high = mid ;
        }
        if(A[low]>=target) return low ;
        return low + 1;
    }
};
