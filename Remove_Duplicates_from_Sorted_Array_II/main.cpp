class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<3) return n ;
        int index = 2 ;
        for(int i = 2 ; i < n ; ++i){
            if(A[i]!=A[index-2])
                A[index++] = A[i];
        }
        return index ;
    }
};
