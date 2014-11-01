class Solution {
public:
    bool canJump(int A[], int n) {
        if(n==1) return true;
        int curr = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(curr<=i&&A[i]==0)
                return false;
            curr = max(curr , i+A[i]);
            if(curr>=n-1)
                return true;
        }
        return false;
    }
};
