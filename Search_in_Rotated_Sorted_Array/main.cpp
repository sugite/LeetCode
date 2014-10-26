class Solution {
public:
    int search(int A[], int n, int target) {
        int pivot = findMin(A,n);
        if(pivot==0) return binarySearch(A,0,n-1,target);
        if(target>A[pivot-1] || target<A[pivot]) return -1 ;
        if(target>=A[0]) return binarySearch(A,0,pivot-1,target);
        return binarySearch(A,pivot,n-1,target);
    }
    
    int binarySearch(int A[],int left ,int right ,int target){
        int low = left ;
        int high = right ;
        int mid ;
        while(low<high){
            mid = low + ((high-low)>>2) ;
            if(A[mid]==target) return mid;
            else if(A[mid]>target) high = mid -1 ;
            else low = mid + 1;
        }
        return A[low]==target?low:-1;
    }
    
    int findMin(int num[] , int n) {
        if(n<2 || num[0]<num[n-1]) return 0;
        int low = 0 ; 
        int high = n-1 ;
        while(low<high-1){
            int mid = (low+high)/2;
            if(num[low]<=num[mid] && num[mid]<=num[high]){
                return low;
            }else{
                if(num[low]<num[mid])
                    low = mid ;
                else
                    high = mid ;    
            }
        }
        return num[low]>num[high]?high:low;
    }
    
};
