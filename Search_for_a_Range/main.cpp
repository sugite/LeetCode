class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res(2,-1);
        if(n==0) return res ;
        int a = binarySearch(A,n,target);
        if(A[a]!=target) 
            return res ;
        int b = binarySearch1(A,n,target);
        res[0] = a ;
        res[1] = b;
        return res ;
    }
    
    int binarySearch(int A[] , int n , int target){
        int low = 0 ;
        int high = n - 1;
        int mid;
        while(low<high){
            mid = low + ((high-low)>>1) ;
            if(A[mid]<target)
                low = mid + 1;
            else
                high = mid ;
        }
        return low;
    }
    int binarySearch1(int A[] , int n , int target){
        int low = 0 ;
        int high = n - 1;
        int mid;
        while(low<high){
            mid = low + ((high-low)>>1) ;
            if(mid==low)
                mid = low + 1;
            if(A[mid]<=target)
                low = mid ;
            else
                high = mid-1 ;
        }
        return high;
    }
};
